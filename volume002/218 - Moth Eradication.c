#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	double x, y;
}Point;

Point Pt[100000], C[100000];

int compare(const void *p, const void *q)
{
	Point *a, *b;
	a = (Point *)p, b = (Point *)q;
	if(a->x != b->x)
	{
		return a->x - b->x > 0? 1 : -1;
	}
	return a->y - b->y> 0? 1 : -1;
}


double turn(Point o, Point a, Point b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}


void solve(int n)
{
	qsort(Pt, n, sizeof(Point), compare);
	int m = 0, i, t;
	for(i = 0; i < n; i++)
	{
		while(m >= 2 && turn(C[m-2], C[m-1], Pt[i]) >= 0)
		{
			m--;
		}
		C[m++] = Pt[i];
	}

	for(i = n-1, t = m+1; i >= 0; i--)
	{
		while(m >= t && turn(C[m-2], C[m-1], Pt[i]) >= 0)
		{
			m--;
		}
		C[m++] = Pt[i];
	}

	double perimeter = 0;

	for(i = 0; i < m; i++)
	{
		if(i)
		{
			printf("-");
			perimeter += sqrt((C[i].x-C[i-1].x)*(C[i].x-C[i-1].x) + (C[i].y-C[i-1].y)*(C[i].y-C[i-1].y));
		}

		printf("(%.1lf,%.1lf)", C[i].x, C[i].y);
	}

	printf("\nPerimeter length = %.2lf\n", perimeter);
}

int main()
{
	int n, i, cases = 0;
	while(scanf("%d", &n) == 1 && n)
	{
		for(i = 0; i < n; i++)
		{
			scanf("%lf %lf", &Pt[i].x, &Pt[i].y);
		}
		if(cases)	puts("");
		printf("Region #%d:\n", ++cases);
		solve(n);
	}
	return 0;
}