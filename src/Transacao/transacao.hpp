#include "../Usuarios/DataModel/usuario.hpp"
#include "../Livro/DataModel/livro.hpp"
#include "../UsuarioVip/usuariovip.hpp"
#include "../Livro/daoLivro.hpp"
#include "../Usuarios/daoUsuario.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdexcept>
#include <cstdlib>
#include <fstream>

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

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
        bool _disponivel;
        DaoLivro _livros;
        DaoUsuario _usuario;

        std::string _codigoLivro;
        std::string _codigoUser;
        
        // METODOS PRIVADOS
        long long int getData();
        void salvaEmprestimo(); // Escreve informacoes emprestimo no .txt
        void salvaDevolucao(); // Escreve informacoes da devolucao do emprestimo no .txt
        bool saveDataModel();
        bool apagarDadosDoArquivo(const char *path);
        bool getDataModelById(std::string registro);
        

    public:
        // METODOS
        void realizarEmprestimo();
        bool is_disponivel();
        void set_disponivel(bool);
        void listarHistorico();
        void devolucaoEmprestimo();
        void set_atributo(std::string atributo, std::string value);
        double calculaMulta();

        std::string get_dataEmprestimo();
        std::string get_dataVencimento();
        std::string get_codigoLivro();
        std::string get_codigoUser();


        void setCodigoTransacao(std::string);
        std::string getCodigo();
        std::string to_string();
        Transacao();   
};

#endif //TRANSACOES_HPP