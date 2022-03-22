#include "../Usuarios/usuario.hpp"
#include"../Livro/DataModel/livro.hpp"
#include "../Livro/daoLivro.hpp"


#include <iostream>
#include <map>
#include <vector>
using namespace std;

#ifndef BIBLIOTECA_HEADER
#define BIBLIOTECA_HEADER

class Biblioteca
{
private:
    // ATRIBUTOS
    map<string, usuario> usuarios;
    map<string, vector<DataModelLivro>> livros;

public:
    // MÉTODOS ESPECÍFICOS
    bool registrar_usuario(usuario);
    void listar_usuarios_cadastrados();

    bool registrar_livro(DataModelLivro);
    void listar_livros_cadastrados();
    void listar_livros_por_genero(string);
    void popular_livros_com_banco_de_dados();

    // MÉTODOS DE ACESSO
    map<string, usuario> get_usuarios();
    void set_usuarios(map<string, usuario>);
    // MÉTODOS DE MODIFICAÇÃO
};

#endif // BIBLIOTECA_HEADER