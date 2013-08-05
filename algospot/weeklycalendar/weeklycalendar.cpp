#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char weeks[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getWeekDay(char* week)
{
	for(int i = 0; i < 7; i++)
	{
		if(strcmp(week, weeks[i]) == 0) return i;
	}

	return -1; // error!
}

int main()
{
	int T;
	scanf("%d", &T);


	while(T --> 0)
	{
		int m, d;
		char week[10];
		scanf("%d %d %s", &m, &d, week);

		d -= getWeekDay(week);

		if(d < 1)
		{
			m--;
			if(m < 1) m = 12;
			d = days[m] + d;
		}

		for(int i = 0; i < 7; i++)
		{
			printf("%d%c", d, i == 6 ? '\n' : ' ');
			d++;
			if(d > days[m]) d = 1;
		}
	}

	return 0;
}

