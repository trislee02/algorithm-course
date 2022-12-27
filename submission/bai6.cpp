#include <iostream>
#include <vector>

using namespace std;

#define min(a,b) a < b ? a : b

// O(n*k)
int approach1() {
	int k, tmp, n = 0;
    vector<vector<int>> arrs;
    vector<int> a;
    // Read input
	cin >> k;
    for (int i = 0; i < k; ++i) {
    	vector<int> subArr;
    	char c = ' ';
    	while (c != '\n' && !cin.eof()) {
    		cin >> tmp;
    		subArr.push_back(tmp);
    		n++;
    		cin.get(c);
		}
		arrs.push_back(subArr);
	}
	
	// Merge arrays
	vector<int> indexes(k, 0);
	for (int i = 0; i < n; ++i) {
		int min = INT_MAX;
		int arrIdx;
		for (int j = 0; j < k; ++j) {
			int idx = indexes[j];
			if (idx < arrs[j].size() && min > arrs[j][idx]) {
				min = arrs[j][idx];
				arrIdx = j;
			}
		}
		a.push_back(min);
		indexes[arrIdx]++;
	}
	
	// Output
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
}

int main() {
	freopen("input/bai6.in", "r",stdin);
    freopen("output/bai6.out", "w",stdout);
    
    approach1();
    
	return 0;
}
