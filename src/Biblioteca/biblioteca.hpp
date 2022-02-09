#include "../Usuarios/usuario.hpp"

#include <iostream>
#include <map>
using namespace std;

#ifndef BIBLIOTECA_HEADER
#define BIBLIOTECA_HEADER

class biblioteca {
    private:
        // ATRIBUTOS
        map<string, usuario> usuarios;
    public:

        // MÉTODOS ESPECÍFICOS
        bool registrar_usuario(usuario);
        void listar_usuarios_cadastrados();

        // MÉTODOS DE ACESSO
        map<string, usuario> get_usuarios();
        void set_usuarios(map<string, usuario>);
        // MÉTODOS DE MODIFICAÇÃO
};

#endif // BIBLIOTECA_HEADER