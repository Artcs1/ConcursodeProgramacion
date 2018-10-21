#include<bits/stdc++.h>

using namespace std;

/*
 * Solucion:
 * Hallar las distancias minimas en cada punto , solo considerando los caminos , sin contar los paraderos,esto se hace con el algoritmo 
 * dijstrak, una vez teniendo las minimas distancias, en cada punto cogeremos el metropolitano si hubiera un paradero y calculamos el ti
 * tiempo para llegar a la universidad( tiempo de llegar al punto + tiempo de espera del metropolitano + tiempo para llegar a la 
 * universidad en el metropolitano) , buscamos el minimo de esos valores y dist[n]( tiempo de llegar solo caminando )
 */

struct node{
    int v,w;
    node(){}
    node(int v,int w):v(v),w(w){}
    bool operator<(node a)const
    {
        return w> a.w;
    }
};

vector<node>ady[1005];

vector<int> dijstrak()
{    
    vector<int> dist(1005,1e9);
    dist[0] = 0 ;
    priority_queue< node > pq;
    pq.push(node(0,0));
    while(!pq.empty())
    {
        node frente = pq.top();
        pq.pop();
        int u = frente.v,d = frente.w;
        if( d > dist[u] )
            continue;
        for(int j=0;j<(int) ady[u].size();j++)
        {
            node v = ady[u][j];
            if(dist[u]+ v.w < dist[v.v])
            {
                dist[v.v] = dist[u] +v.w;
                pq.push(node(v.v,dist[v.v]));
            }
        }
    }
    return dist;
}
int main()
{
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++)
    {
        vector< pair<int,int> > A;
        int puntos,caminos, paradero,destino,u,v,w;
        scanf("%d %d",&puntos,&caminos);
        for(int j=0;j<puntos;j++)
        {
            scanf("%d %d",&paradero,&destino);
            A.push_back(pair<int,int> (paradero,destino));
        }
        for(int j=0;j<caminos;j++)
        {
            scanf("%d %d %d",&u,&v,&w);
            u--,v--;
            ady[u].push_back(node(v,w));
            ady[v].push_back(node(u,w));
        }
        vector<int> distancias = dijstrak();
        int res = distancias[puntos-1];
        for(int j =0; j<puntos ; j++)
        {
            if(A[j].first!=0)
            {
                int mod = distancias[j]%A[j].first;
                if(mod == 0 )
                     mod = A[j].first;
                res = min(res,distancias[j]+A[j].second+(A[j].first -mod));
            }
        }
        if(res == 1e9)
            printf("Caso #%d: -1\n",i+1);
        else
            printf("Caso #%d: %d\n",i+1,res);
        for(int j=0;j<puntos;j++)
            ady[j].clear();
    }
    return 0;
}
