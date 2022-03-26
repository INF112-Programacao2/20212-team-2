#include <iostream>
#include <map>
#include <vector>
#include "DataModel/usuario.hpp"

using namespace std;
#ifndef DAOUSUARIO
#define DAOUSUARIO

class DaoUsuario 
{
public:
    // MÉTODOS DE ACESSO
    DaoUsuario();
    map<std::string, usuario> getDataModels();
    usuario getDataModelById(std::string registro);
    // MÉTODOS DE MODIFICAÇÃO
    bool saveDataModel(usuario newLivro);
    bool deleteDataModel(usuario livroDeletado);
    bool apagarDadosDoArquivo(const char *path);
};

#endif // DAOUSUARIO