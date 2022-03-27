#include "biblioteca.hpp"
#include "../Livro/daoLivro.hpp"


#include <map>
#include <vector>
#include <iterator>
using namespace std;

bool Biblioteca::registrar_usuario(usuario user)
{
    DaoUsuario daoUsuario;

    return daoUsuario.saveDataModel(user);
}

void Biblioteca::listar_usuarios_cadastrados()
{
    popular_usuarios_com_banco_de_dados();

    for (auto &usuario : usuarios)
    {
        cout << usuario.second.to_string() << endl;
    }
}

bool Biblioteca::registrar_livro(DataModelLivro book)
{
    //DaoLivro daoLivro;

    return daoLivro.saveDataModel(book);
}

void Biblioteca::listar_livros_cadastrados()
{
    popular_livros_com_banco_de_dados();
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
    //DaoLivro livro;
    livros = daoLivro.getDataModels();
}

void Biblioteca::popular_usuarios_com_banco_de_dados(){
    DaoUsuario daoUsuario;

    usuarios = daoUsuario.getDataModels();
}


map<string, usuario> Biblioteca::get_usuarios()
{
    return this->usuarios;
}

void Biblioteca::set_usuarios(map<string, usuario> usuarios)
{
    this->usuarios = usuarios;
}

Biblioteca::Biblioteca(DaoLivro &dao){
    daoLivro = dao;
}