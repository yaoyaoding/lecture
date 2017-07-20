#include<stdio.h>
#include<string.h>
#include <iostream>
#include <algorithm>
const int oo=0x3f3f3f3f;
const int N=100005;
int tn=0,a[N],n,m;
char cc[100]; 
using namespace std;

struct node{
	int maxn;
	node *ls,*rs;
	node(){
		maxn=0;ls=rs=NULL;
	}
}w[2*N+5],*p=w,*root;

node* build(int lf,int rg)
{
	node *nd=++p;
	if(lf==rg)
		nd->maxn=a[lf];
	else
	{
		int mid=(lf+rg)/2;
		nd->ls=build(lf,mid);
		nd->rs=build(mid+1,rg);
		nd->maxn=max(nd->ls->maxn,nd->rs->maxn);
	}
	return nd;
}

int cmodify = 0;
void modify(node *nd,int lf,int rg,int pos,int chn)
{
	fprintf( stderr, "modify %d\n", ++cmodify );
	if(lf==rg)
	{
		nd->maxn=chn;
		return;
	}
	int mid=(lf+rg)/2;
	if(pos<=mid)
		modify(nd->ls,lf,mid,pos,chn);
	else
		modify(nd->rs,mid+1,rg,pos,chn);
	nd->maxn=max(nd->ls->maxn,nd->rs->maxn);
}

int cquery = 0;
int query(node *nd,int lf,int rg,int L,int R)
{
	fprintf( stderr, "query [%d,%d] %d\n", lf, rg, ++cquery );
	if(L<=lf&&R>=rg)
		return nd->maxn;
	int mid=(lf+rg)/2;
	int rt=-oo;
	if(L<=mid)
		rt=max(rt,query(nd->ls,lf,mid,L,R));
	if(R>mid)
		rt=max(rt,query(nd->rs,mid+1,rg,L,R));
	return rt;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	root=build(1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",cc);
		if(cc[0]=='m')
		{
			int pos,chn;
			scanf("%d%d",&pos,&chn);
			modify(root,1,n,pos,chn);
		}
		else
		{
			int L,R;
			scanf("%d%d",&L,&R);
			printf("%d\n",query(root,1,n,L,R));
		}
	}
	return 0;
}
