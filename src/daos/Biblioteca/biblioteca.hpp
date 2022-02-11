#include "../Usuarios/usuario.hpp"
#include "../Livro/livro.hpp"

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
    map<string, Usuario> usuarios;
    map<string, vector<Livro>> livros;

public:
    // MÉTODOS ESPECÍFICOS
    bool registrar_usuario(Usuario);
    void listar_usuarios_cadastrados();

    bool registrar_livro(Livro);
    void listar_livros_cadastrados();
    void listar_livros_por_genero(string);

    // MÉTODOS DE ACESSO
    map<string, Usuario> get_usuarios();
    void set_usuarios(map<string, Usuario>);
    // MÉTODOS DE MODIFICAÇÃO
};

#endif // BIBLIOTECA_HEADER