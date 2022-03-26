#include "daoUsuario.hpp"
#include "DataModel/usuario.hpp"
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

DaoUsuario::DaoUsuario()
{
}

map<std::string, usuario> DaoUsuario::getDataModels()
{
    //implementar busca do banco de dados
    map<string, usuario> Usuarios;

    DIR *dir;
    struct dirent *lsdir;

    dir = opendir("../bancoLocalDeDados/Usuarios");

    /* print all the files and directories within directory */
    while ((lsdir = readdir(dir)) != NULL && lsdir->d_name != "." && lsdir->d_name != "..")
    {
        //printf("%s\n", lsdir->d_name);
        usuario u;
        vector<usuario> v;
        u = this->getDataModelById(lsdir->d_name);

        if (u.get_codigo() != "")
        {
            Usuarios.insert({u.get_codigo(), u});
        }
    }

    closedir(dir);

    return Usuarios;
}

usuario DaoUsuario::getDataModelById(std::string registro)
{

    //implementar busca por id do banco de dados
    usuario user;

    FILE *arq;
    char Linha[100];
    char *result;
    int i;

    string filename("../bancoLocalDeDados/Usuarios/" + registro + "/output.txt");
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
            //cout << linha << endl;

            if (linha != "{" && linha != "}" && linha.find(" ") > 0 && linha.find(" ") < linha.length())
            {
                std::string value = linha.substr(linha.find(" "), linha.length() - 1);
                std::string atributo = linha.substr(0, linha.find(":"));

                user.set_atributo(atributo, value);
            }
        }
        arq_in.close();
    }
    else
    {

        //cout << "ERRO: arquivo não foi aberto ou não existe" << endl;
    }
    return user;
}
bool DaoUsuario::saveDataModel(usuario newuser)
{
    //criação de arquivo
    struct stat st = {0};
    string filename("../bancoLocalDeDados/Usuarios/" + newuser.get_codigo());
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
            return false;
        }
        else
        {
            cout << "Arquivo criado com sucesso" << endl;
        }
    }

    //salvando o dado

    string text("{  \n");
    //construindo o texto que sera salvo
    text = text + newuser.to_string();
    text = text + "} \n";
    string filenameFinal(filename + "/output.txt");
    fstream outfile;

    const char *filenameFinal2 = filenameFinal.c_str();

    this->apagarDadosDoArquivo(filenameFinal2);

    outfile.open(filenameFinal, std::ios_base::app);
    if (!outfile.is_open())
    {
        cerr << "failed to open " << filenameFinal << '\n';
        return false;
    }
    else
    {
        outfile.write(text.data(), text.size());
        cerr << "Done Writing!" << endl;
        return true;
    }
}

bool DaoUsuario::apagarDadosDoArquivo(const char *path)
{
    FILE *arquivo;
    arquivo = fopen(path, "w");
    fclose(arquivo);
    return true;
}

bool DaoUsuario::deleteDataModel(usuario userDeletado)
{
    return true;
}