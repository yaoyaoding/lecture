#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5 + 10;
long long n,m;
long long a[4*N],tagm[4*N],tagc[4*N],sum[4*N];
void update(long long o)
{
	sum[o]=sum[o<<1]+sum[o<<1|1];
}
void push_down(long long o,long long l,long long r)
{
	long long mid=(l+r)>>1;
	if(tagc[o]){
		tagc[o<<1]+=tagc[o];
		tagc[o<<1|1]+=tagc[o];
		
		sum[o<<1]+=tagc[o]*(mid-l+1);
		sum[o<<1|1]+=tagc[o]*(r-mid);
		
		tagc[o]=0;
	}
	if(tagm[o]!=-1){
		tagm[o<<1]=tagm[o];
		tagm[o<<1|1]=tagm[o];
		
		sum[o<<1]=tagm[o]*(mid-l+1);
		sum[o<<1|1]=tagm[o]*(r-mid);
		
		tagm[o]=-1;
		tagc[o<<1]=0;
		tagc[o<<1|1]=0;
	}
}
void build(long long o,long long l,long long r)
{	
    tagm[o]=-1;
	if(l==r){
		sum[o]=a[l];
		return ;
	}
	long long mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	
	update(o);
}
void modify(long long o,long long l,long long r,long long L,long long R,long long x)
{
	if(L<=l&&r<=R){
		tagm[o]=x;
		tagc[o]=0;
		sum[o]=x*(r-l+1);
		return ;
	}
	
	long long mid=(l+r)>>1;
	push_down(o,l,r);
	
	if(L<=mid) modify(o<<1,l,mid,L,R,x);
	if(R>mid) modify(o<<1|1,mid+1,r,L,R,x);
	
	update(o);
}
void change(long long o,long long l,long long r,long long L,long long R,long long del)
{
	if(L<=l&&r<=R){
		tagc[o]+=del;
		sum[o]+=del*(r-l+1);
		return ;
	}
	
	long long mid=(l+r)>>1;
	push_down(o,l,r);
	
	if(L<=mid) change(o<<1,l,mid,L,R,del);
	if(R>mid) change(o<<1|1,mid+1,r,L,R,del);
	
	update(o);
}
long long query(long long o,long long l,long long r,long long L,long long R)
{
	if(L<=l&&r<=R)
	    return sum[o];
	long long mid=(l+r)>>1;
	push_down(o,l,r);
	long long ans=0;
	if(L<=mid) ans+=query(o<<1,l,mid,L,R);
	if(R>mid) ans+=query(o<<1|1,mid+1,r,L,R);
	
	return ans;
}
int main()
{
//	freopen("setmod.in","r",stdin);
//	freopen("setmod.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)  cin>>a[i];
	build(1,1,n);
	while(m--){
		string s;
		cin>>s;
		if(s[0]=='m'){
			long long L,R,x;
			cin>>L>>R>>x;
			modify(1,1,n,L,R,x);
		}
		else if(s[0]=='c'){
			long long L,R;
			long long del;
			cin>>L>>R>>del;
			change(1,1,n,L,R,del);
		}
		else{
			long long L,R;
			cin>>L>>R;
			cout<<query(1,1,n,L,R)<<endl;
		}
	}
	return 0;
}
