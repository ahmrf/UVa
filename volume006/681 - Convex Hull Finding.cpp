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
	if(p.y != q.y) return p.y < q.y;
	return p.x < q.x;
}

double turn(Point o, Point a, Point b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}


void find_hull(int n)
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

	printf("%d\n", m);

	for(int i = 0; i < m; i++)
	{
		printf("%.0lf %.0lf\n", convex[i].x, convex[i].y);
	}

}

int main()
{
	int n, c, cases;
	scanf("%d", &cases);
	printf("%d\n", cases);
	while(cases--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%lf %lf", &points[i].x, &points[i].y);
		}

		if(cases) scanf("%d", &c);
		find_hull(n);
		if(cases) puts("-1");
	}

	return 0;
}