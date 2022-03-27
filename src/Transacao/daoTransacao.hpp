#include <iostream>
#include <map>
#include <vector>
#include "transacao.hpp"

using namespace std;
#ifndef DAOTRANSACAO
#define DAOTRANSACAO

class DaoTransacao 
{
public:
    // MÉTODOS DE ACESSO
    DaoTransacao();
    Transacao getDataModelById(std::string registro);
    // MÉTODOS DE MODIFICAÇÃO
    bool saveDataModel(Transacao newLivro);
    bool deleteDataModel(Transacao livroDeletado);
    bool apagarDadosDoArquivo(const char *path);
};

#endif //