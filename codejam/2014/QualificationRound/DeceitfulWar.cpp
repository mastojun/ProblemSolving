#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
double Naomi[1000];
double Ken[1000];

int war(double* w, double* l)
{
	double winner[1000], loser[1000];
	for(int i = 0; i < N; i++)
	{
		winner[i] = w[i];
		loser[i] = l[i];
	}

	int win = 0;
	for(int i = N-1; i >= 0; i--)
	{
		double minimum = 2;
		int index = 0;
		for(int j = 0; j < N; j++)
		{
			double diff = winner[j] - loser[i];
			if(diff < 0) continue;
			if(minimum > diff)
			{
				minimum = diff;
				index = j;
			}
		}
		if(minimum < 1)
		{
			win++;
			winner[index] = -1;
		}
	}
	return win;
}

int main()
{
	scanf("%d", &T);

	for(int Case = 1; Case <= T; Case++)
	{
		scanf("%d", &N);
		printf("Case #%d: ", Case);

		for(int i = 0; i < N; i++) scanf("%lf", Naomi + i);
		for(int i = 0; i < N; i++) scanf("%lf", Ken + i);

		sort(Naomi, Naomi + N);
		sort(Ken, Ken + N);

		printf("%d %d\n", war(Naomi, Ken), N - war(Ken, Naomi));

	}
	return 0;
}

