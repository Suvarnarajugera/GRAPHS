#include<bits/stdc++.h>
using namespace std;
class disjoint{
	vector<int>par,rank;
public:
	disjoint(int n){
		rank.resize(n+1,0);
		par.resize(n+1);
		for(int i = 0; i <= n ;i++){
			par[i]=i;
		}
	}
	// Find ultimate parent
	int find_par(int node){
		if(node == par[node]){
			return node;
		}
		return par[node] = find_par(par[node]);
	}
	// making path compression to solve it in O(1)-->constant time
	void unionfind(int u , int v){
		int u_p = find_par(u);
		int v_p = find_par(v);
		if(rank[u_p] > rank[v_p]){
			par[v_p] = u_p;
		}
		else if(rank[v_p] > rank[u_p]){
			par[u_p] = v_p;
		}
		else{
			par[v_p] = u_p;
			rank[u_p]++;
		}
	}
};
int main(){
	disjoint ds(7);
	ds.unionfind(1,2);
	ds.unionfind(2,3);
	ds.unionfind(4,5);
	ds.unionfind(6,7);
	ds.unionfind(5,6);
	if(ds.find_par(3) == ds.find_par(7)){
		cout << "same "<< endl;
	}
	else{
		cout <<"not same"<<endl;
	}
	ds.unionfind(3,7);
	if(ds.find_par(3) == ds.find_par(7)){
		cout << "same "<< endl;
	}
}