#include<bits/stdc++.h>

using namespace std;

/*
 * Solucion:
 * Este ejercicio se resuelve con programacion dinamica, ya que nos encontramos com
 * problemas recurrentes, entonces basados en una funcion recursiva , agregamos la etapa 
 * de memorizacion.
 * En la recurrencia debemos elegir entre comprar el item , verder el item , y no vender
 * ni comprar.
 */

int P[100005];
int memo[100005][5];
int n,c;

int dp(int i,int compra)// Complejidad O( 2*n ) = O(n)
{
    if( i == n )
        return 0;
    if(memo[i][compra] != -1) // memorizacion
        return memo[i][compra];
    int r = 0;
    if(compra == 1)// una vez comprado un item tenemos posibilidad de vender , o no vender
        r = max(dp(i+1,0) + P[i],dp(i+1,1));
    else  // si no tenemos comprado el item podemos o comprar , o no comprar
        r = max(dp(i+1,1)-P[i]-c,dp(i+1,0));
    return memo[i][compra] = r; // memorizacion
}

int main()
{
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++)
        scanf("%d",&P[i]);
    
    memset(memo,-1,sizeof memo);
    printf("%d\n",dp(0,0));
    return 0;
}
