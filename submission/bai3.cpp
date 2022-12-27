#include <iostream>
#include <vector>

using namespace std;

int abs(int a) {
	return a >= 0 ? a : -a;
}

// O(n*n)
int approach1() {
	int min = INT_MAX;
	int n, m, tmp, apos, bpos;
    vector<int> a, b;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
    	cin >> tmp;
    	a.push_back(tmp);
	}
	for (int i = 0; i < n; ++i) {
    	cin >> tmp;
    	b.push_back(tmp);
	}
	
	for (int i = 0; i < m; ++i)  {
		for (int j = 0; j < n; ++j) {
			tmp = abs(a[i] + b[j]);
			if (tmp < min) {
				min = tmp;
				apos = i;
				bpos = j;
			}
		}
	}
	
	cout << apos+1 << " " << bpos+1;
}

int main() {
	freopen("input/bai3.in", "r",stdin);
    freopen("output/bai3.out", "w",stdout);
    
    approach1();
    
	return 0;
}
