// Used to colour all connected components of that initial colour to new colour
// Time complexity -> O(n*m)
// Space complexity -> O(n*m)
// Used to colour all connected components of that initial colour to new colour
// Time complexity -> O(n*m)
// Space complexity -> O(n*m)
#include<bits/stdc++.h>
using namespace std;
void Fun(vector<vector<int>>&grid,int i , int j , int n , int m , int old , int nw,vector<vector<int>>&vis){
	if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] != old || vis[i][j] == 1){
		return;
	}
	grid[i][j]=nw;
	vis[i][j] = 1;
	Fun(grid,i-1,j,n,m,old,nw,vis);
	Fun(grid,i+1,j,n,m,old,nw,vis);
	Fun(grid,i,j-1,n,m,old,nw,vis);
	Fun(grid,i,j+1,n,m,old,nw,vis);

}
int main(){
	int n , m , sr ,sc , nc;
	cin >> n >> m >> sr >> sc >> nc;
	vector<vector<int>>grid(n,vector<int>(m,0));
	vector<vector<int>>vis(n+1,vector<int>(m+1,0));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ;j++){
			cin >> grid[i][j];
		}
	}
	int initial = grid[sr][sc];
	// grid[sr][sc]=nc;
	Fun(grid,sr,sc,n,m,initial,nc,vis);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout << grid[i][j]<<" ";
		}
		cout << endl;
	}

}