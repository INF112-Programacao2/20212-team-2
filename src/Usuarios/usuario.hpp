#include <iostream>
using namespace std;

#ifndef USUARIO_HEADER
#define USUARIO_HEADER

class usuario {
    protected:
        // ATRIBUTOS
        string nome;
        string celular;
        string codigo;
        bool usuario_ativo;  
    
    public:

        // MÉTODOS DE ACESSO
        string get_nome();
        string get_celular();
        string get_codigo();
        bool is_usuario_ativo();

        // MÉTODOS DE MODIFICAÇÃO
        void set_nome(string);
        void set_celular(string);
        void set_codigo(string);
        void set_usuario_ativo(bool);     

        // TO_STRING
        string to_string();
};

#endif // USUARIO_HEADER