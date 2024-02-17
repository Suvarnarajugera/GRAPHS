#include<bits/stdc++.h>
using namespace std;
void DFS(vector<int>&ans ,vector<int>adj[] , vector<int>&vis , int node){
	vis[node] = 1;
	ans.push_back(node);
	for(auto it : adj[node]){
		if(!vis[it]){
			DFS(ans,adj,vis,it);
		}
	}
}
int main(){
	int n,e;
	cin >> n >> e;
	vector<int>adj[n+1];
	for(int i = 0 ; i < e ; i++){
		int u , v;
		cin >> u >> v ;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int>vis(n+1,0);
	vector<int>ans;
	for(int i = 0 ; i < n ; i++){
		if(!vis[i]){
			DFS(ans,adj,vis,i);
		}
	}
	for(auto it : ans){
		cout << it <<" ";
	}
}