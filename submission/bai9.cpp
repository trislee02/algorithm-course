#include <iostream>
#include <vector>
#include <string>
using namespace std;

// O( min(n,m) )
int approach1() {
    string s, p;
    cin >> s >> p;
    int sIdx = 0, pIdx = 0;
    bool isValid = true;
    while (isValid && (sIdx < s.length() || pIdx < p.length())) {
    	if (pIdx == p.length() || sIdx == s.length()) {
    		isValid = false;
    		break;
		}
    	else if (p[pIdx] == '*') {
    		if (s[sIdx] != p[pIdx-1]) 
    			++pIdx;
    		else
    			++sIdx;
		}
		else if (p[pIdx] == '.') {
			++sIdx;
			++pIdx;
		}
		else {
			if (p[pIdx] != s[sIdx]) 
				isValid = false;
			else {
				++sIdx;
				++pIdx;	
			}
		}
	}
	if (isValid) 
		cout << "True";
	else
		cout << "False";
}

int main() {
	freopen("input/bai9.in", "r",stdin);
//    freopen("output/bai9.out", "w",stdout);
    
    approach1();
    
	return 0;
}
