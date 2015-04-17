#include <stdio.h>
#include <math.h>

using namespace std;

struct segment
{
	char type;
	double ulx, uly, lrx, lry, x, y, r;
};

int main()
{
	struct segment seg[100];
	int idx = -1, p = 1;
	char type[3];
	while(scanf("%s", type) == 1)
	{
		seg[++idx].type = type[0];
		if(type[0] == 'c')
		{
			scanf("%lf %lf %lf", &seg[idx].x, &seg[idx].y, &seg[idx].r);
		}
		else
		{
			scanf("%lf %lf %lf %lf", &seg[idx].ulx, &seg[idx].uly, &seg[idx].lrx, &seg[idx].lry);	
		}

		while(scanf("%s", type) == 1 && type[0] != '*')
		{
			seg[++idx].type = type[0];
			if(type[0] == 'c')
			{
				scanf("%lf %lf %lf", &seg[idx].x, &seg[idx].y, &seg[idx].r);
			}
			else
			{
				scanf("%lf %lf %lf %lf", &seg[idx].ulx, &seg[idx].uly, &seg[idx].lrx, &seg[idx].lry);	
			}
		}

		double x, y;
		while(scanf("%lf %lf", &x, &y) == 2)
		{
			if(x == 9999.9 && y == 9999.9) break;
			bool nai = true;
			for(int i = 0; i <= idx; i++)
			{
				if(seg[i].type == 'c')
				{
					if(sqrt((seg[i].x - x)*(seg[i].x - x) + (seg[i].y - y)*(seg[i].y - y)) < seg[i].r)
					{
						printf("Point %d is contained in figure %d\n", p, i+1);
						nai = false;
					}
				}
				else
				{
					if(x < seg[i].lrx && x > seg[i].ulx && y < seg[i].uly && y > seg[i].lry)
					{
						printf("Point %d is contained in figure %d\n", p, i+1);
						nai = false;	
					}
				}
			}
			if(nai)
			{
				printf("Point %d is not contained in any figure\n", p);
			}
			p++;
		}
		idx = -1, p = 1;
	}
	return 0;
}