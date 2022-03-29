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



DaoLivro::DaoLivro()
{
}

std::map<std::string, std::vector<DataModelLivro>> DaoLivro::getDataModels()
{
    //implementar busca do banco de dados
    std::map<std::string, std::vector<DataModelLivro>> livros;

    DIR *dir;
    struct dirent *lsdir;

    dir = opendir("../bancoLocalDeDados/Livros");

    /* print all the files and directories within directory */
    while ((lsdir = readdir(dir)) != NULL && lsdir->d_name != "." && lsdir->d_name != "..")
    {
        //printf("%s\n", lsdir->d_name);
        DataModelLivro livroTemp("", "", "", "", false);
        std::vector<DataModelLivro> v;
        livroTemp = this->getDataModelById(lsdir->d_name);

        if (livroTemp.get_genero() != "")
        {
            v = this->getLivrosDeMesmoGenero(livroTemp.get_genero());

            livros.insert({livroTemp.get_genero(), v});
        }
    }

    closedir(dir);

    return livros;
}
std::vector<DataModelLivro> DaoLivro::getLivrosDeMesmoGenero(std::string genero)
{
    std::vector<DataModelLivro> vetorDelivrosDoMesmoGenero;
    DIR *dir;
    struct dirent *lsdir;

    dir = opendir("../bancoLocalDeDados/Livros");

    /* print all the files and directories within directory */
    while ((lsdir = readdir(dir)) != NULL && lsdir->d_name != "." && lsdir->d_name != "..")
    {
        DataModelLivro livroTemp("", "", "", "", false);
        livroTemp = this->getDataModelById(lsdir->d_name);

        if (livroTemp.get_genero() == genero)
        {
            vetorDelivrosDoMesmoGenero.push_back(livroTemp);
        }
    }
    return vetorDelivrosDoMesmoGenero;
}
DataModelLivro DaoLivro::getDataModelById(std::string registro)
{

    //implementar busca por id do banco de dados
    DataModelLivro livro = DataModelLivro("", "", "", "", false);

    FILE *arq;
    char Linha[100];
    char *result;
    int i;

    std::string filename("../bancoLocalDeDados/Livros/" + registro + "/output.txt");
    const char *filename2 = filename.c_str();

    std::string linha;
    //ifstream – abre o arquivo apenas para leitura
    std::ifstream arq_in(filename2);
    if (arq_in.is_open())
    {
        //eof() - retorna true ao atingir o fim do arquivo
        while (!arq_in.eof())
        {
            getline(arq_in, linha);
            //std::cout << linha << endl;

            if (linha != "{" && linha != "}" && linha.find(" ") > 0 && linha.find(" ") < linha.length())
            {
                std::string value = linha.substr(linha.find(" ") + 1, linha.length() - 1);
                std::string atributo = linha.substr(0, linha.find(":"));

                livro.set_atributo(atributo, value);
            }
        }
        
    }
    else
    {
        //throw std::invalid_argument("Arquivo nao foi aberto ou nao existe!\n");
    }
    arq_in.close();
    return livro;
}
bool DaoLivro::saveDataModel(DataModelLivro newLivro)
{
    
    //criação de arquivo
    struct stat st = {0};
    std::string filename("../bancoLocalDeDados/Livros/" + newLivro.get_registro());
    
    const char *filename2 = filename.c_str();

    std::string cod("mkdir -p " + filename);
    const char *code2 = cod.c_str();

    if (stat(filename2, &st) == -1)
    {
        const int dir_err = system(code2);
        if (-1 == dir_err)
        {
            printf("Error creating directory!n");
            exit(1);
            return false;
        }
        else
        {
            std::cout << "Arquivo criado com sucesso" << std::endl;
        }
    }

    //salvando o dado

    std::string text("{  \n");
    //construindo o texto que sera salvo
    text = text + newLivro.to_string();
    text = text + "} \n";
    std::string filenameFinal(filename + "/output.txt");
    std::fstream outfile;    
    const char *filenameFinal2 = filenameFinal.c_str();

    this->apagarDadosDoArquivo(filenameFinal2);

    outfile.open(filenameFinal);
    if (!outfile.is_open())
    {
        std::cerr << "failed to open " << filenameFinal << '\n';
        return false;
    }
    else
    {
        outfile.write(text.data(), text.size());
        std::cerr << "Done Writing!" << std::endl;
        return true;
    }
}

bool DaoLivro::apagarDadosDoArquivo(const char *path)
{
    FILE *arquivo;
    arquivo = fopen(path, "w");
    fclose(arquivo);
    return true;
}

bool DaoLivro::deleteDataModel(DataModelLivro livroDeletado)
{
    return true;
}