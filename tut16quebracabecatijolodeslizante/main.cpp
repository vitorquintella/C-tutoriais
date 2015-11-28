//quebra cabecas  de tijolos deslizantes

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

using namespace std;

const int min_lado=2; // min de tamanho lateral do quebracabeca
const int tam_padrao =3; // tamanho parao

class Quebracab{ // a classe quebracabeca de tijolos deslizantes

    int vazio; // indice linear da casa vazia
    int mov; // numero de movimentos

    Matriz* mqc; //matriz interna do quebracabeca

public:
    Quebracab(const int ld=tam_padrao); //cria quebracabeca, ld = lado

    void mostra() const; // mostra quebracabeca

    void movedir();//move celula a esq de vazio para direita

    void moveesq();//move celula a direita de vazio para a esquerda

    void movebaixo();//move celula acima de vazio para baixo

    void movecima();//move celula abaixo de vazio para cima

    void  embaralha(); // embaralha quebracabeca

    int tstsolucao() const; // testa se quebracabeca esta solucionado ??? porque constante?

    int retorna_mov() {return mov;} // retorna o numero de movimentos

    ~Quebracab(); //destroi quebracabeca

};

//definindo o que cada metodo realiza

Quebracab::Quebracab(const int ld){ //argumento ja foi definido como tamanho padrao
    int ldc = abs(ld); // ld copia = valorabsoluto de ld

    if (ldc<min_lado){ldc=min_lado;}

    mqc = new Matriz(ldc,ldc); // inicializa o objeto matriz

    for (int i=1; i<mqc->gett();i++) //??? não entendi essa do for !!!

        mqc->atribuiindlin(i,i); // inicializa casas da matriz ??? naoentendi !!!

    mqc->atribuiindlin(mqc->gett(),0);//atribui zearo a posicao celula vazia

    vazio = mqc->gett(); //defineposicao da celula vazia

    mov = 0; //sem nenhum movimento

    embaralha(); //embaralha o quebracabeca


}

void Quebracab::mostra() const{ //mostra quebra cabeca
    int i,j; //linha e coluna

    int* ind; // valor atual

    for (i=1;i<=mqc->getl();i++){ //linhas
        for (j=1;j<=mqc->getc();j++){ //colunas
            ind=mqc->linear(i,j);//o resultado tambem éumponteiro ???
            if ((*ind)==vazio){
                cout << setw(4)<<" "; // se for vazio a respos é " ".
            }else {
                cout << setw(4) << (*mqc->retornaindlin(*ind)); // mostra o conteudo
            }

        }
        cout << endl;
    }
    cout << endl;
}

void Quebracab::movedir(){//moce celula a esq de vazio para a direita
    //o espaco move para a  esquerda, somente se naão estiverna esquerda
    if((*(mqc->col(vazio))) !=1){
        mqc->trocaindlin(vazio,vazio-1);

        mov++;

        vazio=vazio-1;

    }
}

void Quebracab::moveesq(){
    //o espaco move para a  direita, somente se naão estiverna direita
    if((*(mqc->col(vazio))) !=mqc->getc()){
        mqc->trocaindlin(vazio,vazio+1);

        mov++;

        vazio=vazio+1;

    }
}

void Quebracab::movebaixo(){
    //o espaco move para cima, somente se naão estiver em cima
    if((*(mqc->lin(vazio))) !=1){
        mqc->trocaindlin(vazio,vazio-(mqc->getc())); //chama a funcao private

        mov++;

        vazio=vazio-(mqc->getc());

    }
}

void Quebracab::movecima(){
    //o espaco move para cima, somente se naão estiver em baixo
    if((*(mqc->lin(vazio))) != mqc->getl()){
        mqc->trocaindlin(vazio,vazio+(mqc->getc()));

        mov++;

        vazio=vazio+(mqc->getc());

    }
}

void Quebracab::embaralha(){
    int i,j; //loopprincipal, loop secundario
    int r; // r vezes

    for (j=0; j<mqc->gett();j++){

        r = (rand()%mqc->getc());
        for (i = 0; i<r;i++) {this->movedir();}//move r vezes

        r = (rand()%mqc->getl());
        for (i = 0; i<r;i++) {this->movebaixo();}//move r vezes

        r = (rand()%mqc->getc());
        for (i = 0; i<r;i++) {this->moveesq();}//move r vezes

        r = (rand()%mqc->getl());
        for (i = 0; i<r;i++) {this->movecima();}//move r vezes

    }
    mov=0; // inicializa movimentos
}

int Quebracab::tstsolucao() const{
    int i=1,cont=1;

    while (cont &&(i< (mqc->gett()))){  //?? não entendi esse cont &&...
        if((*(mqc->retornaindlin(i)))==(i)) {cont=1;}
        else{cont=0;}
        i++;
    }
    return (cont);
}

Quebracab::~Quebracab(){
    if (mqc!=NULL) {delete mqc; cout << " Quebra cabeca destruido!\n";} //destroi quebracab

}



int main(int argc,char *argv[])
{//abremain
    int ladocomp;
    char opcao; // eh utilizada como variavel de opcao

    if (argc>1) {ladocomp=atoi(argv[1]);}//convertendo o argumento de linha de comando para inteiro
    else {ladocomp=tam_padrao;} //valor default

    Quebracab umquebracab(ladocomp);//criandoquebracab

    do {
        umquebracab.mostra();
        cout <<"\n"; //menu de opcoes

        cout <<" Movimentos:" << umquebracab.retorna_mov()<< "\n";

        cout <<" 4<- 6-> 8Cima 2Baixo SSair Eembaralha \n";

        cout <<" Reconhece sequencias de comandos: 268624 <Enter>\n";

        cout <<" Aceita argumento de linha de comando: quebracab 4 (cria quebracabeca 4 x 4)\n";

        cout <<" Entre comando:";

        cin >> opcao; //le opcao do usuario

        cout <<"\n";

        switch(opcao){ //executa opcao do usuario

        case 'E':

        case 'e':

            umquebracab.embaralha();

            break;

        case '8': umquebracab.movecima();

            break;

        case '2': umquebracab.movebaixo();

            break;

        case '4': umquebracab.moveesq();

            break;

        case '6': umquebracab.movedir();

            break;

        default: ;
        } //fim do  bloco de codigo do switch-case

        if (umquebracab.tstsolucao()) {opcao ='s';} //sai do loop do menu

    } while ((opcao !='S') && (opcao !='s')); //loopmenu

    if (umquebracab.tstsolucao()) {umquebracab.mostra(); cout << " Parabens!\n";}

    else {cout << " Quebra cabeca nao solucionado. Tente novamente!\n";}

    return 0;


}

