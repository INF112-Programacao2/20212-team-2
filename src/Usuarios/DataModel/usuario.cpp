#include "usuario.hpp"

std::string usuario::get_nome() {
    return this->nome;
}

std::string usuario::get_celular() {
    return this->celular;
}

std::string usuario::get_codigo() {
    return this->codigoUser;
}

bool usuario::is_usuario_ativo() {
    return this->usuario_ativo;
}

void usuario::set_nome(std::string nome) {
    this->nome = nome;
}

void usuario::set_celular(std::string celular) {
    this->celular = celular;
}

void usuario::set_codigo(std::string codigo) {
    this->codigoUser = codigo;
}

void usuario::set_usuario_ativo(bool usuario_ativo) {
    this->usuario_ativo = usuario_ativo;
}

std::string usuario::to_string() {
    std::string status = (is_usuario_ativo()) ? "Sim" : "Nao";
    return "Nome: " + get_nome() + "\n" +
           "Celular: " + get_celular() + "\n" +
           "Codigo: " + get_codigo() + "\n" +
           "Usuario ativo? " + status + "\n";
}

void usuario::set_atributo(std::string atributo, std::string value){
    
    if(atributo == "Nome"){
        this->nome = value;
    }

    if( atributo == "Celular"){
        this->celular = value;
    }

    if(atributo == "Codigo"){
        this->codigoUser = value;
    }

    if(atributo == "Usuario ativo"){
        if(value == "Sim"){
            this->usuario_ativo = true;
        }else{
            this->usuario_ativo = false;
        }
    }
}
double usuario::desconto_multa(double &multa ){
    return multa*1;
}