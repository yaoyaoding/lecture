#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b>a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b<a)a = b; }
#define MS(x,y) memset(x,y,sizeof(x))
typedef long long LL;
const int N = 661000,Z = 1e9+7,INF = 0x3f3f3f3f;

const double pi = acos ( -1.0 ) ;
struct Complex
{
    double r , i ;
    Complex ( double r=0 , double i=0 ) : r ( r ) , i ( i ) {}
    Complex operator + ( const Complex& p ) const
    {return Complex ( r + p.r , i + p.i ) ;}
    Complex operator - ( const Complex& p ) const
    {return Complex ( r - p.r , i - p.i ) ;}
    Complex operator * ( const Complex& p ) const
    {return Complex ( r * p.r - i * p.i , r * p.i + i * p.r ) ;}
}x1[2100000] , x2[2100000];
double A[N],B[N];
void FFT(Complex a[],int n,int t)
{
    for(int i = 1,j = 0; i < n-1; ++i)
    {
        for(int s = n; j^=s>>=1, ~j&s;);
        if(i<j) swap(a[i],a[j]);
    }
    for(int d = 0; (1<<d)<n; ++d)
    {
        int m=1<<d,m2=m<<1;
        double o = pi/m*t; Complex _w(cos(o),sin(o));
        for(int i = 0; i < n; i+=m2)
        {
            Complex w(1,0);
            for(int j = 0; j <     m; ++j)
            {
                Complex &A = a[i+j+m],&B = a[i+j],t=w*A;
                A=B-t; B=B+t; w=w*_w;
            }
        }
    }
    if(t==-1)for(int i = 0; i < n; ++i)
        a[i].r /= n;
}
int multi(int l1,int r1,double *a,double *la,int l2,int r2,double *b,double *lb)
{
    int len1 = r1-l1+1, len2 = r2-l2+1, len = 1,s1,s2;
    if(la > a) s1 = 1;else s1 = -1;
    if(lb > b) s2 = 1;else s2 = -1;
    while(len < len1+len2-1) len<<=1;
    for(int i = l1;i <= r1;i++) x1[i-l1] = Complex((*a),0),a+=s1;
    for(int i = len1;i < len;i++) x1[i] = Complex(0,0);
    for(int i = l2;i <= r2;i++) x2[i-l2] = Complex((*b),0),b+=s2;
    for(int i = len2;i < len;i++) x2[i] = Complex(0,0);
    FFT(x1,len,1);FFT(x2,len,1);
    for(int i = 0;i < len;i++) x1[i] = x1[i]*x2[i];
    FFT(x1,len,-1);
    return -l1-l2;
}

int n,m,R,M;
double r;
void solve()
{
    R = (r+1); M = m+2*R;
    MS(A,0); MS(B,0);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            scanf("%lf",&A[i*M+j+R]);//make A

    double dis;
    int rem = R*(m+2*R);
    for(int i = -R; i <= R; ++i)//make B
        for(int j = -R; j <= R; ++j)
        {
            if( (dis = i*i + j*j) >= r*r) continue;
            dis = sqrt(dis);
            B[rem+i*M+j] = 1/(dis+1);
        }

    rem = multi(0,n*M-1, A, A+n*M-1,  -R*M, R*M, B, B+2*R*M);
    double ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            gmax(ans, x1[rem + i*M+j+R].r);
    printf("%.3f\n",ans);
}
int main()
{
    freopen("energy.in","r",stdin);
    freopen("energy.out","w",stdout);
    while(~scanf("%d%d%lf",&n,&m,&r)) solve();
    return 0;
}
