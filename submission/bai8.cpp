#include <iostream>
#include <vector>
#include <string>
using namespace std;

void _try1(int n, int q, vector<int>& pos, vector<bool>& avaiCol, vector<bool>& avaiLeftDiag, vector<bool>& avaiRightDiag, vector<vector<int>>& res) {
	// Output
	if (q == n) {
		res.push_back(pos);
	} else {
		for (int i = 0; i < n; ++i) {
			if (avaiCol[i] && avaiLeftDiag[i + q] && avaiRightDiag[i - q + n-1]) {
				pos[q] = i;
				avaiCol[i] = false;
				avaiLeftDiag[i + q] = false;
				avaiRightDiag[i - q + n-1] = false;
				_try1(n, q+1, pos, avaiCol, avaiLeftDiag, avaiRightDiag, res);
				avaiCol[i] = true;
				avaiLeftDiag[i + q] = true;
				avaiRightDiag[i - q + n-1] = true;
			}
		}
	}
	
}

// O(n*n)
int approach1() {
    int n;
	cin >> n;
    vector<bool> avaiCol(n, true), avaiLeftDiag(n*2-1, true), avaiRightDiag(n*2-1, true);
    vector<int> pos(n, 0);
    vector<vector<int>> res;
    _try1(n, 0, pos, avaiCol, avaiLeftDiag, avaiRightDiag, res);
    cout << res.size() << endl;
	for (int r = 0; r < res.size(); ++r) {
		vector<int> p = res[r];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j != p[i])
					cout << '.';
				else
					cout << 'Q';
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main() {
	freopen("input/bai8.in", "r",stdin);
//    freopen("output/bai8.out", "w",stdout);
    
    approach1();
    
	return 0;
}
