#include "./Usuarios/DataModel/usuario.hpp"
#include "Biblioteca/biblioteca.hpp"
#include "Transacao/transacao.hpp"
#include <iostream>
using namespace std;

#define CHAR_MAX 200

usuario *cria_usuario();
DataModelLivro *cria_livro();

DaoLivro books;
DaoUsuario users;

Biblioteca lib(books);
Transacao tra(books);

int main(){

    //lib.popular_livros_com_banco_de_dados();
    //lib.listar_livros_cadastrados();
    
   
    lib.popular_usuarios_com_banco_de_dados();
    lib.popular_livros_com_banco_de_dados();
    lib.listar_livros_cadastrados();

    tra.realizarEmprestimo();
    lib.listar_livros_cadastrados();
    
    //lib.popular_livros_com_banco_de_dados();
    //lib.listar_livros_cadastrados();

    //tra.realizarEmprestimo();
    //lib.popular_livros_com_banco_de_dados();
    //lib.listar_livros_cadastrados();
    //tra.devolucaoEmprestimo();
    //tra.listarHistorico();

    return 0;
}

usuario *cria_usuario() 
{
    char resposta;
    std::cout << "Deseja cadastrar Usuario Premium?[S/N]" << std::endl; 
    std::cin >> resposta;\
    cin.ignore();
    UsuarioVip *v = new UsuarioVip;
    usuario *u = new usuario;
    

    char nome[CHAR_MAX];
    char celular[CHAR_MAX];
    char codigo[CHAR_MAX];

    cout << "Insira o nome do usuario: ";
    cin.getline(nome, CHAR_MAX);

    cout << "Insira o celular do usuario: ";
    cin.getline(celular, CHAR_MAX);

    cout << "Insira o codigo do usuario (numero de matricula): ";
    cin.getline(codigo, CHAR_MAX);


    if (resposta == 'S' || resposta == 's')
    {
        v->set_nome(nome);
        v->set_celular(celular);
        v->set_codigo(codigo);
        v->set_usuario_ativo(true);
        return v;
    }
    else {
        u->set_nome(nome);
        u->set_celular(celular);
        u->set_codigo(codigo);
        u->set_usuario_ativo(true);
        return u;
    }
    

    
}

DataModelLivro *cria_livro()
{
    DataModelLivro *l = new DataModelLivro("teste", "autor", "genero", "registro", true);
    

    char nome[CHAR_MAX];
    char autor[CHAR_MAX];
    char genero[CHAR_MAX];
    char registro[CHAR_MAX];

    cout << "Insira o nome do livro: ";
    cin.getline(nome, CHAR_MAX);

    cout << "Insira o(s) autor(es) do livro: ";
    cin.getline(autor, CHAR_MAX);

    cout << "Insira o genero do livro: ";
    cin.getline(genero, CHAR_MAX);

    cout << "Insira o registro do livro: ";
    cin.getline(registro, CHAR_MAX);

    l->set_nome(nome);
    l->set_autor(autor);
    l->set_genero(genero);
    l->set_registro(registro);
    l->set_disponivel(true);

    return l;
}