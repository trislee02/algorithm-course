#include <iostream>
#include <vector>
#include <string>
using namespace std;

// O(n*n)
int approach1() {
    string a, b;
    cin >> a >> b;
    int nA = a.length(), nB = b.length();
    if (nA < nB) {
    	cout << "";
		return 0;	
	}
    for (int i = 0; i <= nA - nB; ++i) {
    	if (a[i] == b[0] && a[i+nB-1] == b[nB-1]) {
    		int j = 0;
			for (; j < nB; ++j) {
    			if (a[i+j] != b[j]) break;
			}
			if (j == nB) cout << i << " ";
		}
	}
}

int main() {
	freopen("input/bai5.in", "r",stdin);
//    freopen("output/bai5.out", "w",stdout);
    
    approach1();
    
	return 0;
}
