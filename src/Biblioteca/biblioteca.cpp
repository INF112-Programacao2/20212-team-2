#include "biblioteca.hpp"

#include <iterator>
using namespace std;

bool biblioteca::registrar_usuario(usuario user) {
    if (usuarios.find(user.get_codigo()) == usuarios.end()) {
        usuarios.insert({user.get_codigo(), user});
        return true;
    }
    return false;
}

void biblioteca::listar_usuarios_cadastrados() {
    for (auto &usuario: usuarios) {
        cout << usuario.second.to_string() << endl;
    }
}

map<string, usuario> biblioteca::get_usuarios() {
    return this->usuarios;
}

void biblioteca::set_usuarios(map<string, usuario> usuarios) {
    this->usuarios = usuarios;
}
