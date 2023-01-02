#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) a < b ? a : b

int abs(int a) {
	return a >= 0 ? a : -a;
}

int upperBound(vector<int> a, int left, int right, int x) {
	
	while (left < right) {
		int mid = (left + right) / 2;
		if (a[mid] <= x) 
			left = mid + 1; 
		else
			right = mid;
	}
		
	return left;
}

void swap(vector<int>& a, int pa, int pb) {
	int tmp = a[pa];
	a[pa] = a[pb];
	a[pb] = tmp;
}

void quicksort(vector<int>& a, vector<int>& pos, int start, int end) {
	if (start >= end) return;
	
	int p = a[end];
	int low = -1;
	for (int i = 0; i < end; ++i) {
		if (a[i] < p) {
			++low;
			swap(a, low, i);
			swap(pos, low, i);
		}
	}
	swap(a, end, ++low);
	swap(pos, end, low);
	
	quicksort(a, pos, start, low-1);
	quicksort(a, pos, low+1, end);
}

int approach2() {
	/*
		Voi moi a[i], tìm so b[j] gan -a[i] nhat 
		- TH1: b[j] >= -a[i]
		- TH2: b[j] < -a[i]
		
		Cách 1: 
			Sort mang b tang dan, Chat nhi phân tìm lowerbound TH1, upperbound TH2
		Cách 2:
			Tao mang c[i] = -a[i]
			Gom ca mang c và mang b vào sort lai tang dan thành mang d, nhu vay voi moi so c[i] (tuc là -a[i])
			=> so nho nhat >= c[i] là so b dau tiên nam sau nó
			=> so lon nhat <= c[i] là so b cuoi cùng nam truoc nó
	*/
	int min = INT_MAX;
	int n, m, tmp, tmp2, apos, bpos, p;
    vector<int> a, b, posArrB;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
    	cin >> tmp;
    	a.push_back(tmp);
	}
	for (int i = 0; i < n; ++i) {
    	cin >> tmp;
    	b.push_back(tmp);
    	posArrB.push_back(i);
	}
	
	quicksort(b, posArrB, 0, b.size()-1);
		
	for (int i = 0; i < m; ++i) {
		p = upperBound(b, 0, b.size()-1, -a[i]);
		tmp = abs(a[i] + b[p]);
		if (p > 0) {
			tmp2 = abs(a[i] + b[p-1]);	
			if (tmp2 < tmp) {
				p = p - 1;
				tmp = tmp2;	
			}
		}
		if (tmp < min) {
			min = tmp;
			apos = i;
			bpos = posArrB[p];
		}
	}
	
	cout << min << " " << apos+1 << " " << bpos+1;
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
//    freopen("output/bai3.out", "w",stdout);
    
    approach2();
    
	return 0;
}
