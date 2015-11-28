#include "matriz.h"
#include <iostream>

using namespace std;

Matriz::Matriz(const int l, const int c){
    lc = new int[l*c]; //l,c dimensoes; lc vetor[l*c]
    linhas = l;
    colunas = c;
    tam = linhas*colunas;

}

int* Matriz::linear (const int alin, const int acol) const{ // ind linear a partir de linha e coluna

    int* result = new int; //valor de retorno

    if((0<alin)&&(alin<=linhas)&&(0<acol)&&(acol<=colunas)){
        (*result) = (alin-1)*colunas+acol;
        return result;
    }else{
        return NULL;
    }
}

int* Matriz::col (const int indlin) const{ // coluna a partir d eindice linear  ??? nao entendi, cade o calculo?
    int* result = new int;
    if((0<indlin)&&(indlin<=tam)){

        (*result) =(indlin % colunas);
        if((*result) == 0){
            (*result) = colunas;
        }
        return result;

    }else{
        return NULL;
    }

}

int* Matriz::lin(const int indlin) const{ // linha a partir do indice linear
    int* result = new int;

    if((0<indlin)&&(indlin<=tam)){
        (*result)=(int((indlin-1)/colunas)+1);
        return result;
    }else{
        return NULL;
    }

}
int Matriz::trocaindlin( const int i, const int j){ // argumentos: 2 indices lineares
    int aux;
    if ((0<i)&&(i<=tam)&&(0<j)&&(j<=tam)){
        aux = lc[i-1]; //efetua a troca

        lc[i-1] = lc[j-1]; // apresentacao diferente para o usuario que entede de 1 até l*c

        lc[j-1] = aux;

        return 1;//sucesso
    }else{
        return 0;//falha
    }
}


int Matriz::atribuiindlin(const int i, const int v){ //atribui v ao indice i

    if((0<i)&&(i<=tam)){
        lc[i-1]=v; //efetua a atribuição
        return 1;//sucesso
    }else{
        return 0;//falha
    }
}

int* Matriz::retornaindlin(const int indlin){ //retorna conteuda do indice i
    int* result = new int;

    if((0<indlin)&&(indlin<=tam)){ //de onde esse indlin fica surgindo??
        *result = lc[indlin-1];

        return result;
    }else{
        return NULL;
    }
}

int Matriz::getl(){//retorna numero de linhas
    return linhas;
}

int Matriz::getc(){//retorna numero de colunas
    return colunas;
}

int Matriz::gett(){//retorna tamanho = linhas*colunas
    return tam;

}

Matriz::~Matriz()
{
cout << "deletando objeto lc"<< endl;
delete lc;
cout << "objeto lc deletado"<< endl;
}
