#include<bits/stdc++.h>
using namespace std;
#define  ll long long int

void dfs(vector<int>* edges, int start,unordered_set<int > &visited , stack<int> &finishstack)//FOR MAINTAING STACK
{
    visited.insert(start);
    for(int i=0;i<edges[start].size();i++)
    {
        int next=edges[start][i];// IMAGINE IT AS A ROW IN MATRIX ACESSING IT
        if(visited.count(next)==0)
        {
            dfs(edges, next,visited,finishstack);
        }
    }
    finishstack.push(start);//PUSHING WHILE RETURNING MEANS WHEN NEXT VERTEX IS  ALREADY VISITED
}

void dfs2(vector<int>* edgest, int start,unordered_set<int >* component , unordered_set<int > &visited)//& VISITED USED SO THAT TOO MANY COPIES SHOULD NOT BE FORMED
{
    visited.insert(start);
    component->insert(start);//FILLING OF COMPONENTS DONE HERE WILL BE REFLECTED IN GET COMPONENTS FUNCTION
    for(int i=0;i<edgest[start].size();i++)
    {
        int next=edgest[start][i];// IMAGINE IT AS A ROW IN MATRIX ACESSING IT
        if(visited.count(next)==0)
        {
            dfs2(edgest, next,component,visited);//REFLECT BACK THE COMPONENTSBACK TO SSC FUNC.
        }
    }
}
unordered_set< unordered_set<int >*>* getssc(vector<int >* edges,vector<int >* edgest,int n)
{
    unordered_set<int> visited;
    stack<int  > finishedvertices;
    for(int i=0;i<n;i++)
    {
        if(visited.count(i)==0)
            dfs(edges,i,visited,finishedvertices);
    }
    //TILL NOW STACK GOT FILLED FOR EACH component

    unordered_set< unordered_set<int >*>* output= new unordered_set< unordered_set<int >*>();
    visited.clear();
    while(finishedvertices.size()!=0)
    {
        int element=finishedvertices.top();//START DFS FROM TOP ELEMENT OF STACK
        finishedvertices.pop();
        if(visited.count(element)!=0)
            continue;
        unordered_set<int>* component=new unordered_set<int>();//START GATHERING COMPONENTS
        dfs2(edges,element, component,visited);
        output->insert(component);
    }
    return output;
}
int main()
{
    int n;
    cin>>n;
    vector<int >* edges =new vector<int >[n];//ARRAY OF VECTOR IS MADE IN ORDER TO STORE COMPONENTS ..;LOOK ITAS A 2D MATRIX
    vector<int >* edgest=new vector<int >[n];//FOR MAINTAINING TRANSPOSE GRAPH
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int j,k;
        cin>>j>>k;
        edges[j-1].push_back(k-1);//MAINTAINING EDGES
        edgest[k-1].push_back(j-1);
    }
    unordered_set< unordered_set<int >*>* components= getssc(edges,edgest,n);// SET OF SET IS A RRETURN TYPE AND GET COMPONENTS  IS A FUNCTION TO RETURN IT

    //PRINTING OF EACH ELEMENT OF EACH COMPONENTS STARTS BELOW
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
    delete [] edgest;
}
