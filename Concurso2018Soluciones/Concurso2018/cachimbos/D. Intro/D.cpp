#include<iostream>

using namespace std;
/*
 * Solucion:
 * Contar el numero de 1 de la forma binaria del numero leido
 * Una forma: divisiones sucesivas entre 2 hasta que n sea 0 , contando cuantas veces el residuo es 1 
 * Otra forma : C++ cuenta con operaciones a nivel de bits que permiten contar el numero de 1 
 * en su representacion binaria.
 */
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>> n;
        cout<< __builtin_popcount(n)<<endl;
    }
    return 0;
}
