#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int T;
char A[20], B[20], C[20], operation;

char nums[11][20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

int init()
{
	for(int i = 0; i <= 10; i++)
	{
		sort(nums[i], nums[i] + strlen(nums[i]));
	}
}

int convert(char* num)
{
	sort(num, num + strlen(num));

	for(int i = 0; i <= 10; i++)
	{
		if(strcmp(num, nums[i]) == 0) return i;
	}
	return -1;
}

int cal(int a, char op, int b)
{
	switch(op){
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
	}
	return -11;
}

int main()
{
	scanf("%d", &T);
	init();

	while(T --> 0)
	{
		scanf("%s %c %s = %s", A, &operation, B, C);

		puts(cal(convert(A), operation, convert(B)) == convert(C) ? "Yes" : "No");
	}

	return 0;
}

