#include "../Usuarios/DataModel/usuario.hpp"
#include"../Livro/DataModel/livro.hpp"
#include "../Livro/daoLivro.hpp"
#include "../Usuarios/daoUsuario.hpp"


#include <iostream>
#include <map>
#include <vector>


#ifndef BIBLIOTECA_HEADER
#define BIBLIOTECA_HEADER

class Biblioteca
{
private:
    // ATRIBUTOS
    std::map<std::string, usuario> usuarios;
    std::map<std::string, std::vector<DataModelLivro>> livros;
    DaoLivro daoLivro;

public:
    // MÉTODOS ESPECÍFICOS
    bool registrar_usuario(usuario);
    void listar_usuarios_cadastrados();

    bool registrar_livro(DataModelLivro);
    void listar_livros_cadastrados();
    void listar_livros_por_genero(std::string);
    void popular_livros_com_banco_de_dados();
    void popular_usuarios_com_banco_de_dados();

    // MÉTODOS DE ACESSO
    std::map<std::string, usuario> get_usuarios();
    void set_usuarios(std::map<std::string, usuario>);
    // CONSTRUTOR
    Biblioteca(DaoLivro&);
};

#endif // BIBLIOTECA_HEADER