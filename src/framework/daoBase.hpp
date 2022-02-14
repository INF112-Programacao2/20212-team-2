#include <iostream>
#include <map>
#include <vector>

#include "./dataModelBase.hpp"
using namespace std;
#ifndef DAOBASE_HEADER
#define DAOBASE_HEADER

template <typename T>

class DaoBase
{

public:
    virtual map<std::string, vector<T>> getDataModels() = 0;
    virtual T getDataModelById(std::string registro) = 0;
    virtual vector<T> getLivrosDeMesmoGenero(std::string genero) = 0;
    // MÉTODOS DE MODIFICAÇÃO
    virtual bool saveDataModel(T newLivro) = 0;
    virtual bool deleteDataModel(T livroDeletado) = 0;
    virtual bool apagarDadosDoArquivo(const char *path) = 0;
};

#endif // DAOBASE_HEADER