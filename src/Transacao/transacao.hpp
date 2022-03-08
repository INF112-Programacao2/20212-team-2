#include "../Usuarios/usuario.hpp"
#include "../Livro/livro.hpp"
#include "../Usuarios/usuariovip.hpp"

#include <iostream>
#include <string>

#ifndef TRANSACOES_HPP
#define TRANSACOES_HPP

class Transacao {
    private:
        // ATRIBUTOS
        long long int _dataEmprestimo; // Data momento do emprestimo
        long long int _dataRetorno; // Data retorno do emprestimo
        long long int _dataVencimento; // Prazo maximo para retorno do emprestimo sem multa
        string _codigoTransacao;
        livro *_l;
        usuario *_u;

        // METODOS PRIVADOS
        long long int getData();
        

    public:
        // METODOS
        void realizarEmprestimo(usuario&, livro&);
        void listarHistorico();
        void devolucaoEmprestimo();
        double calculaMulta();

        void setCodigoTransacao(string);
        string getCodigo();

        
};

#endif //TRANSACOES_HPP