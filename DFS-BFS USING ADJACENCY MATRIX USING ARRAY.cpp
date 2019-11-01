#include<bits/stdc++.h>
using namespace std;
#define ll long long

void print(int** edges,int n,int sv,bool* visited)// DFS
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv)
        continue;
        if(edges[sv][i]==1)
           {
               if(visited[i])
                {
                continue;
                }
               print(edges,n,i,visited);
           }
    }
}

void printbfs(int** edges,int n,int sv)// BFS
{
    queue<int > pendingvertices;
    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    pendingvertices.push(sv);
    visited[sv]=true;
    while(!pendingvertices.empty())
    {
        int currentvertex=pendingvertices.front();
        pendingvertices.pop();
        cout<<currentvertex<<endl;
        for(int i=0;i<n;i++)
        {
            if(edges[currentvertex][i]==1 && !visited[i])
            {
                pendingvertices.push(i);
                visited[i]=true;
            }
        }
    }
    delete [] visited;
}
int main()
{
    int n,e;
    cin>>n>>e;
    int** edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    cout<<"DFS"<<endl;
    print(edges,n,0,visited);
    cout<<"BFS"<<endl;
    printbfs(edges,n,0);

    delete [] visited;
    for(int i=0;i<n;i++)
    {
        delete [] edges[i];
    }
    delete []edges;
}
