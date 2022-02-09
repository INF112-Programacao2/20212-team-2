#include "Usuarios/usuario.hpp"
#include "Biblioteca/biblioteca.hpp"

#include <iostream>
using namespace std;

#define CHAR_MAX 200

usuario *cria_usuario();

int main() {

    biblioteca lib;
    
    lib.registrar_usuario(*cria_usuario());
    lib.listar_usuarios_cadastrados();

    return 0;

}

usuario *cria_usuario() {
    usuario *u = new usuario;

    char nome[CHAR_MAX];
    char celular[CHAR_MAX];
    char codigo[CHAR_MAX];

    cout << "Insira o nome do usuario: ";
    cin.getline(nome, CHAR_MAX);
    

    cout << "Insira o celular do usuario: ";
    cin.getline(celular, CHAR_MAX);

    cout << "Insira o codigo do usuario (numero de matricula): ";
    cin.getline(codigo, CHAR_MAX);

    u->set_nome(nome);
    u->set_celular(celular);
    u->set_codigo(codigo);
    u->set_usuario_ativo(true);

    return u;
}