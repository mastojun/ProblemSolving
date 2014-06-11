#include
#define max(a,b) a>b ? a:b
using namespace std;

int row[110][110],mat[110][110],n,m;

int func(int start, int end)
{
	int i,j,curnt=0, mx=-1270000;
	for(i=1;i<=n;i++)
	{
		j=row[i][end]-row[i][start-1];
		curnt+=j;
		if(curnt>mx) mx=curnt;
		if(curnt<0) curnt=0;
	}
	return mx;
}

int main()
{
	int i,j,temp;
	while(cin>>n)
	{
		for(i=0;i<=n;i++)
		{
			row[i][0]=0;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cin>>mat[i][j];
				row[i][j]=row[i][j-1]+mat[i][j];
			}
		}

		temp=-12700000;
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				temp=max(temp,func(i,j));
			}
		}
		cout<<temp<<endl;
	}
	return 0;
}


