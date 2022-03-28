#include <iostream>

#ifndef USUARIO_HEADER
#define USUARIO_HEADER

class usuario {
    protected:
        // ATRIBUTOS
        std::string nome;
        std::string celular;
        std::string codigoUser;
        bool usuario_ativo;
    
    public:

        // MÉTODOS DE ACESSO
        std::string get_nome();
        std::string get_celular();
        std::string get_codigo();
        bool is_usuario_ativo();
        void set_atributo(std::string atributo, std::string value);

        // MÉTODOS DE MODIFICAÇÃO
        void set_nome(std::string);
        void set_celular(std::string);
        void set_codigo(std::string);
        void set_usuario_ativo(bool);     

        // TO_STRING
        std::string to_string();

        //  
        virtual double desconto_multa(double &multa );
};

#endif // USUARIO_HEADER