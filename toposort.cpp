// it is for Direct acyclic graph
// time complextiy -> O(V*E)
// Space complextiy -> O(V*E)
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , e;
	cin >> n >> e;
	vector<int>adj[n];
	for(int i = 0 ; i < n ;i++){
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	queue<int> q; 
    vector<int> in(n, 0); 
    for(int i = 0;i<n;i++) {
        for(auto it: adj[i]) {
            in[it]++; 
        }
    }
    
    for(int i = 0;i<n;i++) {
        if(in[i] == 0) {
            q.push(i); 
        }
    }
    vector<int> ans;
    while(!q.empty()) {
        int node = q.front(); 
        q.pop(); 
        ans.push_back(node);
        for(auto it : adj[node]) {
            in[it]--;
            if(in[it] == 0) {
                q.push(it); 
            }
        }
    }
    for(auto it : ans)cout << it<<" ";
}