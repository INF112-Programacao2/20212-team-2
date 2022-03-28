#include "biblioteca.hpp"
#include "../Livro/daoLivro.hpp"


#include <map>
#include <vector>
#include <iterator>


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
        std::cout << usuario.second.to_string() << std::endl;
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
    std::cout << std::endl;
    for (auto const &lista : livros)
    {
        std::cout << "Genero: " << lista.first << "\n"
             << std::endl;
        for (auto l : lista.second)
        {
            std::cout << l.to_string() << "\n"
                 << std::endl;
        }
    }
}

void Biblioteca::listar_livros_por_genero(std::string genero)
{

    std::vector<DataModelLivro> &v = livros[genero];
    for (DataModelLivro l : v)
    {
        std::cout << l.to_string() << "\n"
             << std::endl;
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


std::map<std::string, usuario> Biblioteca::get_usuarios()
{
    return this->usuarios;
}

void Biblioteca::set_usuarios(std::map<std::string, usuario> usuarios)
{
    this->usuarios = usuarios;
}

Biblioteca::Biblioteca(DaoLivro &dao){
    daoLivro = dao;
}