#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;

#define min(a, b) a < b ? a : b

struct Point
{
    int x;
    int y;
    
	Point (int x, int y) {
        this->x = x;
        this->y = y;
    }
    
    bool operator==(const Point& p) const
    {
        return x == p.x && y == p.y;
    }

    bool operator!=(const Point& p) const
    {
        return !(*this == p);
    }
};

double slope(Point p1, Point p2)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;

    if (dx == 0) { 
        return INT_MAX;
    }

    return dy/(dx);
}



// O(n)
int approach1() {
    int n, a, b;
    cin >> n;	 
    
	cout << "IMPOSSIBLE";
}

int main() {
	freopen("input/bai13.in", "r",stdin);
//  freopen("output/bai13.out", "w",stdout);
    
	double param, result;
	param = INT_MAX;
	result = atan(param) * 180 / PI;
	
	cout << result;
	
	return 0;
}
