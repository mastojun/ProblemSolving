#include <cstdio>

using namespace std;

int a, b, c, d;
int e, f, g, h;

int main()
{
	scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);

	if(a < g && c > e && b < h && d > f) puts("rectangle");
	else if(a == g || c == e || b == h || d == f){
		if(a < g && c > e || b < h && d > f) puts("line");
		else puts("point");
	}
	else{
		puts("none");
	}
	return 0;
}

