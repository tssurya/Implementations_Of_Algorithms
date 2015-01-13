#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<climits>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<clocale>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>

//containers
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<complex>
#include<string>
#include<stack>
#include<bitset>
#include<istream>
#include<valarray>

//IOs
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<exception>
#include<ios>
#include<iosfwd>
#include<ostream>
#include<iterator>
#include<stdexcept>
#include<streambuf>


//algorithm & miscellaneous
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<locale>
#include<memory>
#include<new>

#define ll long long
#define ull unsigned long long
#define ld long double
#define mp make_pair
#define pb push_back
#define inf (ll)1e18
#define iinf (int)1e9
#define triple(a,b,c) make_pair(a,make_pair(b,c))
#define two(a,b) make_pair(a,b)
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<long long,long long>
#define psi pair<string,int>
#define pis pair<int,string>
#define pss pair<string,string>
#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>
#define vc vector<char> 
#define vpii vector<pii>
#define GI ({int t;scanf("%d",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
#define GF ({float t;scanf("%f",&t);t;})
#define GL ({long long t;scanf("%lld",&t);t;})
#define GLD ({long double t;scanf("%Lf",&t);t;})


int dx[] = {-1,0,0,1,-1,-1,1,1};
int dy[] = {0,-1,1,0,-1,1,-1,1};
const double eps = 1e-9;
int n,m,graph[105][105],dist[105][105];
using namespace std;
void reset()
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			graph[i][j]=0;
			dist[i][j]=int(1e9);
		}
	}
}
void dijkstra(int s1,int s2,int d1,int d2,int t)
{
	dist[s1][s2]=0;
	priority_queue<pair<int,pair<int,int> > >q;
	q.push(make_pair(0,make_pair(s1,s2)));

	while(!q.empty())
	{
		pair<int,pair<int,int> > p=q.top();
		q.pop();
		int previous_node_x=p.second.first;
		int previous_node_y=p.second.second;
		int previous_weight= -p.first;
		cout<<"initial\n";
		cout<<previous_node_x<<" "<<previous_node_y<<" "<<previous_weight<<"\n";
		if(previous_node_x==d1 and previous_node_y==d2)break;
		for(int i=0;i<4;i++)
		{
			int next_node_x=(previous_node_x+dx[i]);
			int next_node_y=(previous_node_y+dy[i]);
			cout<<"before\n";
			cout<<next_node_x<<" "<<next_node_y<<"\n";
			if(next_node_x>=1 and next_node_x<=n and next_node_y>=1 and next_node_y<=m and dist[next_node_x][next_node_y]>previous_weight+graph[next_node_x][next_node_y])
			{
				cout<<"now\n";
				cout<<next_node_x<<" "<<next_node_y<<"\n";
				dist[next_node_x][next_node_y]=previous_weight+graph[next_node_x][next_node_y];
				q.push(make_pair(-dist[next_node_x][next_node_y],make_pair(next_node_x,next_node_y)));
			}
			cout<<"after\n";
			cout<<next_node_x<<" "<<next_node_y<<"\n";
		}
	}
	int ans=(t-dist[d1][d2]);
	cout<<dist[d1][d2]<<"\n";
	if(ans>=0)
	{
		printf("YES\n");
		printf("%d\n",ans );
	}
	else
	{
		printf("NO\n");
	}
}
int main()
{
	int k,a,b,t;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d %d",&n,&m);
		reset();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&graph[i+1][j+1]);
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				printf("%d",graph[i+1][j+1]);
			}
			cout<<"\n";
		}
		scanf("%d %d %d",&a,&b,&t);
		dijkstra(1,1,a,b,t);
	}
	return 0;
}
