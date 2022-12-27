#include <iostream>
#include <vector>

using namespace std;

#define min(a,b) a < b ? a : b

int calc(vector<int> a, int max, int left, int right) {
	int res = 0;
	for (int i = left+1; i < right; ++i) 
		res += max - a[i];
	return res;
}

// O(n*k)
int approach1() {
	int n, slope = 1, tmp, left, right, i, res = 0;
	vector<int> a;
	vector<int> peaks;
	cin >> n;
	a.push_back(0);
	for (i = 0; i < n; ++i) {
		cin >> tmp;
		a.push_back(tmp);
	}
	a.push_back(0);
	
	for (i = 1; i <= n+1; ++i) {
		if ((a[i] - a[i-1]) * slope < 0) {
			if (slope > 0) peaks.push_back(i-1);
			slope *= -1;
		}
	}
	
	left = 0;
	while (left < peaks.size() - 1) {
		int rightMax = left + 1;
		for (right = left + 1; right < peaks.size(); ++right) {
			if (a[peaks[right]] > a[peaks[rightMax]])
				rightMax = right;
			if (a[peaks[rightMax]] > a[peaks[left]]) 
				break;
		}
		res += calc(a, min(a[peaks[left]], a[peaks[rightMax]]), peaks[left], peaks[rightMax]);
		left = rightMax;
	}	
	cout << res;
	return res;
}

int main() {
	freopen("input/bai7.in", "r",stdin);
    freopen("output/bai7.out", "w",stdout);
    
    approach1();
    
	return 0;
}
