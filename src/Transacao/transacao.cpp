#include "transacao.hpp"
#include <ctime>

std::ofstream transacoes("Transacao/Lista_transacao.txt",ios::app);     // Abre arquivo

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

    std::cout << "Emprestimo realizado! Do livro " << p.get_nome() << " para o usuario " << u.get_nome() << "." << std::endl;

    // Escreve informacoes na ListaTransaçao
    salvaEmprestimo();
}

void Transacao::devolucaoEmprestimo(){
   _dataRetorno = getData();

   // Salva os codigos do livro e usuario
    std::cout<<"Digite o codigo do livro que sera devolvido: ";
    std::cin >> _codigoLivro;
    std::cout << "Digite o codigo do usuario que devolveu: ";
    std::cin >> _codigoUser;
    DataModelLivro p = _livros.getDataModelById(_codigoLivro);

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

    // Escrever no arquivo
    salvaDevolucao();
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
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    transacoes <<"Data Emprestimo " <<  tm.tm_mday <<"/" <<tm.tm_mon + 1 <<"/" << tm.tm_year + 1900 << " | ";
    transacoes <<"Codigo Livro " << _codigoLivro << " | ";
    transacoes <<"Codigo User " << _codigoUser << "\n";
    return;
}

void Transacao::salvaDevolucao(){

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    transacoes <<"Data Devolucao " << tm.tm_mday <<"/"<< tm.tm_mon + 1 << "/" << tm.tm_year + 1900 << " | ";
    transacoes <<"Codigo Livro " << _codigoLivro << " | ";
    transacoes <<"Codigo User " << _codigoUser;

    if(_dataRetorno>_dataVencimento)
        transacoes << " | Houve Atraso no Emprestimo";
    
    transacoes << "\n";
    return;
}

std::string Transacao::to_string() {
    return "Registro Livro: " + get_codigoLivro() + "\n" +
           "Registro User: " + get_codigoUser() + "\n" +
           "DataEmprestimo: " + get_dataEmprestimo() + "\n" +
           "DataVencimento: " + get_dataVencimento() + "\n";
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

void Transacao::set_atributo(std::string atributo, std::string value){
    
    if(atributo == "Registro Livro"){
        this->_codigoLivro = value;
    }

    if( atributo == "Registro User"){
        this->_codigoUser = value;
    }

    if(atributo == "DataEmprestimo"){
        this->_dataEmprestimo = stoi(value);
    }

    if(atributo == "DataVencimento"){
        this->_dataVencimento = stoi(value);
    }
}