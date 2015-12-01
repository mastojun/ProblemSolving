#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int C;

string reverseTree(string tree)
{
	string part[4];
	int idx = 0;
	for (int i = 0; idx < 4 && i < tree.length();) {
		if (tree[i] == 'x') {
			part[idx] = "x" + reverseTree(tree.substr(i + 1));
		}
		else {
			part[idx] = tree[i];
		}
		i += part[idx++].length();
	}
	return part[2] + part[3] + part[0] + part[1];
}

int main()
{
	scanf("%d", &C);

	while (C--> 0)
	{
		string quardTree;
		cin >> quardTree;
		cout << reverseTree(quardTree) << endl;
	}

	return 0;
}

