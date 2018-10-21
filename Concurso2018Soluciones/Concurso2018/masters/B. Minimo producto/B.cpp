#include<bits/stdc++.h>

using namespace std;

/*
 * Solucion:
 * Dado que el numero n puede ser maximo 8, se podria resolver con una busqueda completa,
 * pero existe una mejor solucion y mas facil de implementar , por ejemplo: Si tengo 3 numeros
 * 22 10 -5 , y aparte tengo el numero 15 , para quiero obtener el minimo numero de la 
 * operacion ( 15 * (alguno de los otros 3 numeros) ), multiplicaria por el menor de ellos
 * Dado que en nuestro caso todos deben multiplicarse con otro numero , deberiamos juntar
 * el primer mayor valor del arreglo A , con el primer menor valor del arreglo B , y asi con 
 * el segundo , tercero, hasta llegar al n y sumar cada suma
 */
int main()
{
    int c,n;
    scanf("%d",&c);
    int A[10],B[10];
    for(int i=0;i<c;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
            scanf("%d",&A[j]);
        for(int j=0;j<n;j++)
            scanf("%d",&B[j]);

        // Ordenando de menor a mayor
        sort(A,A+n);

        // ordenando de menor a mayor
        sort(B,B+n);
        // Reverse: ahora esta de mayor a menor
        reverse(B,B+n);

        int r =0;
        for(int j=0;j<n;j++)
            r = r + (A[j]*B[j]);

        printf("Caso #%d: %d\n",i+1,r);
    }
    return 0;
}
