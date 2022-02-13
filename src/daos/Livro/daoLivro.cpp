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

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

using namespace std;

DaoLivro::DaoLivro()
{
}

map<std::string, vector<DataModelLivro>> DaoLivro::getDataModels()
{
    //implementar busca do banco de dados
    map<string, vector<DataModelLivro>> livros;
    vector<DataModelLivro> v;

    DIR *dir;
    struct dirent *lsdir;

    dir = opendir("../bancoLocalDeDados/Livros");

    /* print all the files and directories within directory */
    while ((lsdir = readdir(dir)) != NULL && lsdir->d_name != "." && lsdir->d_name != "..")
    {
        printf("%s\n", lsdir->d_name);
        DataModelLivro livroTemp("", "", "", "", false);

        livroTemp = this->getDataModelById(lsdir->d_name);

        v.push_back(livroTemp);
        livros.insert({livroTemp.get_genero(), v});
    }

    closedir(dir);

    return livros;
}
DataModelLivro DaoLivro::getDataModelById(std::string registro)
{

    //implementar busca por id do banco de dados
    DataModelLivro livro = DataModelLivro("asdf", "asdf", "asdf", "asdf", true);

    FILE *arq;
    char Linha[100];
    char *result;
    int i;

    string filename("../bancoLocalDeDados/Livros/" + registro + "/output.txt");
    const char *filename2 = filename.c_str();

    string linha;
    //ifstream – abre o arquivo apenas para leitura
    ifstream arq_in(filename2);
    if (arq_in.is_open())
    {
        //eof() - retorna true ao atingir o fim do arquivo
        while (!arq_in.eof())
        {
            getline(arq_in, linha);
            // cout << linha << endl;

            if (linha != "{" && linha != "}" && linha.find(" ") > 0 && linha.find(" ") < linha.length())
            {
                std::string value = linha.substr(linha.find(" "), linha.length() - 1);
                std::string atributo = linha.substr(0, linha.find(":"));
                livro.set_atributo(atributo, value);
            }
        }
        arq_in.close();
    }
    else
    {
        cout << "ERRO: arquivo não foi aberto ou não existe" << endl;
    }

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
    text = text + "nome: " + newLivro.get_nome() + "\n";
    text = text + "autor: " + newLivro.get_autor() + "\n";
    text = text + "genero: " + newLivro.get_genero() + "\n";
    text = text + "registro: " + newLivro.get_registro() + "\n";
    text = text + "disponivel: " + to_string(newLivro.is_disponivel()) + "\n";
    text = text + "} \n";
    string filenameFinal(filename + "/output.txt");
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