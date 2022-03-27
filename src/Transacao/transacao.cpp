#include "transacao.hpp"
#include <ctime>



long long int Transacao::getData(){
    time_t mytime;
    time(&mytime); // segundos desde 1 de Janeiro de 1970
    return mytime;
}

double Transacao::calculaMulta(){
    if(_dataRetorno<_dataVencimento){
        return 0;
    }

    double atraso;
    double multa = 5; //Multa começa com o valor minimo de 5 reais
    atraso = ((_dataRetorno-_dataVencimento)/60.0)/24.0; // Tempo atraso em dias
    multa += atraso*2; // Valor da multa é 5 reais + 2 reais por dia de atraso
    
    return multa;
}

void Transacao::realizarEmprestimo(){
    _dataEmprestimo =  getData(); // Pega a data do sistema

    // Salva os codigos do livro e usuario
    std::cout<<"Digite o codigo do livro que será emprestado: ";
    std::cin >> _codigoLivro;
    std::cout << "Digite o codigo do usuario a quem será emprestado: ";
    std::cin >> _codigoUser;

    DataModelLivro p = _livros.getDataModelById(_codigoLivro);
    usuario u = _usuario.getDataModelById(_codigoUser);

    // Verifica se o livro está disponivel
    if(!(p.is_disponivel())){
        std::cout<< "O livro nao esta disponivel no momento.\n";
        return;
    }


    // Prazo para devolucao
    int prazo; 
    std::cout << "Qual o prazo (em dias) para a devolucao do livro? ";
    std::cin >> prazo;

    // Calcula a data de Vencimento
    _dataVencimento = _dataEmprestimo+(prazo*60*60); // Transforma o prazo em segundos e soma ao valor a data de emprestimo (em segundos)

    // Atualiza disponibilidade e informa que o emprestimo foi realizado
    p.set_disponivel(false);
    _livros.saveDataModel(p);
    set_disponivel(true);
    std::cout << "Emprestimo realizado! Do livro " << p.get_nome() << " para o usuario " << u.get_nome() << "." << std::endl;

    // Escreve informacoes na ListaTransaçao
    salvaEmprestimo();
    saveDataModel();
    
}

void Transacao::devolucaoEmprestimo(){
   _dataRetorno = getData();

   // Salva os codigos do livro e usuario
    std::cout<<"Digite o codigo do livro que sera devolvido: ";
    std::cin >> _codigoLivro;
    std::cout << "Digite o codigo do usuario que devolveu: ";
    std::cin >> _codigoUser;
    DataModelLivro p = _livros.getDataModelById(_codigoLivro);
    usuario u = _usuario.getDataModelById(_codigoUser);

    getDataModelById(_codigoLivro+_codigoUser);

    if(!(is_disponivel())){
        std::cout << "Este livro nao esta emprestado a este usuario!\n";
        return;
        //throw std::invalid_argument("Esse livro nao esta emprestado para esse usuario! ");
    }


    if(p.is_disponivel()==true){
        std::cout << "Nao e possivel devolver um livro que nao esta emprestado no momento!\n";
        return;
    }


    if(_dataRetorno>_dataVencimento){
        std::cout << "Emprestimo atrasado! Favor pagar a quantia de " << calculaMulta() << " reais. " << std::endl;
    }

    // Atualiza disponibilidade
     p.set_disponivel(true);
    _livros.saveDataModel(p);

    std::cout << "Devolucao realizada. " << std::endl;
    set_disponivel(false);
    salvaDevolucao();
    saveDataModel();
}

void Transacao::listarHistorico(){
    std::ifstream leitura("Transacao/Lista_transacao.txt");
    std::string linha;

    if(leitura.is_open()){
        while(!leitura.eof()){
            getline(leitura,linha);
            std::cout << linha << std::endl;
        }
    }
    else
        std::cerr << "ERRO: arquivo não foi aberto ou não existe\n";
    leitura.close();
}

Transacao::Transacao(){
    
}

void Transacao::salvaEmprestimo(){

    std::ofstream transacoes("Transacao/Lista_transacao.txt",ios::app);     // Abre arquivo
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    transacoes <<"Data Emprestimo " <<  tm.tm_mday <<"/" <<tm.tm_mon + 1 <<"/" << tm.tm_year + 1900 << " | ";
    transacoes <<"Codigo Livro " << _codigoLivro << " | ";
    transacoes <<"Codigo User " << _codigoUser << "\n";
    transacoes.close();
    return;
}

void Transacao::salvaDevolucao(){
    std::ofstream transacoes("Transacao/Lista_transacao.txt",ios::app);     // Abre arquivo
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    transacoes <<"Data Devolucao " << tm.tm_mday <<"/"<< tm.tm_mon + 1 << "/" << tm.tm_year + 1900 << " | ";
    transacoes <<"Codigo Livro " << _codigoLivro << " | ";
    transacoes <<"Codigo User " << _codigoUser;

    if(_dataRetorno>_dataVencimento)
        transacoes << " | Houve Atraso no Emprestimo";
    
    transacoes << "\n";
    transacoes.close();
    return;
}

std::string Transacao::to_string() {
    std::string status = is_disponivel() ? "Sim" : "Nao";
    return "RegistroLivro: " + get_codigoLivro() + "\n" +
           "RegistroUser: " + get_codigoUser() + "\n" +
           "DataEmprestimo: " + get_dataEmprestimo() + "\n" +
           "DataVencimento: " + get_dataVencimento() + "\n" +
           "Disponivel: " + status + "\n";
}

std::string Transacao::get_codigoLivro(){
    return _codigoLivro;
}

std::string Transacao::get_codigoUser(){
    return _codigoUser;
}

std::string Transacao::get_dataEmprestimo(){
    std::string dataEmprestimo = std::to_string(_dataEmprestimo);
    return dataEmprestimo;
}

std::string Transacao::get_dataVencimento(){
    std::string dataVencimento = std::to_string(_dataVencimento);
    return dataVencimento;
}

bool Transacao::is_disponivel(){
    return _disponivel;
}

void Transacao::set_atributo(std::string atributo, std::string value){
    
    if(atributo == "RegistroLivro"){
        _codigoLivro = value;
    }

    if( atributo == "RegistroUser"){
        _codigoUser = value;
    }

    if(atributo == "DataEmprestimo"){
        _dataEmprestimo = stoi(value);
    }

    if(atributo == "DataVencimento"){
        _dataVencimento = stoi(value);
    }

    if (atributo == "Disponivel"){
    
        if (value == "Sim")
        {
            set_disponivel(true);
        }
        else
        {
            set_disponivel(false);
        }
    }
}

bool Transacao::saveDataModel()
{
    //criação de arquivo
    struct stat st = {0};
    string filename("../bancoLocalDeDados/Transacao/" + get_codigoLivro() + get_codigoUser());
    const char *filename2 = filename.c_str();

    string cod("mkdir -p " + filename);
    const char *code2 = cod.c_str();

    if (stat(filename2, &st) == -1)
    {
        const int dir_err = system(code2);
        if (-1 == dir_err)
        {
            printf("Error creating directory!n");
            exit(1);
            return false;
        }
        else
        {
            cout << "Arquivo criado com sucesso" << endl;
        }
    }

    //salvando o dado

    string text("{  \n");
    //construindo o texto que sera salvo
    text = text + to_string();
    text = text + "} \n";
    string filenameFinal(filename + "/output.txt");
    fstream outfile;

    const char *filenameFinal2 = filenameFinal.c_str();
    
    this->apagarDadosDoArquivo(filenameFinal2);

    outfile.open(filenameFinal, std::ios_base::app);
    if (!outfile.is_open())
    {
        cerr << "failed to open " << filenameFinal << '\n';
        return false;
    }
    else
    {
        outfile.write(text.data(), text.size());
        cerr << "Done Writing!" << endl;
        return true;
    }
}

bool Transacao::apagarDadosDoArquivo(const char *path)
{
    FILE *arquivo;
    arquivo = fopen(path, "w");
    fclose(arquivo);
    return true;
}

bool Transacao::getDataModelById(std::string registro)
{

    //implementar busca por id do banco de dados
    FILE *arq;
    char Linha[100];
    char *result;
    int i;

    string filename("../bancoLocalDeDados/Transacao/" + registro + "/output.txt");
    const char *filename2 = filename.c_str();

    string linha;
    //ifstream – abre o arquivo apenas para leitura
    ifstream arq_in(filename2);
    if (arq_in.is_open())
    {
        //eof() - retorna true ao atingir o fim do arquivo
        while (!arq_in.eof())
        {
            getline(arq_in, linha);
            //cout << linha << endl;

            if (linha != "{" && linha != "}" && linha.find(" ") > 0 && linha.find(" ") < linha.length())
            {
                std::string value = linha.substr(linha.find(" ") + 1, linha.length() - 1);
                std::string atributo = linha.substr(0, linha.find(":"));

                set_atributo(atributo, value);
            }
        }
        
    }
    else
    {
        throw std::invalid_argument("Arquivo nao foi aberto ou nao existe!\n");
        return false;
    }
    arq_in.close();
    return true;
}

void Transacao::set_disponivel(bool d){
    _disponivel = d;
}
