#include "biblioteca.hpp"
#include "../Livro/daoLivro.cpp"


#include <map>
#include <vector>
#include <iterator>
using namespace std;

bool Biblioteca::registrar_usuario(usuario user)
{
    if (usuarios.find(user.get_codigo()) == usuarios.end())
    {
        usuarios.insert({user.get_codigo(), user});
        return true;
    }
    return false;
}

void Biblioteca::listar_usuarios_cadastrados()
{
    for (auto &usuario : usuarios)
    {
        cout << usuario.second.to_string() << endl;
    }
}

bool Biblioteca::registrar_livro(DataModelLivro book)
{
    DaoLivro daoLivro;

    return daoLivro.saveDataModel(book);
}

void Biblioteca::listar_livros_cadastrados()
{

    cout << endl;
    for (auto const &lista : livros)
    {
        cout << "Genero: " << lista.first << "\n"
             << endl;
        for (auto l : lista.second)
        {
            cout << l.to_string() << "\n"
                 << endl;
        }
    }
}

void Biblioteca::listar_livros_por_genero(string genero)
{

    vector<DataModelLivro> &v = livros[genero];
    for (DataModelLivro l : v)
    {
        cout << l.to_string() << "\n"
             << endl;
    }
}

void Biblioteca::popular_livros_com_banco_de_dados()
{
    DaoLivro livro;
    livros = livro.getDataModels();
}

map<string, usuario> Biblioteca::get_usuarios()
{
    return this->usuarios;
}

void Biblioteca::set_usuarios(map<string, usuario> usuarios)
{
    this->usuarios = usuarios;
}