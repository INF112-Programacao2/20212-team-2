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

bool biblioteca::registrar_livro(livro book) {
    if (livros.find(book.get_genero()) == livros.end()) {
        vector<livro> v;
        v.push_back(book);
        livros.insert({book.get_genero(), v});
        return true;
    }

    vector<livro> &v = livros[book.get_genero()];
    for (livro l: v) {
        if (book.get_registro() == l.get_registro()) {
            return false;
        }
    }

    v.push_back(book);
    return true;
}

void biblioteca::listar_livros_cadastrados() {
    for (auto const& lista: livros) {
        cout << "Genero: " << lista.first << "\n" << endl;
        for (auto l: lista.second) {
            cout << l.to_string() << "\n" << endl;
        }
    }
}

void biblioteca::listar_livros_por_genero(string genero) {
    vector<livro> &v = livros[genero];
    for (livro l: v) {
        cout << l.to_string() << "\n" << endl;
    }
}

map<string, usuario> biblioteca::get_usuarios() {
    return this->usuarios;
}

void biblioteca::set_usuarios(map<string, usuario> usuarios) {
    this->usuarios = usuarios;
}
