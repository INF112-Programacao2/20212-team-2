#include "biblioteca.hpp"
#include <map>
#include <vector>
#include <iterator>
using namespace std;

bool Biblioteca::registrar_usuario(Usuario user)
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
    if (livros.find(book.get_genero()) == livros.end())
    {
        vector<DataModelLivro> v;
        v.push_back(book);
        livros.insert({book.get_genero(), v});
        return true;
    }

    vector<DataModelLivro> &v = livros[book.get_genero()];
    for (DataModelLivro l : v)
    {
        if (book.get_registro() == l.get_registro())
        {
            return false;
        }
    }

    v.push_back(book);
    return true;
}

void Biblioteca::listar_livros_cadastrados()
{
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

map<string, Usuario> Biblioteca::get_usuarios()
{
    return this->usuarios;
}

void Biblioteca::set_usuarios(map<string, Usuario> usuarios)
{
    this->usuarios = usuarios;
}
