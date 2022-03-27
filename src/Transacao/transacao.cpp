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

    std::cout << p.to_string() <<std::endl;
    _livros.saveDataModel(p);
    std::cout << "Emprestimo realizado! Do livro " << p.get_nome() << " para o usuario " << _codigoUser << "." << std::endl;


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

   if(_dataRetorno>_dataVencimento){
       std::cout << "Emprestimo atrasado! Favor pagar a quantia de " << calculaMulta() << " reais. " << std::endl;
   }

    // Atualiza disponibilidade
    //_livros.modificarDisponibilidadeById(_codigoLivro);

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

Transacao::Transacao(DaoLivro &livros){
    _livros = livros;
}

void Transacao::salvaEmprestimo(){
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    transacoes <<"Data Emprestimo " <<  tm.tm_mday <<"/" <<tm.tm_mon + 1 <<"/" << tm.tm_year + 1900 << " | ";
    transacoes <<"Codigo Livro " << _codigoLivro << " | ";
    transacoes <<"Codigo User " << _codigoUser << " | ";
    return;
}

void Transacao::salvaDevolucao(){

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    transacoes <<"Data Devolucao " << tm.tm_mday <<"/"<< tm.tm_mon + 1 << "/" << tm.tm_year + 1900;

    if(_dataRetorno>_dataVencimento)
        transacoes << " | Houve Atraso no Emprestimo";
    
    transacoes << "\n";
    return;
}