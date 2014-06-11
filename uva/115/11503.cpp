#include <cstdio>
#include <map>
#include <string>

using namespace std;

class DisjointSet
{
public:
	int merge(string name1, string name2)
	{
		return merge(convert(name1), convert(name2));
	}
	int init()
	{
		name2number.clear();
	}

private:
	int convert(string name)
	{
		int result = name2number[name];
		if(result != 0) return result;
		result = name2number.size() + 1;
		root[result] = result;
		rank[result] = 1;
		size[result] = 1;
		return name2number[name] = result;
	}

	int find(int n)
	{
		if(root[n] == n) return n;
		return root[n] = find(root[n]);
	}
	int merge(int n1, int n2)
	{
		n1 = find(n1);
		n2 = find(n2);
		if(n1 == n2) return size[n1];

		if(rank[n1] < rank[n2]) swap(n1, n2);

		root[n2] = n1;
		rank[n1] = max(rank[n1], rank[n2]+1);
		return size[n1] += size[n2];
	}

	int root[100002];
	int rank[100002];
	int size[100002];

	map<string, int> name2number;
};

int main()
{
	DisjointSet disjointSet;
	int c;
	scanf("%d", &c);

	while(c --> 0)
	{
		int l;
		scanf("%d", &l);
		disjointSet.init();
		for(int i = 0; i < l; i++)
		{
			char name1[30], name2[30];
			scanf("%s %s", name1, name2);

			printf("%d\n", disjointSet.merge(name1, name2));
		}
	}

	return 0;
}

