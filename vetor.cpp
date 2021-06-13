#include "vetor.h"

Vetor::Vetor()
{
    v = new int [TAMANHO];
    for (int i = 0; i < TAMANHO; i++)
        v[i] =  0;

    numElementos = 0;
}
int Vetor::obtemTamanho()
{
    return numElementos;
}
void Vetor::insereNoFinal(int novoElemento)
{

    if(numElementos < TAMANHO)
    {
        v[numElementos]= novoElemento;
        numElementos++;
    }
  else cout<< "\nVetor cheio!\n";

}

int Vetor::posicaoDe (int elemento)
{

    for(int i =0; i< numElementos; i++)
        if (elemento == v [i])
        return i;

    return -1;

}


void Vetor::alteraEm (int pos, int novoValor)
 {
    if ((pos >=0) && (pos < numElementos))
     v[pos] = novoValor;
    else cout << "\n Posiçao invalida! \n";
 }

int Vetor::elementoDe (int pos)
{
    return 0;
}
int Vetor::elementoEm (int pos)
{
    return 0;
}
void Vetor::reverte() { };

void Vetor::imprime()
{

    for(int i= 0; i< numElementos; i++)
        cout<< v[i] << " ";


};

int Vetor::getTamanhoVetor()
{
    return -1;
}

