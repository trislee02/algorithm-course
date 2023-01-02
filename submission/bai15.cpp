#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;

#define PI 3.14159265

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

double calcDistance(Point a, Point b) {
	return sqrt(1.0*(a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double calcTriangleArea(double adjacent, double hypo) {
	return 0.5 * adjacent * sqrt(hypo*hypo - adjacent*adjacent);
}

double calcRadius(double adjacent, double hypo) {
	return acos(adjacent / hypo);
}

// O(n)
int approach1() {
    int x1, y1, x2, y2, r;
    double d, rad, triangle, pie, intersection;
    cin >> x1 >> y1 >> x2 >> y2 >> r;
    Point o1 = Point(x1, y1);
    Point o2 = Point(x2, y2);
    
	d = calcDistance(o1, o2);
	rad = calcRadius(d/2, r);
	
	triangle = 2*calcTriangleArea(d/2, r);
	pie = r*r*rad;
	
	intersection = 2*(pie - triangle);
	
	cout << round((2*PI*r*r - intersection) * 1000.0)/1000.0;
}

int main() {
	freopen("input/bai15.in", "r",stdin);
//  freopen("output/bai15.out", "w",stdout);
    
	approach1();
	
	return 0;
}
