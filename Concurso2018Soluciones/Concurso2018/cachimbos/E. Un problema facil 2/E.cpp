#include<iostream>
#include<algorithm>

using namespace std;
/*
 * Solucion:
 * En programacion competitiva 1s = 10^8 operaciones, esto determina que en ciertos
 * problemas tenemos que reducir la complejidad de nuestra solucion, en el problema
 * En el grupo 1, N = 10^3 lo que nos permite dar una solucion en O(n^2) , pero 
 * En el grupo 2, N = 10^5 con una solucion O(n^2) obtendriamos Tiempo excedido ya que el
 * numero de operaciones al realizar ahi son 10^10 mucho mayor a 10^8 , por lo tanto tenemos
 * que reducir la complejidad de la solucion hasta O(n logn) con lo que si pasaria el problema 
 * para hacer esto aplicaremos busqueda binaria, recorremos el arreglo y por cada numero del 
 * arreglo aplicaremos busqueda binaria( con el arreglo ordenado) para encontrar el numero
 * en caso exista que cumpla la condicion del problema
 */

int n,k,temp;
int arr[100005];
int val;
int s=0;

void bin(int x,int y)
{
    int mid=(x+y)/2;
    if(val-arr[mid]==k)
    {
        s++;
        return;
    }
    if(x>=y)
        return;
    if(val-arr[mid]>k)
        bin(mid+1,y);
    if(val-arr[mid]<k)
        bin(x,mid-1);
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        val=arr[i];
        bin(0,i);
    }
    cout<<s<<endl;
    return 0;
}
