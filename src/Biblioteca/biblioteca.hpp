#include "../Usuarios/usuario.hpp"
#include "../Livro/livro.hpp"

#include <iostream>
#include <map>
#include <vector>
using namespace std;

#ifndef BIBLIOTECA_HEADER
#define BIBLIOTECA_HEADER

class biblioteca {
    private:
        // ATRIBUTOS
        map<string, usuario> usuarios;
        map<string, vector<livro>> livros;
    public:

        // MÉTODOS ESPECÍFICOS
        bool registrar_usuario(usuario);
        void listar_usuarios_cadastrados();

        bool registrar_livro(livro);
        void listar_livros_cadastrados();
        void listar_livros_por_genero(string);

        // MÉTODOS DE ACESSO
        map<string, usuario> get_usuarios();
        void set_usuarios(map<string, usuario>);
        // MÉTODOS DE MODIFICAÇÃO
};

#endif // BIBLIOTECA_HEADER