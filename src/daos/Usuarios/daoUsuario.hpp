#include <iostream>
#include <map>
#include <vector>


using namespace std;
#ifndef DAOUSUARIO
#define DAOUSUARIO

class DaoUsuario 
{
public:
    // MÉTODOS DE ACESSO
    DaoUsuario();
    map<std::string, Usuario> getDataModels();
    Usuario getDataModelById(std::string registro);
    // MÉTODOS DE MODIFICAÇÃO
    bool saveDataModel(Usuario newLivro);
    bool deleteDataModel(Usuario livroDeletado);
    bool apagarDadosDoArquivo(const char *path);
};

#endif // DAOUSUARIO