#include<bits/stdc++.h>
using namespace std;
#define  ll long long int

void dfs(vector<int>* edges, int start,unordered_set<int >* component , bool* visited)
{
    visited[start]=true;
    component->insert(start);//FILLING OF COMPONENTS DONE HERE WILL BE REFLECTED IN GET COMPONENTS FUNCTION
    for(int i=0;i<edges[start].size();i++)
    {
        int next=edges[start][i];// IMAGINE IT AS A ROW IN MATRIX ACESSING IT
        if(!visited[next])
        {
            dfs(edges, next, component,visited);
        }
    }
}

unordered_set< unordered_set<int >*>* getcomponents(vector<int >* edges,int n)
{
    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    unordered_set< unordered_set<int >*>* output= new unordered_set< unordered_set<int >*>();
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            unordered_set<int >* component=new unordered_set<int >();
            dfs(edges,i,component,visited);//RETURN A COMPONENTS
            output->insert(component);//INSERTING A COMPONENTS USING ARROW COZ ITS MADE USING *
        }
    }
    delete [] visited;
    return output;
}
int main()
{
    int n;
    cin>>n;
    vector<int >* edges =new vector<int >[n];//ARRAY OF VECTOR IS MADE IN ORDER TO STORE COMPONENTS ..;LOOK ITAS A 2D MATRIX
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int j,k;
        cin>>j>>k;
        edges[j-1].push_back(k-1);//MAINTAINING EDGES
        edges[k-1].push_back(j-1);
    }
    unordered_set< unordered_set<int >*>* components= getcomponents(edges,n);// SET OF SET IS A RRETURN TYPE AND GET COMPONENTS  IS A FUNCTION TO RETURN IT
    unordered_set< unordered_set<int >*> :: iterator it1 =components->begin();
    while(it1!=components->end())
    {
        unordered_set<int>* component= *it1;//ONE SET IS MADE TO EXTRACT COMPONENTS ONE BY ONE
        unordered_set<int > :: iterator it2 = component->begin();
        while(it2!=component->end())//PRINT ITS CONTENTS
        {
            cout<<*it2 +1 <<" ";
            it2++;
        }
        cout<<endl;
        delete component;
        it1++;
    }
    delete components;
    delete [] edges;
}



