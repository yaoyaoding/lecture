#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

typedef long long ll;
const int maxn = 15;
int T,K,P[maxn]; ll N,M,jie[100010],res[maxn];

inline ll qsm(ll a,ll b,ll mod)
{
	ll ret = 1;
	for (;b;b >>= 1,(a *= a) %= mod) if (b&1) (ret *= a)%=mod;
	return ret;
}

inline ll qsj(ll a,ll b,ll mod)
{
	ll ret = 0; a %= mod,b %= mod;
	for (;b;b >>= 1)
	{
		if (b&1)
		{
			ret += a;
			if (ret >= mod) ret -= mod;
		}
		a += a; if (a >= mod) a -= mod;
	}
	return ret;
}

inline ll msm(ll a,ll b,ll mod)
{
	ll ret = 1;
	for (;b;b >>= 1,a = qsj(a,a,mod)) if (b&1) ret = qsj(ret,a,mod);
	return ret;
}

inline ll C(ll n,ll m,ll mod)
{
	if (m > n) return 0;
	if (n < mod) return jie[n]*qsm(jie[m],mod-2,mod)%mod*qsm(jie[n-m],mod-2,mod);
	return C(n/mod,m/mod,mod)*C(n%mod,m%mod,mod)%mod;
}

inline ll crt()
{
	ll lcm = 1,ret = 0;
	for (int i = 1;i <= K;++i) lcm *= (ll)P[i];
	for (int i = 1;i <= K;++i)
	{
		ll tm = lcm/P[i];
		ll inv = msm(tm,P[i]-2,P[i]);
		ret = (ret+qsj(qsj(tm,inv,lcm),res[i],lcm))%lcm;		
	}
	return ret;
}

inline ll work(ll n,ll m)
{
	jie[0] = 1;
	for (int i = 1;i <= K;++i)
	{
		for (int j = 1;j < P[i];++j)
			jie[j] = jie[j-1]*j%P[i];
		res[i] = C(n,m,P[i]);		
	}
	return crt();
}

int main()
{
//	scanf("%d",&T);
	T = 1;
	while (T--)
	{
		cin >> N >> M >> K;
		for (int i = 1;i <= K;++i) cin >> P[i];
		cout << work(N,M) << endl;
	}
	return 0;
}

