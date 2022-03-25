#include "../Usuarios/usuario.hpp"
#include "../Livro/DataModel/livro.hpp"
#include "../UsuarioVip/usuariovip.hpp"
#include "../Livro/daoLivro.hpp"

#include <iostream>
#include <string>
#include <fstream>

#ifndef TRANSACOES_HPP
#define TRANSACOES_HPP

class Transacao {
    private:
        // ATRIBUTOS
        long long int _dataEmprestimo; // Data momento do emprestimo
        long long int _dataRetorno; // Data retorno do emprestimo
        long long int _dataVencimento; // Prazo maximo para retorno do emprestimo sem multa
        DaoLivro _livros;

        std::string _codigoLivro;
        std::string _codigoUser;
        
        // METODOS PRIVADOS
        long long int getData();
        void salvaEmprestimo(); // Escreve informacoes emprestimo no .txt
        void salvaDevolucao(); // Escreve informacoes da devolucao do emprestimo no .txt
        

    public:
        // METODOS
        void realizarEmprestimo();
        void listarHistorico();
        void devolucaoEmprestimo();
        double calculaMulta();

        void setCodigoTransacao(std::string);
        std::string getCodigo();
        Transacao(DaoLivro &livros);   
};

#endif //TRANSACOES_HPP