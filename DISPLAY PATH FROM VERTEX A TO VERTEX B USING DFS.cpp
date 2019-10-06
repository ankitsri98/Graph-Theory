#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int > smallout;
//PROBLEM IS TO FIND PATH FROM VERTEX A TO VERTEX B USING DFS
//AND NEED TO RETURN VECTOR
vector<int > getpath(int** edges,int n,int sv,int ev,bool* visited)
{
    if(sv==ev)//THIS IS BASE CONDITION FOR RETURNING THE LAST VERTEX OF THE PATH
    {
        vector<int > output;
        output.push_back(ev);//PUSH IT AND RETURN THE VECTOR OUTPUT
        return output;
    }
    visited[sv]=true;  //MARK IT AS VISITED
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1 && visited[i]==false)//WHENEVER THE CONDITON SATIFIES CALL THE FUNCTION
        {
            smallout=getpath(edges,n,i,ev,visited);
            if(smallout.size()>0)//NOW THIS IS CALC. AFTER RETURNING THE RECURSIVE CALL 
            {
                smallout.push_back(sv);//PUSH THE SOURCE OF THE VERTEX
                return smallout;//KEEP RETURNING THE VERTEX 
            }
        }
    }
    vector<int> noAns;
    return noAns;//    return empty vector IN THE END 
}
int main()
{
    int n,e,v1,v2;
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

    vector<int > v=getpath(edges,n,v1,v2,visited);
    //CODE FOR PRINTING THE PATH
    if(v.size()!=0)
    {
        for(auto i :v)
        {
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

