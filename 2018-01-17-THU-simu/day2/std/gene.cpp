#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005,maxl = 320;

struct info
{
	int front_node,ans;
}Block_sav[maxl][maxn];

struct pnode
{
	int apear[maxl];
	int fail,quick[26],go[26],len;
}T[maxn];

char s[maxn];
int walk[26][maxn],sav[26][maxn];
int n,m,cnt,vis[maxn],vistag;

void palindrome_init()
{
	cnt = 1;
	T[1].len = -1;
	T[0].fail = 1;
	for(int i = 0;i < 26;i ++) T[0].quick[i] = 1;
}

long long sum;
int dep[maxn];

inline int insert(bool type,int bar,int p,int lst,int x) //type=0:insert_front,type=1:insert_back
{
	int fa;
	int fx = -1;
	if (!type) 
	{
		fx = s[p + T[lst].len + 1]; 
		if (p + T[lst].len + 1 > bar) fx = -1;
	}
	else 
	{
		fx = s[p - T[lst].len - 1];
		if (p - T[lst].len - 1 < bar) fx = -1;
	}
	bool skip1 = 0,skip2 = 0;
	if (fx == x + 'a') 
	{
		sum ++;
		if (sav[x][lst]) return sav[x][lst];
		fa = lst,skip1 = 1; 
	} else
	{
		sum += dep[lst] - dep[T[lst].quick[x]];
		if (walk[x][lst]) return walk[x][lst];
		fa = T[lst].quick[x];
		skip2 = 1;
	}
	if (!T[fa].go[x]) 
	{
		T[fa].go[x] = ++ cnt;
		dep[cnt] = dep[fa] + 1;
		for(int i = 1;i < maxl;i ++) T[cnt].apear[i] = (1 << 30);
		T[cnt].fail = T[T[fa].quick[x]].go[x];
		int q = T[cnt].fail;
		memcpy(T[cnt].quick,T[q].quick,sizeof T[cnt].quick);
		if (!type) fx = s[p + T[q].len]; else fx = s[p - T[q].len];
		T[cnt].quick[fx - 'a'] = q;
		T[cnt].len = T[fa].len + 2;
	}
	if (skip1) sav[x][lst] = T[fa].go[x];
	if (skip2) walk[x][lst] = T[fa].go[x];
	return T[fa].go[x];
}

int main()
{
	freopen("gene.in","r",stdin),freopen("gene.out","w",stdout);
	int type;
	scanf("%d", &type);
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	int L = sqrt(n);
	palindrome_init();
	for(int i = 1;i * L < n;i ++)
	{
		int cur = 0;
		++ vistag;
		for(int j = i * L;j < n;j ++)
		{
			cur = insert(1,i * L,j,cur,s[j] - 'a');
			Block_sav[i][j].ans = Block_sav[i][j - 1].ans;
			if (vis[cur] != vistag)
			{
				T[cur].apear[i] = j;
				vis[cur] = vistag;
				++ Block_sav[i][j].ans;
			}
			if (T[cur].len == j - i * L + 1) Block_sav[i][j].front_node = cur; else Block_sav[i][j].front_node = Block_sav[i][j - 1].front_node;
		}
	}
	sum = 0;
	int lstans = 0;
	for(int i = 1;i <= m;i ++)
	{
		int l,r;
		scanf("%d%d", &l, &r);
		if (type) l ^= lstans,r ^= lstans;
		int ans = 0;
		l --,r --;
		if (r - l <= L)
		{
			++ vistag;
			int cur = 0;
			for(int j = l;j <= r;j ++)
			{
				cur = insert(1,l,j,cur,s[j] - 'a');
				if (vis[cur] != vistag) ++ ans,vis[cur] = vistag;
			}
		} else
		{
			int p = (l / L) + 1,cur = Block_sav[p][r].front_node;
			ans = Block_sav[p][r].ans;
			++ vistag;
			for(int j = p * L - 1;j >= l;j --)
			{
				cur = insert(0,r,j,cur,s[j] - 'a');
				if (T[cur].apear[p] > r && vis[cur] != vistag)
				{
					vis[cur] = vistag;
					++ ans;
				}
			}
		}
		printf("%d\n", lstans = ans);
	}
	return 0;
}
