#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int T;

int main()
{
	scanf("%d", &T);

	for(int c = 1; c <= T; c++)
	{
		int counter[20] = {0};

		for(int s = 0; s < 2; s++) {
			int row;
			scanf("%d", &row);
			for(int i = 1; i <= 4; i++){
				for(int j = 0; j < 4; j++) {
					int n;
					scanf("%d", &n);
					if(row != i) continue;
					counter[n]++;
				}
			}
		}

		int answer = 0;
		int number = 0;

		for(int i = 1; i <= 16; i++) {
			if(counter[i] == 2) {
				number++;
				answer = i;
			}
		}

		printf("Case #%d: ", c);
		if(number == 0) puts("Volunteer cheated!");
		if(number >  1) puts("Bad magician!");
		if(number == 1) printf("%d\n", answer);
	}

	return 0;
}

