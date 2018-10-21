#include<bits/stdc++.h>
using namespace std;

/*
 * Solucion:
 * Es un problema de cadenas que una posible solucion puede ser por medio 
 * del algoritmo sliding windows o dos punteros, Ej:
 * Tenemos una cadena1: ALMUNDIALICPC , cadena2: ACM
 * tenemeos um i = 0 , j=0 si a substring de la cadena1 
 * construida por los indices de i,j , no es dominante j aumenta en 1
 * Si es dominante testa si es la mejor respuesta y guarda , y aumenta i en 1,
 * asi sucesivamente hasta que j == n(tama;o de la cadena 1) , y ya no sea  mas dominante
 */

int freq[30];
int freq2[30];

bool dominante()
{
    for(int i=0;i<30;i++)
        if(freq[i]>freq2[i])
            return false;
    return true;
}
int main()
{
    string cad,cad1;
    int n;
    scanf("%d",&n);
    cin.ignore();
    for(int i2=0;i2<n;i2++)
    {
        memset(freq, 0 ,sizeof freq);
        memset(freq2,0,sizeof freq2);
        getline(cin,cad);
        getline(cin,cad1);

        for(int j=0;j<(int)cad1.size();j++)
        {
            freq[cad1[j]-'A']++;
        }

        string res = "",temp = "";
        int i = 0, j = 0;

        while(j<(int)cad.size())
        {
            if(!dominante())
                freq2[cad[j]-'A']++,temp+=cad[j],j++;
            else
            {
                if(res == "")
                    res = temp;
                else if(res.size() > temp.size())
                    res = temp;
                else if(res.size() == temp.size() && res>temp)
                    res = temp ;
                freq2[cad[i]-'A']--,temp = temp.substr(1,(int)temp.size()),i++;
            }
        }
        while(dominante())
        {
            if(res == "")
                res = temp;
            else if(res.size() > temp.size())
                res = temp;
            else if(res.size() == temp.size() && res>temp)
                res = temp ;
            freq2[cad[i]-'A']--,temp = temp.substr(1,(int)temp.size()),i++;
        }
        printf("Caso #%d: ",i2+1);
        if(res == "")
            printf("NO ES DOMINANTE\n");
        else
            printf("%s\n",res.c_str());
    }
    return 0;
}
