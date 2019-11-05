
#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

vector<pair<int, int>> adj[MAX];
vector<int> current_set(MAX);
vector<bool> vis(MAX);

bool dfs(int i, int vl){
    vis[i] = true;
    current_set[i] = vl;//firstly assigning set to each vertex
    
    for(auto ad : adj[i])//for all adjacent in edge EX- A->B
    {
        if( vis[ad.first] )// adjacent i.e B if already visited now comes 2 condition ki unki jo value hai uske acc. vo set me hai ki nhi
        {
            if( ad.second )//for 1 vo same set me nhi hone chahiye means A and B should not be in same set
            {
                if( current_set[i] == current_set[ad.first])
                    return false;
            }else//for 0 vo same set me hi hone chahiye means A and B should be in same set
            {
                if( current_set[i] != current_set[ad.first])
                    return false;
            }
        }
        else if( !dfs(ad.first, (ad.second ? 1 - vl : vl )) )//and if its not visited then yet toh usko visit karwao but in passing in opposite set
        {
            return false;
        }
    }
    return true;                                                                            
}

int main(){

    int t;
    cin >> t;
    while(t--){
        bool can = true;
        int n, q, a, b, c;
        cin >> n >> q;
        for(int i = 0; i <= n; i++)
            adj[i].clear(), vis[i] = false, current_set[i] = -1;
        
        for(int i = 0; i < q; i++){
            cin >> a >> b >> c;
            a--, b--; //zero based indexing of vertices
            if( a == b )//if vertices are same then it cant be 1 as elements should be equal and diagnol can't have any 1
            {
                if( c != 0 )//agar c ki value 1 hai not possible seedha false
                    can = false;
            }else// valid input make a graph with value
            {
                adj[a].push_back({b, c});
                adj[b].push_back({a, c});
            }
        }
        if( can )//in case of valid input
        {
            for(int i = 0; i < n; i++)//dfs called on all components
                if( !vis[i] )
                    can = can && dfs(i, 0);//and is done coz if anyone 1 is false ans is false & dfs(vertex , its present set number i.e 0 or 1)
            
            if( can )
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }else
        {
            cout << "no" << endl;//in case of in valid input
        }
    }
    return 0;
}