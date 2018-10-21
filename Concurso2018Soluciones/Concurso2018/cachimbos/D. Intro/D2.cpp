#include<iostream>
using namespace std;
int main()
{  
    int num,casos,m;
    cin>>casos;
    while(casos--)
    {
        cin>>num;
        m=0;
        while(num!=0)
        {
            m+=num%2;
            num/=2;
        }
        cout<<m<<endl;
    }
    return 0;
}
