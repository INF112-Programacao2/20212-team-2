#include <iostream>
#include "../Usuarios/usuario.hpp"
using namespace std;

#ifndef USUARIOVIP_HEADER
#define USUARIOVIP_HEADER

class usuarioVip : public Usuario
{
private:
    // ATRIBUTOS
    string nome;
    string celular;
    string codigo;
    bool usuario_ativo;

public:
    // MÉTODOS DE ACESSO
    string get_nome();
    string get_celular();
    string get_codigo();
    bool is_usuario_ativo();

    // MÉTODOS DE MODIFICAÇÃO
    void set_nome(string);
    void set_celular(string);
    void set_codigo(string);
    void set_usuario_ativo(bool);

    // TO_STRING
    string to_string();
};

#endif // USUARIOVIP_HEADER