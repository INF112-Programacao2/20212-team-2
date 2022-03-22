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

void Transacao::realizarEmprestimo(std::string codigo_livro, string codigo_user){
    _dataEmprestimo =  getData(); // Pega a data do sistema
    _codigoLivro = codigo_livro;
    _codigoUser = codigo_user;
 



    int prazo; 
    std::cout << "Qual o prazo (em dias) para a devolucao do livro? ";
    std::cin >> prazo;

    _dataVencimento = _dataEmprestimo+(prazo*60*60); // Transforma o prazo em segundos e soma ao valor a data de emprestimo (em segundos)
    //l.set_disponivel(false); // Atualiza disponibilidade
    std::cout << "Emprestimo realizado! Do livro " << _codigoLivro << " para o usuario " << codigo_user << "." << std::endl;

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    transacoes <<"Data Emprestimo " <<  tm.tm_mday <<"/" <<tm.tm_mon + 1 <<"/" << tm.tm_year + 1900 << " | ";
    transacoes <<"Codigo Livro " << _codigoLivro << " | ";
    transacoes <<"Codigo User " << codigo_user << " | ";

}

void Transacao::devolucaoEmprestimo(){
   _dataRetorno = getData();
   if(_dataRetorno>_dataVencimento){
       std::cout << "Emprestimo atrasado! Favor pagar a quantia de " << calculaMulta() << " reais. " << std::endl;
   }

   //_l->set_disponivel(true);
   std::cout << "Devolucao realizada. " << std::endl;

    // Escrever no arquivo
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    transacoes <<"Data Devolucao " << tm.tm_mday <<"/"<< tm.tm_mon + 1 << "/" << tm.tm_year + 1900;

    if(_dataRetorno>_dataVencimento)
        transacoes << " | Houve Atraso no Emprestimo";
    
    transacoes << "\n";
}

void Transacao::listarHistorico(){
    std::ifstream leitura("Transacao/Lista_transacao.txt");
    std::string linha;
    if(leitura.is_open()){
        while(getline(leitura,linha)){
            std::cout << linha << std::endl;
        }
    }
    leitura.close();
}
