#include "usuario.hpp"

string usuario::get_nome() {
    return this->nome;
}

string usuario::get_celular() {
    return this->celular;
}

string usuario::get_codigo() {
    return this->codigo;
}

bool usuario::is_usuario_ativo() {
    return this->usuario_ativo;
}

void usuario::set_nome(string nome) {
    this->nome = nome;
}

void usuario::set_celular(string celular) {
    this->celular = celular;
}

void usuario::set_codigo(string codigo) {
    this->codigo = codigo;
}

void usuario::set_usuario_ativo(bool usuario_ativo) {
    this->usuario_ativo = usuario_ativo;
}

string usuario::to_string() {
    string status = (is_usuario_ativo()) ? "Sim" : "Nao";
    return "Nome: " + get_nome() + "\n" +
           "Celular: " + get_celular() + "\n" +
           "Codigo: " + get_codigo() + "\n" +
           "Usuario ativo? " + status;
}