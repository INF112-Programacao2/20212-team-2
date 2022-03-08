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

void Transacao::realizarEmprestimo(usuario &u, livro &l){
    _dataEmprestimo =  getData(); // Pega a data do sistema

    _l = &l;    //Guarda informacoes do livro e usuarios do emprestimo
    _u = &u;

    int prazo; 
    std::cout << "Qual o prazo (em dias) para a devolucao do livro? ";
    std::cin >> prazo;

    _dataVencimento = _dataEmprestimo+(prazo*60*60); // Transforma o prazo em segundos e soma ao valor a data de emprestimo (em segundos)
    l.set_disponivel(false); // Atualiza disponibilidade

    std::cout << "Emprestimo realizado! Do livro " << l.get_nome() << " para o usuario " << u.get_nome() << "." << std::endl;

}

void Transacao::devolucaoEmprestimo(){
   _dataRetorno = getData();
   if(_dataRetorno>_dataVencimento){
       std::cout << "Emprestimo atrasado! Favor pagar a quantia de " << calculaMulta() << " reais. " << std::endl;
   }
   _l->set_disponivel(true);
   std::cout << "Devolucao realizada. " << std::endl;
}

void Transacao::setCodigoTransacao(string codigo){
    _codigoTransacao = codigo;
}

string Transacao::getCodigo(){
    return _codigoTransacao;
}