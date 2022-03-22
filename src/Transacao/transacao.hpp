#include "../Usuarios/usuario.hpp"
#include "../Livro/DataModel/livro.hpp"
#include "../Usuarios/usuariovip.hpp"

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

        std::string _codigoLivro;
        std::string _codigoUser;
        
        // METODOS PRIVADOS
        long long int getData();
        

    public:
        // METODOS
        void realizarEmprestimo(std::string codigo_livro, std::string codigo_user);
        void listarHistorico();
        void devolucaoEmprestimo();
        double calculaMulta();

        void setCodigoTransacao(std::string);
        std::string getCodigo();
        

        
};

#endif //TRANSACOES_HPP