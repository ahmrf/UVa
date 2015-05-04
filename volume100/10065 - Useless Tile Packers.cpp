#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct Point
{
	double x, y;
};
Point points[1000], convex[1000];

bool compare(Point p, Point q)
{
	if(p.x != q.x) return p.x < q.x;
	return p.y < q.y;
}

double turn(Point o, Point a, Point b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double get_area(Point p[], int n)
{
	double area = 0;
	for(int i = 0; i < n; i++)
	{
		area += p[i].x*p[i+1].y - p[i].y * p[i+1].x;
	}
	return fabs(area)/2.0;
}

int find_hull(int n)
{
	sort(points, points+n, compare);
	int m = 0;
	for(int i = 0; i < n; i++)
	{
		while(m >= 2 && turn(convex[m-2], convex[m-1], points[i]) <= 0)
		{
			m--;
		}
		convex[m++] = points[i];
	}

	for(int i = n-1, t = m+1; i >= 0; i--)
	{
		while(m >= t && turn(convex[m-2], convex[m-1], points[i]) <= 0)
		{
			m--;
		}
		convex[m++] = points[i];
	}

	return m;
}

int main()
{
	int n, c = 1;
	
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%lf %lf", &points[i].x, &points[i].y);
		}

		points[n] = points[0];
		double tile = get_area(points, n);

		int m = find_hull(n);

		double cont = get_area(convex, m-1);
		

		printf("Tile #%d\n", c++);
        printf("Wasted Space = %.2lf %%\n\n", (cont-tile)*100/cont);
	}

	return 0;
}