#include<bits/stdc++.h>

using namespace std;

/*
 * Solucion:
 * En programacio competitiva 1s = 10^8 operaciones 
 * En el grupo 3 , n = 10^12  lo que nos sugiere encontrar una solucion 
 * con complejidad O(1) o O(log n), sabemos que el maximo comun divsor que 
 * contenga 2 numeros adyacentes es 1 , y que el maximo comun divisor de un solo numero
 * es el mismo numero(mcd ( n  ) = n ), entonces nuestra suma de mcd(1,..n) + mcd(2,..,n)+
 * .. + mcd (n) es igual a (n + n -1) , esta es la formula a partir de n y tambien no 
 * olvidarse que 10^12 es mayor que (2^32) -1(esto es aproximadamente 10^9), por lo que 
 * se usa el tipo de dato long long int
 */
int main()
{
    long long int n;
    scanf("%lld",&n);
    printf("%lld\n",n+n-1);
    return 0;
}
