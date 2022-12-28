#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define min(a, b) a < b ? a : b

// O(n*n)
int approach1() {
    int m, n, tmp, max = 0;
    vector<vector<int>> a;
    vector<vector<int>> f;
	cin >> m >> n;
    for (int i = 0; i < m; ++i) {
    	vector<int> atmp;
    	vector<int> ftmp;
		for (int j = 0; j < n; ++j) {
    		cin >> tmp;
    		atmp.push_back(tmp);
			ftmp.push_back(1);			
		}
		a.push_back(atmp);
		f.push_back(ftmp);
	}
	
	// Initialization
	// f(1, j) = f(i, 1) = 1 for all j = 1..n, i = 1..m
	
	// f(i,j) = min( f(i-1,j), f(i,j-1) ) + 1 if a(i,j) = a(i-1,j) = a(i,j-1) = a(i-1,j-1)
    // f(i,j) = 1 if else
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (a[i][j] == a[i-1][j] && a[i-1][j] == a[i][j-1] && a[i][j-1] == a[i-1][j-1]) {
				f[i][j] = min(f[i-1][j], f[i][j-1]) + 1;
			}
			else {
				f[i][j] = 1;
			}
			if (f[i][j] > max) max = f[i][j];
		}
	}    
	cout << max * max;
}

int main() {
	freopen("input/bai10.in", "r",stdin);
//    freopen("output/bai10.out", "w",stdout);
    
    approach1();
    
	return 0;
}
