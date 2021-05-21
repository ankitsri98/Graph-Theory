#include<bits/stdc++.h>
using namespace std;

const int N=1e5+4;
const int M=1e9+7;

vector<int > g[N];
bool vis[N];
vector<int > mark;
bool flag;
int khud[N];
int niche[N];
int parent[N];
int nodd;

void dfs(int x,int id){

	vis[x]=true;
	mark.push_back(x);
	if(khud[x]!=id && x!=nodd && khud[x]!=0){
		flag=1;
	}
	if(flag)return;
	for(auto it : g[x]){
		if(!vis[it]){
			dfs(it,id);
		}
	}
}


void dfs2(int x,int id){
	vis[x]=true;
	mark.push_back(x);
	khud[x]=0;
	niche[x]=0;

	for(auto it :g[x]){
		if(!vis[it]){
			dfs2(it,id);
		}
	}
}
void solve(){
	int n,m,Q;
	cin>>n>>m>>Q;
	map<string ,int > ma;

	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		ma[s]=i;
	}
	queue<int > q;
	q.push(1);
	/*int khud[n+1]={0};
	int niche[n+1]={0};
	int parent[n+1]={0};*/
	int pos=2;
	while(pos<=n){
		int par=q.front();
		q.pop();
		for(int i=1;i<=m;i++){
			parent[pos]=par;
			g[par].push_back(pos);
			//g[pos].push_back(par);
			q.push(pos);
			pos++;
		}
	}
	while(Q--){
		int type ,id ;
		string s;
		cin>>type>>s>>id;
		int node=ma[s];
		if(type==1){
			if(khud[node]==0 && niche[node]==0){
				bool flag=0;
				int nn=node;
				while(node!=0){
					if(khud[node]!=0){
						flag=1;
						break;
					}
					node=parent[node];
				}
				if(flag)cout<<"false\n";
				else{
					cout<<"true\n";
					node=nn;
					khud[node]=id;

					while(node!=0){
						niche[node]++;
						node=parent[node];
					}
				}
			}
			else cout<<"false\n";
		}
		else if(type==2){
			if(khud[node]==id){
				cout<<"true\n";
				khud[node]=0;
				while(node!=0){
					niche[node]--;
					node=parent[node];
				}
			}
			else cout<<"false\n";
		}
		else{
			if(khud[node]!=0)cout<<"false\n";
			else{
				int ng=node;
				bool fg=0;
				while(node!=0){
					if(khud[node]!=0){
						fg=1;break;
					}
					node=parent[node];
				}
				if(fg==1){
					cout<<"false\n";
				}
				else{
					node=ng;
				
				flag=0;
				mark.clear();
				nodd=node;
				dfs(node,id);

				for(auto it:mark){
					vis[it]=0;
				}
				mark.clear();

				if(flag){
					cout<<"false\n";
				}
				else{
					cout<<"true\n";
					mark.clear();
					dfs2(node,id);
					khud[node]=id;
					int val=mark.size()-1;

					while(node!=0){
						niche[node]-=val;
						node=parent[node];
					}

					for(auto it : mark){
						vis[it]=0;
					}
					mark.clear();
				}
				}
			}

		}
	}





}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
