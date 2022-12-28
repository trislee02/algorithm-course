#include <iostream>
#include <vector>
#include <map>
using namespace std;

// O(n*n)
int approach1() {
    vector<int> a;
    map<int, int> m;
	int n, tmp, res = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> tmp;
    	a.push_back(tmp);
    	auto x = m.find(tmp);
    	if (x == m.end()) m.insert({ tmp, 0});
	}
	
	for (int i = 0; i < n; ++i) {
		int j = i-1;
		int count = 0;
		while (j >= 0 && a[j] != a[i]) {
			if (a[i] < a[j]) ++count;
			--j;
		}
		auto x = m.find(a[i]);
		x->second += count;
	}

	for (auto itr = m.begin(); itr != m.end(); ++itr) {
        res += itr->second;
    }
    cout << res;
}

int main() {
	freopen("input/bai4.in", "r",stdin);
    freopen("output/bai4.out", "w",stdout);
    
    approach1();
    
	return 0;
}
