#include "DataModel/livro.cpp"
#include <iostream>
#include <map>
#include <vector>

using namespace std;
#ifndef DAOLIVRO_HEADER
#define DAOLIVRO_HEADER

class DaoLivro 
{
public:
    // MÉTODOS DE ACESSO
    DaoLivro();
    map<std::string, vector<DataModelLivro>> getDataModels();
    DataModelLivro getDataModelById(std::string registro);
    vector<DataModelLivro> getLivrosDeMesmoGenero(std::string genero);
    // MÉTODOS DE MODIFICAÇÃO
    bool saveDataModel(DataModelLivro newLivro);
    bool deleteDataModel(DataModelLivro livroDeletado);
    bool apagarDadosDoArquivo(const char *path);
};

#endif // DAOLIVRO_HEADER