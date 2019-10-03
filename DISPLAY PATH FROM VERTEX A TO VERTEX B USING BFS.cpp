#include<bits/stdc++.h>
using namespace std;
#define ll long long

int v1,v2;

map<int ,int >m;
bool printbfs(int** edges,int n,int sv,bool* visited)
{
    queue<int > pendingvertices;//QUEUE IS USED SO THAT FOR EVERY VERTEX FIRST ITS CHILD ARE TO BE PRINTED IN ASCENDING ORDER
    
    pendingvertices.push(sv);//INITIALLY MARKEIT AS VISITED
    visited[sv]=true;
    while(!pendingvertices.empty())//IF QUEUE IS NOT EMPTY
    {
        int currentvertex=pendingvertices.front();//TAIKING OUT THE FIRST EDGE
        pendingvertices.pop();//D;ELETEING THAT EDGE FROM THE QUEUE
        
        for(int i=0;i<n;i++)//NOW PRINTING ALL ITS ADJACENT ELEMENTS IF NOT VISITED
        {
            if(edges[currentvertex][i]==1 && !visited[i])
            {
                //cout<<"all: "<<i<<endl;
                if(i==v2)
                {
                   // cout<<"end: "<<i<<endl;
                    m[i]=currentvertex;//MAP IS TAKEN IN ORDER TO MAINTAIN THE ORIGIN OF A VERTEX
                    visited[i]=true;// I = KEY AND CURRENT VERTEX = VALUE
                    return true;
                }
                m[i]=currentvertex;
                pendingvertices.push(i);//PUSHING IN TO THE QUEUE
                visited[i]=true;
            }
        }
    }
    return false;
}


int main()
{
    int n,e;
    cin>>n>>e;
    int** edges=new int*[n+2];
    for(int i=0;i<=n;i++)
    {
        edges[i]=new int[n+2];
        for(int j=0;j<=n;j++)
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
    bool* visited=new bool[n+2];
    for(int i=0;i<=n;i++)
    {
        visited[i]=false;
    }
    cin>>v1>>v2;
    int i=v2;
    bool x=printbfs(edges,n,v1,visited);
    //CODE FOR PRINTING THE PATH
    if(x==true)
    {
        cout<<i<<" ";
        while(i!=v1)
        {
            i=m[i];
            cout<<i<<" ";
        }
    }

    delete [] visited;
    for(int i=0;i<=n;i++)
    {
        delete [] edges[i];
    }
    delete []edges;
}
