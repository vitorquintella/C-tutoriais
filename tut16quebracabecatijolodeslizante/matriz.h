#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz
{
    int linhas;// numero de linhas d amatriz
    int colunas; //numero de colunas da matriz
    int tam; // = linhas*colunas
    int *lc; // ??? vetor de tamanho linha*colunas representando a matriz: 0...(tam-1)

public:
    Matriz(const int l, const int c);//cria a matriz LxC, com atributos constantes
    
    
    // ??? qualquer uma das funcoes abaixo retorna nil se nao conseguiu

    int* linear (const int alin, const int acol) const;// ind linear a partir de linha e coluna
    
    int* col (const int indlin) const; // coluna a partir d eindice linear
    
    int* lin(const int indlin) const; // linha a partir do indice linear
    
    int trocaindlin( const int i, const int j); // argumentos: 2 indices lineares
    //retorna 1 conseguiu, 0 se não conseguiu
    
    int atribuiindlin(const int i, const int v); //atribui v ao indice i
    //retorna 1 conseguiu, 0 não conseguiu
    
    int* retornaindlin(const int i); //retorna conteuda do indice i
    //retorna nil se não conseguiu
    
    int getl();//retorna numero de linhas
   
    int getc();//retorna numero de colunas
    
    int gett();//retorna tamanho = linhas*colunas
    
    ~Matriz();
};

#endif // MATRIZ_H
