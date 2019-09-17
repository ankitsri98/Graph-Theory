//program gives wa owhen t= 2 test cases 
//first apply bfs from any node then find max then fronm that node apply bfs ,the two indexes returned .....distance between them is ans.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

vector<pair<ll,ll > > adj[100004];
vector<bool > visited(100005,false);
int dist[100004]={0};

ll bfs(int x,int n)
{
    for(int i=0;i<n+3;i++)
    {
        visited[i]=false;dist[i]=0;
    }
    queue<int > q;
    q.push(x);
    visited[x]=true ;
    while(!q.empty())
    {
        int m=q.front();
       // cout<< m <<" ";
        q.pop();
        for(int j=0;j<adj[m].size();j++)
        {
            if(visited[adj[m][j].first]==false)
            {
                q.push(adj[m][j].first);dist[adj[m][j].first]+=dist[m]+adj[m][j].second;
                visited[adj[m][j].first]=true;
                //cout<<adj[m][j].first<<" <--node level--> "<<dist[adj[m][j].first]<<endl;
            }
        }
    }
  /*  for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }*/
    return int(max_element(dist+1,dist+n+1)-dist);
}

int main()
{
    ll n,e,x,y,t,z,v,ans,c=0,p;
    cin>>t;
    while(t--)
    {              //n=nodes e=edges
    cin>>n;    //entering no. of node and edges
     e=n-1;
    for(int i=1;i<=e;i++)
    {
        cin>>x>>y>>z;              //edges connection
        adj[x].pb(make_pair(y,z));          //undirected graph
        adj[y].pb(make_pair(x,z));
    }

    v=bfs(1,n);//cout<<"v: "<<v<<endl;
    p=bfs(v,n);//cout<<"p: "<<p<<endl;
    ans=dist[p];
    if(ans<100)
        c=0;
    else if(ans>100 && ans<=1000)
        c=100;
    else if(ans>1000 && ans<=10000)
        c=1000;
    else if(ans>10000)
        c=10000;

    cout<<c<<" "<<ans<<endl;
    }
    return 0;
}

