#include <cstdio>
#include <cfloat>
#include <algorithm>

using namespace std;

double dist;
double capacity;
double miles;
double cost;
int station;

struct Station {
	double position;
	double cent;
} stations[52];

bool canGo(double dist, double gallon) {
	return miles * gallon >= dist;
}

double solve(int now, double gallon) {
	if(now > station) return 0.0;

	double result = DBL_MAX;

	int next = now + 1;
	double dist = stations[next].position - stations[now].position;

	if(canGo(dist, gallon)) {
		result = min(result, solve(next, gallon - dist/miles));
	}

	if((!canGo(dist, gallon) || gallon <= capacity/2.) && canGo(dist, capacity)) {
		result = min(result, solve(next, capacity - dist/miles) + 200. + (capacity - gallon) * stations[now].cent);
	}

	return result;
}

int main()
{
	int dataSet = 1;
	while(scanf("%lf", &dist) != -1) {
		if(dist < 0.0) break;

		scanf("%lf %lf %lf %d", &capacity, &miles, &cost, &station);

		stations[0].position = 0;
		for(int i = 1; i <= station; i++) {
			scanf("%lf %lf", &stations[i].position, &stations[i].cent);
		}
		stations[station+1].position = dist;

		printf("Data Set #%d\n", dataSet++);
		printf("minimum cost = $%.2lf\n", solve(0, capacity)/100.0 + cost);
	}

	return 0;
}


