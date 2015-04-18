#include<bits/stdc++.h>

using namespace std;

struct Time
{
    int hour;
    int minute;

    Time()
    {

    }

    Time (int _hour, int _minute)
    {
        hour = _hour;
        minute = _minute;
    }
};

int duration(Time f, Time s)
{
    if(s.minute > f.minute)
    {
        f.minute += 60;
        s.hour++;
    }

    return (f.hour - s.hour)*60 + (f.minute - s.minute);
}

bool compare(pair<Time, Time> a, pair<Time, Time> b)
{
    if(a.first.hour != b.first.hour)return a.first.hour < b.first.hour;
    return a.first.minute < b.first.minute;
}

int main()
{
    int nos, day = 1;
    char work[2048];

    while(scanf("%d", &nos) != EOF)
    {
        Time s, f, last, napstarts;
        int maxNap = -1, df;
        vector< pair <Time, Time> > schedule;
        schedule.push_back(make_pair(Time(9, 0), Time(10, 0)));
        for(int i=0; i<nos; i++)
        {
            scanf("%2d:%2d %2d:%2d", &s.hour, &s.minute, &f.hour, &f.minute);
            while(getc(stdin) != '\n');
            schedule.push_back(make_pair(Time(s.hour, s.minute), Time(f.hour, f.minute)));
        }
        schedule.push_back(make_pair(Time(18, 0), Time(19, 0)));

        sort(schedule.begin(), schedule.end(), compare);
        int sz = schedule.size();
        for(int i = 1; i < sz; i++)
        {
            df = duration(schedule[i].first, schedule[i-1].second);
            if(df > maxNap)
            {
                maxNap = df;
                napstarts = schedule[i-1].second;
            }
        }
        printf("Day #%d: the longest nap starts at %d:%02d and will last for ", day++, napstarts.hour, napstarts.minute);
        if(maxNap < 60) printf("%d minutes.\n", maxNap);
        else printf("%d hours and %d minutes.\n", maxNap/60, maxNap%60);

    }
    return 0;
}
