#include<bits/stdc++.h>
using namespace std;
#define  ll long long int

//BIPARTITE GRAPH:- 1. ODD CYCLE GRAPH CAN NEVER BE  BIPARTITE 2.IF THERE ARE 2 SETS THEN THERE SHOULD NOT BE ANY EDGE BETWEEN PARTICULAR SET.

bool bipartite(vector<int >* edges, int n)
{
    if(n==0)
        return true;
    unordered_set<int> sets[2];//FORMING 2 SETS
    vector<int > pending;
    sets[0].insert(0);//INITIALLY PUTING 0
    pending.push_back(0);
    while(pending.size()!=0)
    {
        int current=pending.back();//VECTOR WORKING AS STACK
        pending.pop_back();
        int currentset=sets[0].count(current)>0?0:1;//sets[0].count(current)==0 MEANS current is not present in set 0 ELSE IT IS PRESENT
        for(int i=0;i<edges[current].size();i++)//FOR ALL ADJACENT NEIGHBORS
        {
            int neighbor=edges[current][i];
            if(sets[0].count(neighbor)==0 && sets[1].count(neighbor)==0)
            {
                sets[1-currentset].insert(neighbor);
                pending.push_back(neighbor);
            }
            else if(sets[currentset].count(neighbor)>0)//REMEMBER 2 COND. FOR BIPARTITE
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)
        break;
        vector<int >* edges =new vector<int >[n];//ARRAY OF VECTOR IS MADE IN ORDER TO STORE COMPONENTS ..;LOOK ITAS A 2D MATRIX
        int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int j,k;
            cin>>j>>k;
            edges[j].push_back(k);//MAINTAINING EDGES
            edges[k].push_back(j);
        }
        bool ans=bipartite(edges,n);
        if(ans)
            cout<<"BICOLOURABLE."<<endl;
        else
            cout<<"NOT BICOLOURABLE."<<endl;
        delete [] edges;
    }
}
