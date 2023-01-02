#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i <= n / 2; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

set<int> initPrimeTable(int n) {
	set<int> primes;
	for (int i = 2; i <= n; ++i) {
		if (isPrime(i)) primes.insert(i);
	}
	return primes;
}

// O(n*k)
int approach1() {
	int n, fn = 0;
	set<int> primes;
	cin >> n;
	vector<int> g(n-1, 0);
	primes = initPrimeTable(n * 2);
	
	for (int i = 2; i <= n; ++i) {
		int s = i * 2;
		for (set<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
			if (*it > s / 2) break;
			if (primes.find(s - *it) != primes.end()) {
				g[i-2]++;	
			}
		}
	}
	
	for (int i = 0; i < n-1; ++i) 
		fn += g[i];
	cout << fn;
}

int main() {
	freopen("input/bai2.in", "r",stdin);
    freopen("output/bai2.out", "w",stdout);
    
    approach1();
    
	return 0;
}
