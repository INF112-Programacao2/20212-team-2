#include "biblioteca.hpp"
#include "../../daos/Livro/daoLivro.cpp"
#include "../../daos/Usuarios/daoUsuario.cpp"

#include <map>
#include <vector>
#include <iterator>
using namespace std;

bool Biblioteca::registrar_usuario(Usuario user)
{
    DaoUsuario daoUsuario;

    return daoUsuario.saveDataModel(user);
}

void Biblioteca::listar_usuarios_cadastrados()
{
    for (auto &usuario : usuarios)
    {
        cout << usuario.second.to_string() << endl;
        cout << endl;
    }
}

void Biblioteca::popular_usuarios_com_banco_de_dados(){
    DaoUsuario daoUsuario;

    usuarios = daoUsuario.getDataModels();
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

map<string, Usuario> Biblioteca::get_usuarios()
{
    return this->usuarios;
}

void Biblioteca::set_usuarios(map<string, Usuario> usuarios)
{
    this->usuarios = usuarios;
}
