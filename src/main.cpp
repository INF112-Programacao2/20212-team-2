#include "Usuarios/usuario.hpp"
#include "Biblioteca/biblioteca.hpp"
#include "Transacao/transacao.hpp"
#include <iostream>
using namespace std;

#define CHAR_MAX 200

usuario *cria_usuario();
DataModelLivro *cria_livro();

int main(){

    Biblioteca lib;
    Transacao tra;
    DaoLivro books;
    books.getDataModels();

    //DataModelLivro livro = *cria_livro();

    //lib.registrar_livro(livro);
    lib.popular_livros_com_banco_de_dados();
    //lib.listar_livros_cadastrados();
    //lib.listar_livros_por_genero(" Aventura");
    lib.listar_livros_cadastrados();

    tra.realizarEmprestimo("777", "105459");

    /*lib.registrar_usuario(*cria_usuario());
    lib.listar_usuarios_cadastrados();

    lib.registrar_livro(*cria_livro());
    lib.listar_livros_cadastrados();
    lib.listar_livros_por_genero("Aventura");*/

    return 0;
}

usuario *cria_usuario()
{
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

    u->set_nome(nome);
    u->set_celular(celular);
    u->set_codigo(codigo);
    u->set_usuario_ativo(true);

    return u;
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