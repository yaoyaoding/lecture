#include <bits/stdc++.h>
#define max(a,b) (a > b ? a : b)

using namespace std;

const int maxn = 100005;

typedef unsigned long long ull;

ull tag[17][maxn];
int final[maxn],to[maxn * 2],nex[maxn * 2],tot;
int n;

void link(int u,int v)
{
	to[++ tot] = v,nex[tot] = final[u],final[u] = tot;
}

int stk[maxn],dep[maxn],mxdep[maxn],cnt,fx,fy;

void dfs(int now,int pre,ull *a,ull *b,ull *c)
{
	stk[++ cnt] = now;
	a[now] = b[now];
	mxdep[now] = dep[now] = cnt;
	if (cnt > fx) 
		(a[stk[cnt - fx]] *= 2543323) += c[now];
	for(int i = final[now];i;i = nex[i])
		if (to[i] != pre) dfs(to[i],now,a,b,c),mxdep[now] = max(mxdep[now],mxdep[to[i]]);
	cnt --;
}

ull cur_v[maxn];

inline bool cmp(int a,int b) {return cur_v[a] < cur_v[b];}

void merge(ull *a,ull *b,ull *c,int x,int y)
{
	fx = x,fy = y;
	dfs(1,0,a,b,c);
	static int ord[maxn];
	for(int i = 1;i <= n;i ++) ord[i] = i,cur_v[i] = a[i];
	sort(ord + 1,ord + n + 1,cmp);
	for(int i = 1,x = 0;i <= n;i ++)
	{
		if (cur_v[ord[i]] != cur_v[ord[i - 1]]) ++ x;
		a[ord[i]] = x;
	}
}

bool test(ull *a,int l)
{
	static int vis[maxn],vistag;
	++ vistag;
	for(int i = 1;i <= n;i ++)
		if (mxdep[i] - dep[i] >= l) 
		{
			if (vis[a[i]] == vistag) return 1;
			vis[a[i]] = vistag;
		}
	return 0;
}

void work()
{
	scanf("%d", &n);
	tot = 0;
	for(int i = 1;i <= n;i ++) final[i] = 0;
	for(int i = 1;i <= n;i ++)
	{
		int x;
		scanf("%d", &x);
		for(int j = 1,u;j <= x;j ++)
			scanf("%d", &u),link(i,u);
		tag[0][i] = x;
	}		
	for(int i = 1;i < 17;i ++) merge(tag[i],tag[i - 1],tag[i - 1],1 << (i - 1),1 << (i - 1));
	static ull cur[2][maxn];
	for(int i = 1;i <= n;i ++) cur[0][i] = 0;
	int ans = 0;
	for(int i = 16;i + 1;i --)
	{
		for(int j = 1;j <= n;j ++) cur[1][j] = cur[0][j];
		merge(cur[0],cur[1],tag[i],ans,1 << i);
		if (!test(cur[0],ans + (1 << i))) swap(cur[0],cur[1]); else ans += (1 << i);
	}
	printf("%d\n", ans);
}

int main()
{
freopen("ernd.in","r",stdin);
freopen("ernd.out","w",stdout);
	work();
	return 0;
}
