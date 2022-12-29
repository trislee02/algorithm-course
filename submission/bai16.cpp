#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;

#define min(a, b) a < b ? a : b

// dfs and memorise results along the path
int pathLen(vector<vector<int>>& a, vector<vector<int>>& f, int src, int des, vector<bool>& visited) {
	if (f[src][des] > 0) return f[src][des];
	int res = -1;
	visited[src] = true;
	for (int i = 0; i < a[src].size(); ++i) {
		if (visited[a[src][i]]) continue;
		int neighbor = a[src][i];
		int l = pathLen(a, f, neighbor, des, visited);
		if (l > 0) {
			f[src][des] = l + 1;
			res = l + 1;	
			break;
		}
	}
	visited[src] = false;
	return res;
}

// O(n) with n = tree width
int approach1() {
    int n, node1, node2, res = 0;
    cin >> n;
	vector<vector<int>> a(n);
	vector<vector<int>> f(n);
	vector<bool> visited(n, false);
	
	// f[i][j] = path length between node i and node j (i < j)
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) f[i].push_back(0);

	for (int i = 0; i < n-1; ++i) {
    	cin >> node1 >> node2;
    	a[node1-1].push_back(node2-1);
    	a[node2-1].push_back(node1-1);
    	f[node1-1][node2-1] = 1;
    	f[node2-1][node1-1] = 1;
	}
	
	for (int i = 0; i < n-1; ++i) {
		for (int j = i+1; j < n; ++j) {
			res += pathLen(a, f, i, j, visited);
		}
	}
	
	cout << res;
}

int main() {
	freopen("input/bai16.in", "r",stdin);
//  freopen("output/bai16.out", "w",stdout);
    
    approach1();
    
	return 0;
}
