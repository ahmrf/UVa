#include <stdio.h>
#include <algorithm>

using namespace std;

struct Job
{
	int shomoy, fine, id;
}jobs[1010];;

bool compare(Job a, Job b)
{
	return a.shomoy*b.fine < b.shomoy*a.fine;
}

int main()
{
	int cases, n;
	
	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d", &jobs[i].shomoy, &jobs[i].fine);
			jobs[i].id = i+1;
		}

		stable_sort(jobs, jobs+n, compare);

		printf("%d", jobs[0].id);
		for(int i = 1; i < n; i++)
		{
			printf(" %d", jobs[i].id);
		}
		puts("");
		if(cases) puts("");
	}
	return 0;
}