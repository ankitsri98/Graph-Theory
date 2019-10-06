#include<bits/stdc++.h>
using namespace std;
#define ll long long


void printbfs(int** edges,int n,int sv,bool* visited)
{
    queue<int > pendingvertices;//QUEUE IS USED SO THAT FOR EVERY VERTEX FIRST ITS CHILD ARE TO BE PRINTED IN ASCENDING ORDER

    pendingvertices.push(sv);//INITIALLY MARKEIT AS VISITED
    visited[sv]=true;
    while(!pendingvertices.empty())//IF QUEUE IS NOT EMPTY
    {
        int currentvertex=pendingvertices.front();//TAIKING OUT THE FIRST EDGE
        pendingvertices.pop();//DELETEING THAT EDGE FROM THE QUEUE
        //cout<<currentvertex<<" ";
        for(int i=0;i<n;i++)//NOW PRINTING ALL ITS ADJACENT ELEMENTS IF NOT VISITED
        {
            if(edges[currentvertex][i]==1 && !visited[i])
            {
                pendingvertices.push(i);
                visited[i]=true;
            }
        }
    }
    
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
    int p=0;
    printbfs(edges,n,0,visited);
    for(int i=0;i<=n;i++)
    {
        
        if(visited[i]==true){//ONLY CHECKING IF ALL THE VERTICES ARE VISITED OR NOT
            p++;
        }   
    }
    if(p==n)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
   

    delete [] visited;
    for(int i=0;i<=n;i++)
    {
        delete [] edges[i];
    }
    delete []edges;
}
