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


int main(){


    Folha *cinco = new Folha(5);
    cout << "endereco de " << "*cinco" << " eh :   "<< &cinco << endl;

    cinco->direita = new Folha(6);
    cout << "endereco de " << "cinco->direita" << " eh :   "<<  &cinco->direita << endl;


    cinco->esquerda = new Folha(3);
    cout << "endereco de " << "cinco->esquerda" << " eh :   "<<  &cinco->esquerda << endl;

    cinco->esquerda->direita = new Folha(4);
    cout << "endereco de " << "cinco->esquerda->direita" << " eh :   "<<  &cinco->esquerda->direita << endl;

    cinco->esquerda->esquerda = new Folha(1);
    cout << "endereco de " << "cinco->esquerda->esquerda" << " eh :   "<<  &cinco->esquerda->esquerda << endl;

    Folha *seis = cinco->direita;
    cout << "endereco de " << "seis (equivalente a Folha(6))" << " eh :   "<<  &seis << endl;  // !!! o endereco aqui (&seis) não deveria serigual ao endereco  de 61?


    cout << endl<< endl;

    imprimeFolha(cinco);
    std::cout <<endl;




    return 0;
}

