## Trabalho Final da Disciplina INF 112 - Programação II da UFV

### Professor da Disciplina
- Julio Soares Reis (@juliosoaresreis)

### Grupo 02
- Caio Gomes Braga (@caiobraga)
- Gabriel Moraes Ribeiro (@GabrielMoraesRibeiro)
- Henrique Andrade Lopes (@H3nriqu3L)
- Lucas Mombach (@Lucas-Mombach)

### User Stories
1. Como bibliotecário, eu quero cadastrar livros do catálogo para manter o catálogo sempre atualizado
2. Como bibliotecário, eu quero saber a multa de atraso de um sócio para que possa cobrá-lo adequadamente
3. Como bibliotecário, eu  quero saber a disponibilidade de um determinado livro para poder emprestá-lo ou não
4. Como bibliotecário, eu quero cadastrar um novo usuário com contato para poder pedir a devolução em caso de atraso
5. Como bibliotecário, eu quero poder ver a lista de usuários e livros atrasados
6. Como bibliotecário, eu quero poder editar livros já cadastrados

### Classes (Definição)
- [ ] Biblioteca
- [x] Livro
- [x] Usuário
- [ ] Transações
- [ ] Histórico de Transações

### Como compilar o programa
    Para compilar e executar o programa é necessário estar na pasta "20212-team-2/src" e utilizar o codigo abaixo no terminal:

    g++ main.cpp Biblioteca/biblioteca.cpp Livro/DataModel/livro.cpp Transacao/transacao.cpp Usuarios/DataModel/usuario.cpp UsuarioVip/usuariovip.cpp Livro/daoLivro.cpp Usuarios/daoUsuario.cpp

    
    Durante a execuçao do programa, instruçoes serao dadas para a execuçao correta.
