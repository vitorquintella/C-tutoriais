#include <iostream>

using namespace std;

//cria a classe que conta algo


struct Counter{
    int num;

    //adiciona um ao contador
    void incremet(){
        num += 1;
    }

    void start(){
        num = 0;
    }
};


int main()
{
    Counter acounter;
    acounter.start();
    cout << "contador = " << acounter.num <<endl;

    acounter.incremet();
    cout << "contador = " << acounter.num <<endl;

    return 0;
}

