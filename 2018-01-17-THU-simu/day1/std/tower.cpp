#include <bits/stdc++.h>

using namespace std;

const int maxn = 105,maxm = 20000,maxl = 200005;

typedef int mat[maxn][maxn];

mat c,tr;
int f[maxm][maxn],n,l,mo;

inline void upd(int &a,int b)
{
	a += b;
	if (a >= mo) a -= mo;
}

void mul(mat &a,mat &b,mat &c)
{
	static mat tmp;
	memset(tmp,0,sizeof tmp);
	for(int i = 0;i <= n;i ++)
		for(int k = 0;k <= n;k ++)
			if (a[i][k])
				for(int j = 0;j <= n;j ++)
					if (b[k][j])
						tmp[i][j] = (tmp[i][j] + a[i][k] * 1ll * b[k][j]) % mo;
	memcpy(c,tmp,sizeof c);
}

int main()
{
	freopen("tower.in","r",stdin),freopen("tower.out","w",stdout);
	scanf("%d%d%d", &n, &l, &mo);
	f[0][1] = 1;
	l --;
	int sum = 0;
	for(int i = n;i;i --)
	{
		for(int l = sum;l >= 0;l --)
			for(int k = 0;k <= i && k <= n - i + 1;k ++)
			{
				if (!f[l][k]) continue;
				int w = f[l][k];
				f[l][k] = 0;
				upd(f[l + 2 * i][k + 1],w * 1ll * k % mo);
				upd(f[l + i][k],2ll * w * k % mo);
				if (k) upd(f[l][k - 1], w * 1ll * k % mo);
			}
		sum += 2 * i;
	}
	c[0][0] = 1;	
	for(int i = 1;i <= n;i ++)
		for(int j = i;j;j --)
			c[0][j] = (c[0][j - 1] + c[0][j]) % mo;
	for(int i = 0;i <= n;i ++) 
	{
		tr[i][i] = 1;
		if (i) tr[i - 1][i] = 1;
	}
	for(int b = l - min(sum,l);b;b >>= 1,mul(tr,tr,tr))
		if (b & 1) mul(c,tr,c);
	int ans = 0;
	for(int i = min(sum,l);i >= 0;i --)
	{
		ans = (ans + c[0][n] * 1ll * f[i][0]) % mo;
		for(int j = n;j;j --) c[0][j] = (c[0][j - 1] + c[0][j]) % mo;
	}
	printf("%d\n", ans);
	return 0;
}
