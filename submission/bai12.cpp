#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;

#define min(a, b) a < b ? a : b

void swap(vector<int>& a, int pa, int pb) {
	int tmp = a[pa];
	a[pa] = a[pb];
	a[pb] = tmp;
}

void quicksort(vector<int>& a, vector<int>& cluster, vector<int>& group, int start, int end) {
	if (start >= end) return;
	int pivot = a[start];
	int left = start + 1, right = end;
	while (left < right) {
		while (left <= end && a[left] >= pivot) ++left;
		while (right >= 0 && a[right] <= pivot) --right;
		swap(a, left, right);
		swap(cluster, left, right);
		swap(group, left, right);
	}
	swap(a, left, right);
	swap(cluster, left, right);
	swap(group, left, right);
	swap(a, right, start);	
	swap(cluster, right, start);	
	swap(group, right, start);	
	
	quicksort(a, cluster, group, start, right -1);
	quicksort(a, cluster, group, right + 1, end);
}

bool isSquareNum(int n) {
	int t = sqrt(n);
	return t * t == n;
}

// O(n)
int approach1() {
    int n, a, b;
    cin >> n;	 
    			  //i*i < (n*n)/2
    for (int i = 1; i < n/sqrt(2); ++i) {
    	if (isSquareNum(n*n - i*i)) {
    		a = i;
    		b = sqrt(n*n - i*i);
    		cout << 0 << " " << b << endl;
    		cout << a << " " << 0 << endl;    		
    		cout << a+b << " " << a << endl;
    		cout << b << " " << a+b << endl;
    		return 0;
		}
    		
	}
	cout << "IMPOSSIBLE";
}

int main() {
	freopen("input/bai12.in", "r",stdin);
//  freopen("output/bai12.out", "w",stdout);
    
    approach1();
    
	return 0;
}
