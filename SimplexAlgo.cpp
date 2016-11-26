// https://www.hackerrank.com/contests/zenhacks/challenges/circles-1

///============================================================================///
///                                                                            ///
///                            IT'S ME                                         ///
///                         BISHAL GAUTAM                                      ///
///                  CSE,JAHANGIRNAGAR UNIVERSITY,DHAKA                        ///
///               "Follow Excellence..Success will chase U"                    ///
///                                                                            ///
///============================================================================///
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define X first
#define Y second
#define nl printf("\n")
#define SZ(x) (int)(x.size())
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpp make_pair
 
///==Scanning====///
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
 
///==Arr,Vec Functions==///
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define MAX(a) (*max_element(all(a)))
#define MIN(a) (*min_element(all(a)))
#define fv(i,v)  for(int i=0;i<(int)v.size();i++)
#define fr(i,a,n) for(int i=a;i<=n;i++)
#define rf(i,n,a) for(int i=n;i>=a;i--)
 
///===Some Useful====///
#define OnBit(a) __builtin_popcountll(a)
#define LB(v,k) lower_bound(v.begin(),v.end(),k)
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
#define dbg(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define fi(n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
#define IO freopen("A.in","r",stdin),freopen("Out.out","w",stdout)
using namespace std;
 
///===TypeDefs=====///
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vii;
 
///===Number Theory===///
//template< class T > inline T SQR(T a) { return a*a; }
//template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
//template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
//template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//template<typename T> T ModInverse(T n,T m) { return BigMod(n,m-2,m); }
//
/////==GeoMetry=========///
//double DEG(double x) { return (180.0*x)/(PI);}
//double RAD(double x) { return (x*(double)PI)/(180.0);}
//template<typename T> double DIS(T a,T b){ return sqrt((double)( SQR(a.X-b.X)+ SQR(a.Y-b.Y))); }
//template<typename T> T ANGLE(T a,T b){ return atan( double(a.Y-b.Y) / double(a.X-b.X));}
//template<typename T> int isLeft(T a,T b,T c) { return (c.X-a.X)*(b.Y-a.Y)-(b.X-a.X)*(c.Y-a.Y); }
//
/////===IO-Related===///
//template< class T > void prnt(T v) { fv(i,v) {if(!i)cout<<v[i];else cout<<" "<<v[i];} cout<<endl; }
//template< class T > void BIN(T n) { if(!n){nl;return;}BIN(n/2);cout<<(n%2); }
//template<typename T> T in(){ char ch; T n = 0; bool ng = false; while (1) { ch = getchar(); if (ch == '-') { ng = true; ch = getchar(); break;} if (ch>='0' && ch<='9') break; }    while (1) { n = n*10 + (ch - '0'); ch = getchar(); if (ch<'0' || ch>'9')   break;    }  return (ng?-n:n);  }
 
///====Some-Stuff===///
/// atoi( str.c_str() ); // char string to int
/// sprintf(str,"%d",num);// num to char string
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Year
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
 
/**************************************************************************************
 * ///////////////////////////////////////////////////////////////////////////////////*
 *************************************************************************************/
 
///==========CONSTANTS==============///
///  Digit     0123456789*#@%&^$"-  ///
#define MX     208
#define INF    100000000000000
#define MD     1000000007LL
#define EPS    1e-9
///================================///
 
const int mxr = 10009, mxc = 109;
double b[mxc], A[mxr][mxc];
 
void Pivot(int m, int n, double A[mxr][mxc], int *B, int *N, int r, int c) {
    int i, j;
    swap(N[c], B[r]);
    A[r][c] = 1.0 / A[r][c];
    for(j = 0; j <= n; j++) {
        if( j != c ) A[r][j] *= A[r][c];
    }
    for(i = 0; i <= m; i++) {
        if(i != r) {
            for(j = 0; j <= n; j++) {
                if(j != c) {
                    A[i][j] -= A[i][c] * A[r][j];
                }
            }
            A[i][c] = -A[i][c] * A[r][c];
        }
    }
}
 
int Feasible(int m, int n, double A[mxr][mxc], int *B, int *N) {
    int r, c, i;
    double p, v;
    while (true) {
        for(p = INF, i = 0; i < m; i++) {
            if(A[i][n] < p) {
                p = A[r = i][n];
            }
        }
        if(p > -EPS) {
            return 1;
        }
        for(p = 0, i = 0; i < n; i++) {
            if(A[r][i] < p) {
                p = A[r][c = i];
            }
        }
        if(p > -EPS) return 0;
        p = A[r][n] / A[r][c];
        for(i = r + 1; i < m; i++) {
            if(A[i][c] > EPS) {
                v = A[i][n] / A[i][c];
                if(v < p) {
                    r = i;
                    p = v;
                }
            }
        }
        Pivot(m, n, A, B, N, r, c);
    }
}
 
int Simplex(int m, int n, double A[mxr][mxc], double *b, double &Ret) {
    int B[mxr], N[mxc], r, c, i;
    double p, v;
    for(i = 0; i < n; i++) {
        N[i] = i;
    }
    for(i = 0; i < m; i++) {
        B[i] = n + i;
    }
    if (!Feasible(m, n, A, B, N)) {
        return 0;
    }
    while (true) {
        for(p = 0, i = 0; i < n; i++) {
            if(A[m][i] > p) {
                p = A[m][c = i];
            }
        }
        if(p < EPS) {
            for(i = 0; i < n; i++) {
                if(N[i] < n) {
                    b[N[i]] = 0;
                }
            }
            for(i = 0; i < m; i++) {
                if(B[i] < n) {
                    b[B[i]] = A[i][n];
                }
            }
            Ret = -A[m][n];
            return 1;
        }
        for( p = INF, i = 0; i < m; i++ ) {
            if(A[i][c] > EPS) {
                v = A[i][n] / A[i][c];
                if(v < p) {
                    p = v;
                    r = i;
                }
            }
        }
        if(p == INF) {
            return -1;
        }
        Pivot(m, n, A, B, N, r, c);
    }
}
 
pdd pp[MX + 5];
double Dis(int i, int j) {
    double xx = (pp[j].X - pp[i].X);
    xx *= xx;
    double yy = (pp[j].Y - pp[i].Y);
    yy *= yy;
    double ret = sqrt(xx + yy);;
    // cout<<ret<<endl;
    return ret;
}
int main() {
    int i, j, k, n;
    double ret;
    // cout << fixed << setprecision(2);
    S(n);
    fr(i, 0, n - 1) {
        cin >> pp[i].X >> pp[i].Y;
    }
    CLR(A);
    k = 0;
    fr(i, 0, n - 1) {
        fr(j, i + 1, n - 1) {
            A[k++][i] = 1.0;
            A[k - 1][j] = 1.0;
            A[k - 1][n] = Dis(i, j);
        }
    }
    fr(i, 0, n - 1)A[k][i] = 1.0;
    A[k][n] = 0.0;

    Simplex(k, n, A, b, ret);
    double ans = 0.0;
    for(i = 0; i < n; i++) {
        // cout << b[i] << " ";
        ans += b[i];
    }
    ans *= 2.0 * PI;
    cout << fixed << setprecision(9) << ans << endl;
    return 0;
}
