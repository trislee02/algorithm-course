#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;

unsigned int _try(unsigned int factor, unsigned int m, int n) {
	if (factor == 0) {
		if (m > 0 && m % n == 0) {
			return m;
		}
		return -1;
	} else {
		unsigned int x = _try(factor/10, m, n);
		if (x == -1) {
			return _try(factor/10, factor + m, n);
		}
		return x;
	}
}

// O(n)
int approach1() {
    int n;
    unsigned int m = 0;
    cin >> n;
    cout << _try(100000000, m, n);
}

int main() {
	freopen("input/bai17.in", "r",stdin);
//  freopen("output/bai17.out", "w",stdout);
    
	approach1();
	
	return 0;
}
