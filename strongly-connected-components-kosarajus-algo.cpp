//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&v,int node){
	    vis[node]=1;
	    for(auto it : adj[node]){
	        if(!vis[it]){
	            dfs(adj,vis,v,it);
	        }
	    }
	    v.push_back(node);
	}
	void fun(vector<int>adj[],vector<int>&vis,int node){
	    vis[node]=1;
	    for(auto it : adj[node]){
	        if(!vis[it]){
	            fun(adj,vis,it);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>&adj){
        //code here
        vector<int>vis(V+1,0);
        vector<int>v;
        vector<int>adj1[V];
        for(int i = 0; i < V; i++){
            for(int j = 0; j < adj[i].size(); j++){
                adj1[adj[i][j]].push_back(i);
            }
        }
      
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(adj,vis,v,i);
            }
        }
        int cnt = 0;
        reverse(v.begin(),v.end());
        vector<int>vis1(V+1,0);
        for(int i = 0 ; i < V ; i++){
            if(!vis1[v[i]]){
                fun(adj1,vis1,v[i]);
                cnt ++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends