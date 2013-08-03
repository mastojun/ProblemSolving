#include <stdio.h>

int main()
{
	int m, d;
	scanf("%d %d", &m, &d);

	int M = 1;
	int D = 1;
	int w = 0;
	char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31 ,30 ,31};

	while(m != M || d != D)
	{
		D++;
		if(day[M] < D){
			M++;
			D = 1;
		}
		w = (w+1)%7;
	}

	puts(week[w]);

	return 0;
}

