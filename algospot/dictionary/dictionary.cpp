#include <cstdio>
#include <cstring>

using namespace std;

int C, n;
char word[1001][30];

char dic[26][26];

int visited[26];
char result[26];
int resultIdx;
bool hasCycle;

void dfs(int idx, int value)
{
	int firstIdx = value == -1 ? idx : value;
	bool firstVisited = visited[idx] == -1;

	visited[idx] = firstIdx;
	for(int i = 0; i < 26; i++)
	{
		if(dic[idx][i])
		{
			if(visited[i] == -1)
			{
				dfs(i, firstIdx);
			}
			else if(firstIdx == i)
			{
				hasCycle = true;
				return;
			}
		}
	}

	if(firstVisited) result[resultIdx++] = idx;
}

int main()
{
	scanf("%d", &C);

	while(C --> 0)
	{
		scanf("%d", &n);

		for(int i = 0; i < n; i++)
		{
			scanf("%s", word[i]);
		}

		memset(dic, 0, sizeof(dic));

		for(int i = 1; i < n; i++)
		{
			for(int j = 0; word[i-1][j] && word[i][j]; j++)
			{
				if(word[i-1][j] - word[i][j]){
					dic[word[i-1][j]-'a'][word[i][j]-'a'] = 1;
					break;
				}
			}
		}

		resultIdx = 0;
		memset(visited, -1, sizeof(visited));
		hasCycle = false;

		for(int i = 0; hasCycle == false && i < 26; i++)
		{
			if(visited[i] == -1)
			{
				dfs(i, -1);
			}
		}

		if(hasCycle){puts("INVALID HYPOTHESIS");}
		else
		{
			for(int i = resultIdx-1; i >= 0; i--)
			{
				putchar(result[i] + 'a');
			}
			for(int i = 0; i < 26; i++)
			{
				if(visited[i] != -1){continue;}
				putchar(i + 'a');
			}
			putchar('\n');
		}
	}

	return 0;
}


