#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
# define INF 0x3f3f3f3f 

typedef pair<int, int> pi;
vector<pair<ll,ll > > adj[1005];
int dist[1005];
void bfs(int** edges,int x,int n)         //x=starting vertex n=total vertex
{
    int s=0;
    for(int i=0;i<n;i++)
    {
        dist[i]=INF;
    }
    priority_queue<pair<int,int > > pq;
    pq.push(make_pair(0,x));//distance is zero and x is source (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair)
    dist[x]=0;
    while(!pq.empty())
    {
        int m=pq.top().second;//source x is taken out
        //cout<< m <<" stand "<<endl;
        pq.pop();
        for(int j=0;j<n;j++)
        {
            //cout<<j<<endl;
            //cout<<dist[j]<<" adj ka dist--> current vertex ka dist"<<dist[m]<<"  weight->  "<<edges[m][j]<<endl;
            if(edges[m][j]>0)
            {
	            if(dist[j]> dist[m] + edges[m][j] )
	            {
	                //first: is child vertex and second: is weight on adj edge to m
	                dist[j] = dist[m] + edges[m][j] ;
	                //cout<<"entered "<<dist[j]<<" --> "<<dist[m]<<" "<<edges[m][j]<<endl;
	                pq.push(make_pair(dist[j],j));
	            }            	
            }

        }
    }
    for(int i=0;i<n;i++)
        cout<< i<<" "<<dist[i]<<endl;
}

int main()
{
    ll n,e,x,y,z;    //n=nodes e=edges
    cin>>n>>e;    //entering no. of node and edges
    int** edges=new int*[n+2];
    for(int i=0;i<=n;i++)
    {
        edges[i]=new int[n+2];
        for(int j=0;j<=n;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=1;i<=e;i++)
    {
        cin>>x>>y>>z;              //x-->y  edges connection...corresponding z weight
        edges[x][y]=z;         //undirected graph
        edges[y][x]=z;
    }
    bfs(edges,0,n);//starting vertex and no. of vertices
    return 0;
}
