#include <iostream>
#include "livro.hpp"

DataModelLivro::DataModelLivro(string nome, std::string autor, std::string genero, std::string registro, bool disponivel)
{
    nome = nome;
    autor = autor;
    genero = genero;
    registro = registro;
    disponivel = disponivel;
}

std::string DataModelLivro::get_nome()
{
    return this->nome;
}

std::string DataModelLivro::get_autor()
{
    return this->autor;
}

std::string DataModelLivro::get_genero()
{
    return this->genero;
}

std::string DataModelLivro::get_registro()
{
    return this->registro;
}

bool DataModelLivro::is_disponivel()
{
    return this->disponivel;
}

void DataModelLivro::set_nome(std::string nome)
{
    this->nome = nome;
}

void DataModelLivro::set_autor(std::string autor)
{
    this->autor = autor;
}

void DataModelLivro::set_genero(std::string genero)
{
    this->genero = genero;
}

void DataModelLivro::set_registro(std::string registro)
{
    this->registro = registro;
}

void DataModelLivro::set_disponivel(bool disponivel)
{
    this->disponivel = disponivel;
}

std::string DataModelLivro::to_string()
{
    std::string status = is_disponivel() ? "Sim" : "Nao";
    return "Nome: " + get_nome() + "\n" +
           "Autor: " + get_autor() + "\n" +
           "Genero: " + get_genero() + "\n" +
           "Registro: " + get_registro() + "\n" +
           "Esta disponivel? " + status;
}