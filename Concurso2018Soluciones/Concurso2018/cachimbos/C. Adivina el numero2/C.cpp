#include<iostream>

using namespace std;
/*
 * Solucion:
 * Simular las operaciones pero de retroceso y tomando en cuenta que los operadores
 * + cambian por - y viceversa , * cambian por / y viceversa
 */
int main()
{
    int c,operaciones,resultado;
    cin>>c;
    for(int j=0;j<c;j++)
    {
        cin>>operaciones;
        int numero[105];
        char operador[105];
        for(int i=0;i<operaciones;i++)
        {
            cin>>operador[i]>>numero[i];    
        }
        cin>>resultado;
        for(int i= operaciones-1; i>=0;i--)
        {
            if(operador[i] == '+')
                resultado -= numero[i]; // forma reducida de resultado = resultado - numero[i]
            else if(operador[i] == '-')
                resultado += numero[i]; 
            else if(operador[i] == '*')
                resultado /= numero[i];
            else if(operador[i] == '/')
                resultado *= numero[i];
        }
        cout<<"Caso #"<<j+1<<": "<<resultado<<endl;
    }
}
