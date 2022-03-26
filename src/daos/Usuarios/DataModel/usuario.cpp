#include "usuario.hpp"

string Usuario::get_nome()
{
    return this->nome;
}

string Usuario::get_celular()
{
    return this->celular;
}

string Usuario::get_codigo()
{
    return this->codigo;
}

bool Usuario::is_usuario_ativo()
{
    return this->usuario_ativo;
}

void Usuario::set_atributo(std::string atributo, std::string value){
    
    if(atributo == "Nome"){
        this->nome = value;
    }

    if( atributo == "Celular"){
        this->celular = value;
    }

    if(atributo == "Codigo"){
        this->codigo = value;
    }

    if(atributo == "Usuario ativo"){
        if(value == "Sim"){
            this->usuario_ativo = true;
        }else{
            this->usuario_ativo = false;
        }
    }
}

void Usuario::set_nome(string nome)
{
    this->nome = nome;
}

void Usuario::set_celular(string celular)
{
    this->celular = celular;
}

void Usuario::set_codigo(string codigo)
{
    this->codigo = codigo;
}

void Usuario::set_usuario_ativo(bool usuario_ativo)
{
    this->usuario_ativo = usuario_ativo;
}

string Usuario::to_string()
{
    string status = (is_usuario_ativo()) ? "Sim" : "Nao";
    return "Nome: " + get_nome() + "\n" +
           "Celular: " + get_celular() + "\n" +
           "Codigo: " + get_codigo() + "\n" +
           "Usuario ativo? " + status;
}