#include<bits/stdc++.h>
using namespace std;


// Using Bfs
bool bipartiteBfs(int node, vector<int> adj[], int color[]) {
	queue<int> q;
	q.push(node);
	color[node] = 1;
	while(!q.empty()) {
		int f = q.front();
		q.pop();
		for(auto it:adj[f]) {
			if(color[it] == -1) {
				color[it] = 1 - color[f];
				q.push(it);
			} else {
				if(color[it] == color[f])
					return false;
			}
		}
	}
	return true;
}

bool checkBipartite(vector<int> adj[], int n) {
	int color[n];
	memset(color, -1, sizeof color);
	for(int i = 0; i < n; i++) {
		if(color[i] == -1) {
			if(!bipartiteBfs(i, adj, color))
				return false;
		}
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