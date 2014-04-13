#include <cstdio>
#include <algorithm>
using namespace std;

int T;
double C, F, X;

double solve()
{
	double result = 1000000000.0;
	double farm = 0;
	for(int i = 0; ; i++)
	{
		double r =  farm + X / (2+F*i);
		farm += C / (2+F*i);
		if(r > result) break;
		result = r;
	}
	return result;
}

int main()
{
	scanf("%d", &T);

	for(int c = 1; c <= T; c++)
	{
		scanf("%lf %lf %lf", &C, &F, &X);

		printf("Case #%d: %.7lf\n", c, solve());
	}
	return 0;

}
