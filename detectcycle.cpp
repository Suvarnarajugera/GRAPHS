#include<bits/stdc++.h>
using namespace std;
bool Fun(vector<int>adj[],vector<int>&vis,int node){
	vis[node] = 1;
	queue<pair<int,int>>q;
	q.push({node,-1});
	while(!q.empty()){
		auto top = q.front();
		int nd = top.first;
		int parent = top.second;
		// cout << top <<" ";
		q.pop();
		for(auto it : adj[nd]){
			if(!vis[it]){
				q.push({it,nd});
				vis[it] = 1;
			}
			else if(parent != it){
				return true;
			}
		}
	}
	return false;
}
int main(){
	int n , e;
	cin >> n >> e ;
	vector<int>adj[n+1];
	for(int i = 0 ; i < n ; i++){
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int>vis(n+1,0);
	// vis[0] = 1;
	for(int i = 0 ; i < n ; i++){
		if(!vis[i]){
			if(Fun(adj,vis,i)){
				cout << 1 << endl;
				break;
			}
		}
	}
	cout << 0 << endl;
}