#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

#define min(a, b) a < b ? a : b

struct Point
{
    int x;
    int y;
    
    Point() {
        this->x = 0;
        this->y = 0;
    }
    
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

struct PointInfo {
	Point point;
	double slope;
	int position;
	
	PointInfo (Point p, double s, int pos) {
        this->point = p;
        this->slope = s;
        this->position = pos;
    }
};

bool comparePointInfo (PointInfo i, PointInfo j) { return (i.slope < j.slope); }

// O(n)
int approach1() {
    int n, x, y, leftPoint = 0;
    vector<Point> points;
    vector<PointInfo> data;
    cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		points.push_back(Point(x, y));
	}
	
	// Find the left (bottom) point
	for (int i = 1; i < n; ++i) {
		if (points[i].x < points[leftPoint].x) {
            leftPoint = i;
        } else if (points[i].x == points[leftPoint].x) {
            if (points[i].y < points[leftPoint].y) {
                leftPoint = i;
            }
        }
	}
	
	// Calculate slopes
	for (int i = 0; i < n; ++i) {
		if (i != leftPoint) {
			double s = slope(points[i], points[leftPoint]);
			data.push_back(PointInfo(points[i], s, i));
		}
	}
	
	
	sort(data.begin(), data.end(), comparePointInfo);
	
	cout << leftPoint+1 << " " << data[data.size()/2].position+1;
}

int main() {
	freopen("input/bai13.in", "r",stdin);
//  freopen("output/bai13.out", "w",stdout);
    
	approach1();
	
	return 0;
}
