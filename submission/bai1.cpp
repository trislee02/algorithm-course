#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	while (a*b != 0) 
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

// O(n*k)
int approach1() {
	int n, k, b, maxG = 1;
    vector<int> a;
    
    cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> b;
		a.push_back(b);
		if (i+1 >= k) {
			int g = a[i];
			for (int j = i - k + 1; j <= i - 1; ++j) {
				g = gcd(g, a[j]);
			}
			if (g > maxG) maxG = g;
		}
	}    
	cout << maxG;
}

int main() {
	freopen("input/bai1.in", "r",stdin);
    freopen("output/bai1.out", "w",stdout);
    
    approach1();
    
	return 0;
}
