#include <bits/stdc++.h>

using namespace std;
/*
 * Solucion:
 * La implementacion de este ejercicio puede ser un poco fastidiosa, ya que 
 * debes usar estrucuturas adecuadas para guardar los datos, por ejemplo para guardar 
 * los horarios disponibles de los alumnos podemos usar una matriz( dias * horas ), 
 * y marcar los horarios disponibles ya que tenemos n alumnos , podriamos construir
 * una matriz tridimensional para guardar los datos, despues en las consultas
 * volvemos pasamos por el intervalo requerido , verificando si en cada hora , mas de los
 * 50% de los alumnos esta disponible en esa hora ( esto por que "un horario de clase es
 * considerado adecuado cuando al menos el 50% de los alumnos
 * (no necesariamente los mismos en cada hora)" )
 */
int main()
{
    map<string ,int>M ;
    M["LU"] = 1,M["MA"] = 2,M["MI"] = 3,M["JU"] = 4,M["VI"] = 5,M["SA"] = 6,M["DO"] = 7;

    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++)
    {
        int matriz[55][30][10];
        memset(matriz, 0, sizeof matriz);
        string cad,dia;
        int n,q,h1,h2;
        scanf("%d",&n);
        cin.ignore();
        for(int j=0;j<n;j++)
        {
            getline(cin,cad);
            istringstream iss(cad);
            while(iss>>dia)
            {
                iss>>h1;
                iss>>h2;
                int k = M[dia];
                for(int ini = h1;ini<h2;ini++)
                    matriz[j][ini][k] = 1;
            }
        }
        scanf("%d",&q);
        printf("Caso #%d:",i+1);
        for(int z=0;z<q;z++)
        {
            cin>>dia>>h1>>h2;
            int d = M[dia];
            bool band = true;
            for(int hora=h1;hora<h2;hora++)
            {
                int c =0;
                for(int j=0;j<n;j++)
                    c+= matriz[j][hora][d];
                if(2*c < n)
                    band = false;
            }
            (band)?printf(" Si"):printf(" No");
        }
        printf("\n");
    }
    return 0;
}
