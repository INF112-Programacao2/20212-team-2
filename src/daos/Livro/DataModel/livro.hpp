#include <iostream>
#include "../../../framework/dataModelBase.hpp"
#ifndef DATAMODELLIVRO_HEADER
#define DATAMODELLIVRO_HEADER

class DataModelLivro : DataModelBase
{
private:
    // ATRIBUTOS
    std::string nome;
    std::string autor;
    std::string genero;
    std::string registro;
    bool disponivel;

public:
    DataModelLivro(std::string nome, std::string autor, std::string genero, std::string registro, bool disponivel);
    // MÉTODOS DE ACESSO
    std::string
    get_nome();
    std::string get_autor();
    std::string get_genero();
    std::string get_registro();
    bool is_disponivel();

    // MÉTODOS DE MODIFICAÇÃO
    void set_nome(std::string);
    void set_autor(std::string);
    void set_genero(std::string);
    void set_registro(std::string);
    void set_disponivel(bool);
    void set_atributo(std::string atributo, std::string value);

    // TO_STRING
    std::string to_string();
};

#endif // DATAMODELLIVRO_HEADER