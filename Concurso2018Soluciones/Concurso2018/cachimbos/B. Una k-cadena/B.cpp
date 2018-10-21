
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

/*
 * Solucion:
 * Para que una cadena pueda ser representada como k copias concatenadas
 * todos los caracteres que conforman la cadena deben ser multiplos de k o en otras palabras 
 * el numero de incidencia de cada caracter modulo k debe ser 0
 */
int main()
{
    int k,tam,freq[300];
    bool band =true;
    string cad;
    memset(freq,0,sizeof freq);// llena con valores(ceros) el arreglo freq
    cin>>k>>cad;
    tam=cad.size();
    for(int j=0;j<tam;j++)
        freq[cad[j]-'0']++;// contando el numero de incidencia de cada caracter
    int i=0;
    while(i<300&&band)
    {
        if(freq[i]!=0)
        {
            if(freq[i]%k!=0)
                band=false;
        }
        i++;
    }
    if(band)
        cout<<"SI"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

