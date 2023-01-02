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

// 
int approach1() {
	int n, t, tmp, lowest, high, numHigh;
	cin >> n >> t;
	lowest = INT_MAX;
	high = -INT_MAX;
	for (int i = 0; i < n, ++i) {
		cin >> tmp;
		if (tmp < lowest) lowest = tmp;
		if (tmp > high) {
			high = tmp;
			numHigh = 1;	
		}
		if (tmp == high) ++numHigh;
	}
	
	if (high == lowest) numHigh = 0;
	
	while (t > 0) {
		if (numHigh == 0) {
			--lowest;
			numHigh = n-1;
		}
		else 
			--numHigh;
		--t;
	}
	cout << lowest;
}

int main() {
	freopen("input/bai16.in", "r",stdin);
//  freopen("output/bai16.out", "w",stdout);
    
    approach1();
    
	return 0;
}
