#include<bits/stdc++.h>
using namespace std;
void DFS(vector<int>adj[],vector<int>&vis , int node){
	cout << node <<" ";
	vis[node] = 1;
	for(auto it : adj[node]){
		if(!vis[it]){
			DFS(adj,vis,it);
		}
	}
}
void BFS(vector<int>adj[],vector<int>&vis , int node){
	queue<int>q;
	q.push(node);
	vis[node]=1;
	while(!q.empty()){
		int top = q.front();
		cout << top <<" ";
		q.pop();
		for(auto it : adj[top]){
			if(!vis[it]){
				q.push(it);
				vis[it]=1;
			}
		}
	}
}
int main(){
	int n , e ;
	cin >> n >> e;
	vector<int>adj[n+1];
	for(int i = 0 ; i < n ;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	vector<int>vis(n+1,0);
	vis[0] = 1;
	for(int i = 0 ; i <= n ; i++){
		if(!vis[i]){
			// DFS(adj,vis,i);
			BFS(adj,vis,i);
		}
	}
	// DFS(adj,vis,1);
	// BFS(adj,vis,1);
}