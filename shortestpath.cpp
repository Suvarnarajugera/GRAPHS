#include<bits/stdc++.h>
using namespace std;
void Fun(vector<int>adj[],int node,vector<int>&vis){
    queue<pair<int,int>>q;
    vector<int>ans;
    q.push({node,0});
    while(!q.empty()){
        pair<int,int>top = q.front();
        cout << top.first <<" " << top.second <<" "<<endl;
        q.pop();
        for(auto it : adj[top.first]){
            if(!vis[it]){
                q.push({it,top.second+1});
                vis[it] = 1;
            }
        }
    }
}
int main(){
    int n , e ;
    cin >> n >> e;
    vector<int>adj[n+1];
    for(int i = 0 ; i < e ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n,0);
    vis[1] = 1;
    Fun(adj,1,vis);
}