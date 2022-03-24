#include<bits/stdc++.h>
using namespace std;

// Using Dfs
bool bipartiteDfs(int src, vector<int> adj[], int color[]) {
	if(color[src] == -1) color[src] = 1;
	for(auto it:adj[src]) {
		if(color[it] == -1) {
			color[it] = 1 - color[src];
			if(!bipartiteDfs(it, adj, color)) return false;
		} else {
			if(color[it] == color[src])
				return false;
		}
	}
	return true;
}

bool checkBipartite(vector<int> adj[], int n) {
	int color[n];
	memset(color, -1, sizeof color);
	for(int i = 0; i < n; i++) {
		if(!bipartiteDfs(i, adj, color))
			return false;
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	int u, v;
	vector<int> adj[n];
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if(!checkBipartite(adj, n))
		cout << "Not a bipartite..." << endl;
	else 
		cout << "Is a bipartite..." << endl;
	return 0;
}