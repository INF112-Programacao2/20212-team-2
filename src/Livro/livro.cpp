#include "livro.hpp"

string livro::get_nome() {
    return this->nome;    
}

string livro::get_autor() {
    return this->autor;
}

string livro::get_genero() {
    return this->genero;
}

string livro::get_registro() {
    return this->registro;
}

bool livro::is_disponivel() {
    return this->disponivel;
}


void livro::set_nome(string nome) {
    this->nome = nome;
}

void livro::set_autor(string autor) {
    this->autor = autor;
}

void livro::set_genero(string genero) {
    this->genero = genero;
}

void livro::set_registro(string registro) {
    this->registro = registro;
}

void livro::set_disponivel(bool disponivel) {
    this->disponivel = disponivel;
}
