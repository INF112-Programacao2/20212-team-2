//#include "DataModel/livro.cpp
#include "DataModel/livro.hpp"
#include <iostream>
#include <map>
#include <vector>

#include "../framework/daoBase.hpp"


#ifndef DAOLIVRO_HEADER
#define DAOLIVRO_HEADER

class DaoLivro : DaoBase<DataModelLivro>
{
public:
    // MÉTODOS DE ACESSO
    DaoLivro();
    std::map<std::string, std::vector<DataModelLivro>> getDataModels();
    DataModelLivro getDataModelById(std::string registro);
    std::vector<DataModelLivro> getLivrosDeMesmoGenero(std::string genero);
    // MÉTODOS DE MODIFICAÇÃO
    bool saveDataModel(DataModelLivro newLivro);
    bool deleteDataModel(DataModelLivro livroDeletado);
    bool apagarDadosDoArquivo(const char *path);
};

#endif // DAOLIVRO_HEADER