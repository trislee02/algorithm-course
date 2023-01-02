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


double calcArea(vector<Point> points, int start, int end) {
	double a = 0;
	for (int i = start; i < end; ++i) {
		a += (points[i+1].x - points[i].x)*(points[i+1].y + points[i].y);
	}
	a += (points[start].x - points[end].x) * (points[start].y + points[end].y);
	return -a * 0.5;
}

double calcTriangleArea(Point a, Point b, Point c) {
	return -0.5 * ((b.x - a.x)*(b.y + a.y) + (c.x - b.x)*(c.y + b.y) + (a.x - c.x)*(a.y + c.y));
}

// O(n)
int approach1() {
    int n, x, y, p1, p2;
    double sij, s, areaDiff, min = INT_MAX;
    vector<Point> points;
    cin >> n;
	
	if (n < 4) return 1;
		 
    for (int i = 0; i < n; ++i) {
    	cin >> x >> y;
    	points.push_back(Point(x, y));
	}
	
	s = calcArea(points, 0, points.size()-1);

	for (int i = 0; i < n; ++i) {
		sij = 0;
		for (int j = 2; j < n-1; ++j) {
			sij += calcTriangleArea(points[i], points[(i+j-1) % n], points[(i+j) % n]);
			areaDiff = abs(2*sij - s);
			if (areaDiff < min) {
				min = areaDiff;
				p1 = i;
				p2 = i+j;
			}
		}
		
	}
	
	cout << p1+1 << " " << p2+1;
}

int main() {
	freopen("input/bai14.in", "r",stdin);
//  freopen("output/bai14.out", "w",stdout);
    
	approach1();
	
	return 0;
}
