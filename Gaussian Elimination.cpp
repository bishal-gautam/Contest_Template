
///  (LightOj 1278: Graph Coloring) 

#include<bits/stdc++.h>
#define PI acos(-1.0)
#define nl puts("")
#define SZ(x) x.size()
#define pb(x) push_back(x)
#define X first
#define Y second
#define pii pair<int,int>
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define all(v) v.begin(),v.end()
#define clr(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(i=a;i<=n;i++)
#define rf(i,n,a) for(i=n;i>=a;i--)
#define LB(v,k) lower_bound(v.begin(),v.end(),k)
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
#define ct(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define fi(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
using namespace std;
typedef long long ll;
/// atoi( str.c_str() ); // char string to int
/// sprintf(str,"%d",num);// num to char string
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Yr
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Dir
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Dir
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight
/************************************************************************
 * /////////////////////////////////////////////////////////////////////*
 ************************************************************************/
/// [ Look at my code below, My code is so amazing !! :P ]
/// Digit   012345678910
#define MX  105
#define inf 100000005

const ll MD = 1000000007LL;
ll mat[MX][MX], sol[MX], K;
int r, c;
bool vis[MX];
vector<ll>G[MX + 5];

ll BigMod(ll base, ll power, ll MOD) {
    ll ret = 1LL;
    while(power) {
        if(power & 1LL)
            ret = (ret * base) % MOD;
        base = (base * base) % MOD;
        power >>= 1LL;
    }
    return ret;
}

int Find_Nrow(int rw, int cl) {
    for(int i = rw; i < r; i++)if(mat[i][cl] != 0)return i;
    return -1;
}

void Swap_Rows(int r1, int r2, int cl) {
    for(int j = cl; j < c; j++)swap(mat[r1][j], mat[r2][j]);
}

void Print_Mat( ) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++ ) {
            cout << mat[i][j] << " ";
        }
        nl;
    }
}

ll Find_Sol( ) {
    int cnt = 0;
    int rnk = 0;
    //Print_Mat();
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++ ) {
            if(mat[i][j]) {
                rnk++;
                break;
            }
        }
    }
    ll inde_var = (r - rnk);
    return BigMod(K, inde_var, MD);
}

ll Gauss( ) {
   // Print_Mat();
    for(int cl = 0, rw = 0; cl < c ; cl++, rw++ ) {
        int sr = Find_Nrow(rw, cl);
        if(sr == -1) {
            rw--;
            continue;
        } else if(sr != rw) Swap_Rows(rw, sr, cl);
        for(int i = rw + 1; i < r ; i++ ) {
            if(mat[i][cl] == 0)continue;
            ll rat = ( mat[i][cl] * BigMod( mat[rw][cl], K - 2, K ) + K) % K;
            for(int j = cl ; j < c ; j++) {
                mat[i][j] = (mat[i][j] - (rat * mat[rw][j] + K) % K + K) % K;
            }
        }
    }
    return (Find_Sol( ));
}

int main() {
    int tc, n, m, cs = 1, i, j, u, v;
    S(tc);
    while(tc--) {
        S2(n, m);
        SL(K);
        r = c = n;
        for(int i = 0; i < m; i++) {
            S2(u, v);
            G[u - 1].pb(v - 1);
            G[v - 1].pb(u - 1);
        }
        for(int i = 0; i < n; i++) {
            mat[i][i] = 1;
            int sz = G[i].size();
            for(int j = 0; j < sz; j++) {
                v = G[i][j];
                mat[i][v] = (K - 1);
            }
        }
        ll ans = Gauss();
        printf("Case %d: %lld\n", cs++, ans);
        fr(i, 0, n - 1)G[i].clear();
        clr(mat);
    }
    return 0;
}
