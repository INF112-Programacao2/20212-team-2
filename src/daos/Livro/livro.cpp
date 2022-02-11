#include "livro.hpp"

string Livro::get_nome()
{
    return this->nome;
}

string Livro::get_autor()
{
    return this->autor;
}

string Livro::get_genero()
{
    return this->genero;
}

string Livro::get_registro()
{
    return this->registro;
}

bool Livro::is_disponivel()
{
    return this->disponivel;
}

void Livro::set_nome(string nome)
{
    this->nome = nome;
}

void Livro::set_autor(string autor)
{
    this->autor = autor;
}

void Livro::set_genero(string genero)
{
    this->genero = genero;
}

void Livro::set_registro(string registro)
{
    this->registro = registro;
}

void Livro::set_disponivel(bool disponivel)
{
    this->disponivel = disponivel;
}

string Livro::to_string()
{
    string status = is_disponivel() ? "Sim" : "Nao";
    return "Nome: " + get_nome() + "\n" +
           "Autor: " + get_autor() + "\n" +
           "Genero: " + get_genero() + "\n" +
           "Registro: " + get_registro() + "\n" +
           "Esta disponivel? " + status;
}