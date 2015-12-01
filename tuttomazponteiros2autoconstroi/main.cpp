#include <iostream>

using namespace std;



struct Folha {
    Folha *esquerda;
    Folha *direita;
    int v;

    Folha(int valor){
        esquerda = NULL;
        direita = NULL;
        v=(valor);
    }
};



void imprimeFolha(Folha *fo){
    int decisao;

    cout << "Voce esta em " <<fo->v<< endl;
    cout << "cujo endereco eh:   " << &fo << endl; // esses enderecos nao deviam ser iguais aos enderecos printados no main?

    if (fo->esquerda){cout <<"aa esquerda tem  "<< fo->esquerda->v<<endl;}
    if (fo->direita){cout <<"aa direita tem  "<< fo->direita->v<<endl;}



    if ((fo->esquerda && fo->direita)== false){
        cout << "fim de arvore!!" << endl;
        return ;
    }

    cout << "avancar para qual?" << endl;

    std::cin >> decisao;
    cout << endl;

    if (decisao == fo->esquerda->v){
        imprimeFolha(fo->esquerda);
    }else if (decisao == fo->direita->v){
        imprimeFolha(fo->direita);
    }else {
        cout << "nao entendi, repetindo..." << endl << endl;
        imprimeFolha(fo);
    }

}


void constroiArvore(Folha *base){
    int valordireita;
    int valoresquerda;

    cout << "endereco de folha " << base->v << " eh :   "<<  &base << endl<< endl;

    cout << "voce esta em: "  <<base->v << endl;
    cout << "Qual o valor da folha a direita?? ('0' para encerrar o ramo) "  << endl;
    std::cin >> valordireita;

    if (valordireita != 0){
        base->direita = new Folha(valordireita);

        constroiArvore(base->direita);}

    cout << "voce esta em: "  <<base->v << endl;
    cout << "Qual o valor da folha a esquerda?? ('0' para encerrar o ramo) "  << endl;
    std::cin >> valoresquerda;

    if (valoresquerda != 0){
        base->esquerda = new Folha(valoresquerda);

        constroiArvore(base->esquerda);}

}








int main(){


    cout << endl << endl<< "------------construindo a arvor, folha por folha!------------------------" << endl << endl;
    int valorum;
    cout << "Qual o valor da primeira folha?"  << endl;
    std::cin >> valorum;
    cout << endl;
    Folha *primeira = new Folha(valorum);

    constroiArvore(primeira);


    cout << endl << endl<< "------------lendo a arvore, somente um caminho!------------------------" << endl << endl;
    imprimeFolha(primeira);
    std::cout <<endl;




    return 0;
}

