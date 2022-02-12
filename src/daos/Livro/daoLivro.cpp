#include "DataModel/livro.hpp"
#include "daoLivro.hpp"
#include <iostream>
#include <map>
#include <vector>
//includes para salvar pastas e arquivos
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <cstdlib>
#include <fstream>
using namespace std;

DaoLivro::DaoLivro()
{
}

map<std::string, vector<DataModelLivro>> DaoLivro::getDataModels()
{
    //implementar busca do banco de dados
    map<string, vector<DataModelLivro>> livros;
    return livros;
}
DataModelLivro DaoLivro::getDataModelById(std::string registro)
{
    //implementar busca por id do banco de dados
    DataModelLivro livro = DataModelLivro("asdf", "asdf", "asdf", "asdf", true);

    return livro;
}
void DaoLivro::saveDataModel(DataModelLivro newLivro)
{
    //criação de arquivo
    struct stat st = {0};
    string filename("../bancoLocalDeDados/Livros/" + newLivro.get_registro());
    const char *filename2 = filename.c_str();

    string cod("mkdir -p " + filename);
    const char *code2 = cod.c_str();

    if (stat(filename2, &st) == -1)
    {
        const int dir_err = system(code2);
        if (-1 == dir_err)
        {
            printf("Error creating directory!n");
            exit(1);
        }
        else
        {
            cout << "Arquivo criado com sucesso" << endl;
        }
    }

    //salvando o dado

    string text("{  \n");
    //construindo o texto que sera salvo
    text = text + "\"nome\": \"" + newLivro.get_nome() + +"\" ," + "\n";
    text = text + "\"autor\": \"" + newLivro.get_autor() + +"\" ," + "\n";
    text = text + "\"genero\": \"" + newLivro.get_genero() + +"\" ," + "\n";
    text = text + "\"registro\": \"" + newLivro.get_registro() + "\"," + "\n";
    text = text + "\"disponivel\":" + to_string(newLivro.is_disponivel()) + "\n";
    text = text + "} \n";
    string filenameFinal(filename + "/output.json");
    fstream outfile;

    outfile.open(filenameFinal, std::ios_base::app);
    if (!outfile.is_open())
    {
        cerr << "failed to open " << filenameFinal << '\n';
    }
    else
    {
        outfile.write(text.data(), text.size());
        cerr << "Done Writing!" << endl;
    }
}

void DaoLivro::deleteDataModel(DataModelLivro livroDeletado)
{
}