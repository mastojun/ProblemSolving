#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int c, n, m;

char resultSet[201][201];
int resultCounter[201];

struct Node
{
	int counter;
	Node* next[26];

	Node(){
		counter = 0;
		for(int i = 0; i < 26; i++){
			next[i] = NULL;
		}
	}
};

Node head;

void initNode(Node* node)
{
	if(node == NULL){return;}

	node->counter = 0;
	for(int i = 0; i < 26; i++){
		initNode(node->next[i]);
		delete node->next[i];
		node->next[i] = NULL;
	}
}

void init()
{
	memset(resultCounter, 0, sizeof(resultCounter));
	initNode(&head);
}

void updateResult(char* str, int length, int counter)
{
	char subStr[500];
	for(int i = 0; i < length; i++) subStr[i] = str[i];
	subStr[length] = 0;

	if(counter > resultCounter[length]){
		strcpy(resultSet[length], subStr);
		resultCounter[length] = counter;
	}
	else if(counter == resultCounter[length] && strcmp(subStr, resultSet[length]) < 0){
		strcpy(resultSet[length], subStr);
	}
}

void insert(Node* node, char* str, int idx)
{
	node->counter++;
	if(idx > 0){
		updateResult(str, idx, node->counter);
	}
	if(idx == m){return;}
	if(str[idx] == 0){return;}
	int nodeIdx = str[idx] - 'a';

	if(node->next[nodeIdx] == NULL){
		node->next[nodeIdx] = new Node();
	}

	insert(node->next[nodeIdx], str, idx+1);
}

int main()
{
	scanf("%d", &c);

	while(c --> 0)
	{
		scanf("%d %d", &n, &m);

		init();

		for(int i = 0; i < n; i++){
			char word[1000];
			scanf("%s", word);
			insert(&head, word, 0);
		}

		for(int i = 1; i <= m; i++){
			printf("%s\n", resultSet[i]);
		}
	}

	return 0;
}

