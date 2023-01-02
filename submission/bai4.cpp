#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
Nén dãy so lai t 1, 2, 3, ..., M
Ði t? trái sang ph?i, v?i m?i s? a[j]:
=> Ð?m s? lu?ng s? i < j mà a[i] > a[j] b?ng cách ùng segment d?m các s? trong do?n [a[j] + 1, M]
=> Thêm a[j] vào segment tree
*/

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
    	if (x == m.end()) m.insert({ tmp, 0} );
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
