#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
namespace IO
{
	const int MAXL=1<<15;
	char buf[MAXL],*S,*T,ch;
	inline char igetch()
	{
		if(S==T)T=(S=buf)+fread(buf,1,MAXL,stdin);
		return S==T?EOF:*S++;
	}
	inline void read(int &x)
	{
		x=0;
		while(!isdigit(ch=igetch()));
		do{x=x*10+(ch^'0');}while(isdigit(ch=igetch()));
	}
}
const int MAXN=100010,MAXM=200010,inf=~0u>>1;
struct node
{
	node *lc,*rc;
	int lower;
	void update(){lower=min(lc->lower,rc->lower);}
}pool[MAXN<<2],*cur=pool;
struct SegmentTree
{
	node *root;
	int n;
	void modify(node *u,int ul,int ur,int p,int k)
	{
		if(ul==ur){u->lower=k;return;}
		int mid=ul+ur>>1;
		if(p<=mid)modify(u->lc,ul,mid,p,k);
		else modify(u->rc,mid+1,ur,p,k);
		u->update();
	}
	int query(node *u,int ul,int ur,int l,int r)
	{
		if(l<=ul&&ur<=r)return u->lower;
		int mid=ul+ur>>1,ret=inf;
		if(l<=mid)ret=min(ret,query(u->lc,ul,mid,l,r));
		if(r>mid)ret=min(ret,query(u->rc,mid+1,ur,l,r));
		return ret;
	}
	void modify(int p,int k){modify(root,1,n,p,k);}
	int query(int l,int r){return l>r?inf:query(root,1,n,l,r);}
	void build(node *&u,int ul,int ur,int *val)
	{
		u=cur++;
		if(ul==ur){u->lower=val[ul];return;}
		int mid=ul+ur>>1;
		build(u->lc,ul,mid,val);
		build(u->rc,mid+1,ur,val);
		u->update();
	}
	void init(int _n,int *val)
	{
		n=_n;
		build(root,1,n,val);
	}
}segt_cir;
struct edge{int adj,weight,next;}e[MAXM<<1];
int n,m,tot,head[MAXN],belong[MAXN],st[MAXN],cnt[MAXN],id[MAXN];
inline void add_edge(int u,int v,int w)
{
	tot++;
	e[tot].adj=v,e[tot].weight=w,e[tot].next=head[u];
	head[u]=tot;
}
inline int calc(int u,int v)
{
	if(u==v)return inf;
	int sec=belong[u];
	if(id[u]>id[v])swap(u,v);
	return segt_cir.query(id[u],id[v]-1)+min(segt_cir.query(id[v],st[sec]+cnt[sec]-1),segt_cir.query(st[sec],id[u]-1));
}
namespace Tree
{
	SegmentTree segt_tree;
	struct edge{int adj,weight,escape,next;}e[MAXN<<1];
	int n,tot,idx,head[MAXN],cnt[MAXN],val[MAXN],ori[MAXN];
	int dep[MAXN],fa[MAXN],top[MAXN],pre[MAXN],chain[MAXN];
	int DFN[MAXN],heavy[MAXN],pos[MAXN];
	inline void add_edge(int u,int v,int w,int o)
	{
		tot++;
		e[tot].adj=v,e[tot].weight=w,e[tot].escape=o,e[tot].next=head[u];
		head[u]=tot;
	}
	void DFS1(int u)
	{
		cnt[u]=1;
		for(int i=head[u];i;i=e[i].next)
		{
			int &v=belong[e[i].adj];
			if(v==fa[u])continue;
			fa[v]=u,dep[v]=dep[u]+1;
			top[v]=e[i].adj,pre[v]=e[i].escape,val[v]=e[i].weight;
			DFS1(v);
			cnt[u]+=cnt[v];
		}
	}
	void DFS2(int u,int f)
	{
		pos[DFN[u]=++idx]=u,chain[u]=f;
		for(int i=head[u];i;i=e[i].next)
		{
			int &v=belong[e[i].adj];
			if(v==fa[u])continue;
			if(cnt[v]>cnt[heavy[u]])heavy[u]=v;
		}
		if(!heavy[u])return;
		DFS2(heavy[u],f);
		for(int i=head[u];i;i=e[i].next)
		{
			int &v=belong[e[i].adj];
			if(v==fa[u]||v==heavy[u])continue;
			DFS2(v,v);
		}
	}
	inline void init()
	{
		DFS1(1);
		DFS2(1,1);
		for(int i=1;i<=n;i++)
			if(heavy[fa[i]]==i&&fa[i]!=1)ori[DFN[i]]=min(val[i],calc(pre[i],top[fa[i]]));
		segt_tree.init(n,ori);
	}
	inline int get_LCA(int u,int v)
	{
		for(;chain[u]!=chain[v];v=fa[chain[v]])
			if(dep[chain[u]]>dep[chain[v]])swap(u,v);
		if(dep[u]>dep[v])swap(u,v);
		return u;
	}
	inline int get_anc(int u,int f)
	{
		int last=0;
		while(chain[u]!=chain[f])last=u,u=fa[chain[u]];
		return u==f?chain[last]:pos[DFN[f]+1];
	}
	inline int chain_query(int u,int f)
	{
		int ret=val[f];
		for(;chain[u]!=chain[f];u=fa[chain[u]])
		{
			ret=min(ret,segt_tree.query(DFN[chain[u]]+1,DFN[u]));
			ret=min(ret,val[chain[u]]);
			ret=min(ret,calc(pre[chain[u]],top[fa[chain[u]]]));
		}
		ret=min(ret,segt_tree.query(DFN[f]+1,DFN[u]));
		return ret;
	}
	inline int query(int u,int v)
	{
		int f,u1,v1;
		f=get_LCA(belong[u],belong[v]);
		u1=get_anc(belong[u],f),v1=get_anc(belong[v],f);
//		cout<<"###"<<u<<' '<<v<<' '<<f<<' '<<u1<<' '<<v1<<endl;
		int ret=calc((u1?pre[u1]:u),(v1?pre[v1]:v));
		if(u1)
		{
			ret=min(ret,calc(u,top[belong[u]]));
			ret=min(ret,chain_query(belong[u],u1));
		}
		if(v1)
		{
			ret=min(ret,calc(v,top[belong[v]]));
			ret=min(ret,chain_query(belong[v],v1));
		}
		return ret;
	}
	inline void modify(int u,int v,int w)
	{
		if(belong[u]==belong[v])
		{
			int sec=belong[u];
			if((id[u]+1-st[sec])%(::cnt[sec])!=(id[v]-st[sec]))swap(u,v);
			segt_cir.modify(id[u],w);
			int &t=heavy[sec];
			if(t&&fa[t]!=1)segt_tree.modify(DFN[t],min(val[t],calc(pre[t],top[fa[t]])));
		}
		else
		{
			u=belong[u],v=belong[v];
			if(dep[u]>dep[v])swap(u,v);
			val[v]=w;
			if(heavy[u]==v&&u!=1)segt_tree.modify(DFN[v],min(val[v],calc(pre[v],top[fa[v]])));
		}
	}
}
bool vis[MAXN];
int sta[MAXN],len,idx,ori[MAXN];
void get_cir(int u,int fa)
{
	vis[u]=true,sta[len++]=u;
	for(int i=head[u];i;i=e[i].next)
	{
		int &v=e[i].adj;
		if(v==fa)continue;
		if(!vis[v])
		{
			get_cir(v,u);
			if(belong[u]==belong[v])ori[id[v]]=e[i].weight;
		}
		else if(!belong[v])
		{
			Tree::n++;
			while(true)
			{
				int t=sta[len-cnt[Tree::n]-1];
				belong[t]=Tree::n,id[t]=++idx;
				cnt[Tree::n]++;
				if(t==v)break;
			}
			ori[id[v]]=e[i].weight;
			st[Tree::n]=id[u];
		}
	}
	if(!belong[u])
	{
		st[++Tree::n]=id[u]=++idx;
		cnt[belong[u]=Tree::n]=1;
	}
	--len;
}
inline void init()
{
	int m;
	IO::read(n),IO::read(m);
	while(m--)
	{
		int u,v,w;
		IO::read(u),IO::read(v),IO::read(w);
		add_edge(u,v,w),add_edge(v,u,w);
	}
	get_cir(1,0);
//	for(int i=1;i<=n;i++)cout<<i<<' '<<belong[i]<<' '<<ori[id[i]]<<' '<<id[i]<<endl;
	segt_cir.init(n,ori);
	for(int u=1;u<=n;u++)
		for(int i=head[u];i;i=e[i].next)
		{
			int &v=e[i].adj;
			if(belong[u]!=belong[v])Tree::add_edge(belong[u],v,e[i].weight,u);
		}
	Tree::init();
}
inline void solve()
{
	int q,opt,u,v;
	IO::read(q);
	while(q--)
	{
		IO::read(opt),IO::read(u),IO::read(v);
		if(opt)Tree::modify(e[u*2-1].adj,e[u*2].adj,v);
		else printf("%d\n",Tree::query(u,v));
	}
}
int main(void)
{
	freopen("stream.in","r",stdin);
	freopen("stream.out","w",stdout);
	init();
	solve();
	return 0;
}