#include <iostream>
using namespace std;

#ifndef LIVRO_HEADER
#define LIVRO_HEADER

class livro {
    private:
        // ATRIBUTOS
        string nome;
        string autor;
        string genero;
        string registro;
        bool disponivel;
    public:
        // MÉTODOS DE ACESSO
        string get_nome();
        string get_autor();
        string get_genero();
        string get_registro();
        bool is_disponivel();

        // MÉTODOS DE MODIFICAÇÃO
        void set_nome(string);
        void set_autor(string);
        void set_genero(string);
        void set_registro(string);
        void set_disponivel(bool);

        // TO_STRING
        string to_string();
};

#endif // LIVRO_HEADER