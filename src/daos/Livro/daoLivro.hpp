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
    // MÉTODOS DE MODIFICAÇÃO
    void saveDataModel(DataModelLivro newLivro);
    void deleteDataModel(DataModelLivro livroDeletado);
};

#endif // DAOLIVRO_HEADER