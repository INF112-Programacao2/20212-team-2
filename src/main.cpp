#include "./Usuarios/DataModel/usuario.hpp"
#include "Biblioteca/biblioteca.hpp"
#include "Transacao/transacao.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

#define CHAR_MAX 200

usuario *cria_usuario();
DataModelLivro *cria_livro();
void interface();

DaoLivro books;
DaoUsuario users;

Biblioteca lib(books);
Transacao tra;

int main(){

    try{
        interface();
    } catch (std::invalid_argument &e){
        std::cerr << e.what() << std::endl;
    } catch (std::exception &e2){
        std::cerr << e2.what()<< std::endl;
    }

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

void interface(){
    int entrada=0; // Entrada de dados pelo usuario

    std::cout << "*** Bem vindo ao sistema Bibliotecario da UFV ***\n";
    std::cout << std::endl;
    std::cout << "Como podemos te ajudar hoje?\n";

    while(true){
        std::cout<<std::endl;
        std::cout << "Digite 1 para listar todos os livros disponiveis\n";
        std::cout << "Digite 2 para listar todos os usuarios disponiveis\n";
        std::cout << "Digite 3 para realizar um emprestimo\n";
        std::cout << "Digite 4 para devolver um emprestimo\n";
        std::cout << "Digite 5 para listar os livros disponiveis de um genero especifico\n";
        std::cout << "Digite 6 para listar todas as transacoes de livros realizadas\n";
        std::cout << "Digite 7 para cadastrar um novo livro\n";
        std::cout << "Digite 8 para cadastrar um novo usuario\n";
        std::cout << "Digite um valor negativo para sair do sistema\n";

        std::cin>> entrada;

        if(entrada==1){
            lib.listar_livros_cadastrados();
        }
        if(entrada==2){
            lib.listar_usuarios_cadastrados();
        }
        if(entrada==3){
            tra.realizarEmprestimo();
        }
        if(entrada==4){
            tra.devolucaoEmprestimo();
        }
        if(entrada==5){
            std::string genero;
            std::cout << "Qual o genero do livro que deseja listar?";
            std::cin >> genero;
            lib.listar_livros_por_genero(genero);
        }
        if(entrada==6){
            tra.listarHistorico();
        }
        if(entrada==7){
            cin.ignore();
            lib.registrar_livro(*cria_livro());
        }
        if(entrada==8){
            cin.ignore();
            lib.registrar_usuario(*cria_usuario());
        }
        if(entrada<0){
            std::cout << "Obrigado por utilizar nosso sistema!\n";
            break;
        }
    }

    std::cout << std::endl;
    std::cout << "Feito por:\n";
    std::cout << "Caio Gomes Braga (@caiobraga)\n";
    std::cout << "Gabriel Moraes Ribeiro (@GabrielMoraesRibeiro)\n";
    std::cout << "Henrique Andrade Lopes (@H3nriqu3L)\n";
    std::cout << "Lucas Mombach (@Lucas-Mombach)\n";

}