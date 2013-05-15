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
	}
};

Node head;
Node nodePool[600000];
int nodePoolIdx;

Node* getNode()
{
	nodePool[nodePoolIdx].counter = 0;
	memset(nodePool[nodePoolIdx].next, 0, sizeof(nodePool[nodePoolIdx].next));
	return &nodePool[nodePoolIdx++];
}

void init()
{
	memset(resultCounter, 0, sizeof(resultCounter));
	nodePoolIdx = 0;
	memset(head.next, 0, sizeof(head.next));
}

void updateResult(char* str, int length, int counter)
{
	if(counter > resultCounter[length]){
		strncpy(resultSet[length], str, length);
		resultCounter[length] = counter;
	}
	else if(counter == resultCounter[length] && strncmp(str, resultSet[length], length) < 0){
		strncpy(resultSet[length], str, length);
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
		node->next[nodeIdx] = getNode();
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

