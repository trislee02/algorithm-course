#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

int calc(vector<int> a, int max, int left, int right) {
	int res = 0;
	for (int i = left+1; i < right; ++i) 
		res += max - a[i];
	return res;
}

//
int approach2() {
	// Mang left: di tu trai sang phai. left[i] = max ben trai tai diem i
	// Mang right: di tu phai sang trai. right[i] = max ben phai tai diem i
	// Duyet tu 0 den n, muc nuoc tai i = min(left[i], right[i]) - h[i]. 
	// res = tong muc nuoc tai i
	int n, tmp, max = -INT_MAX, i, res = 0;
	vector<int> a;
	vector<int> left, right;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> tmp;
		a.push_back(tmp);
		
		if (tmp > max) max = tmp;
		
		left.push_back(max);
		right.push_back(0);
	}
	
	max = -INT_MAX;
	for (i = n-1; i >= 0; --i) {
		if (max < a[i]) max = a[i];
		right[i] = max;
		res += min(left[i], right[i]) - a[i];
	}
	
	cout << res;
}

// O(n^2)
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
//    freopen("output/bai7.out", "w",stdout);
    
    approach2();
    
	return 0;
}
