#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
#define deb1(x)                cout<<#x<<": "<<x<<endl
#define deb2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cout<<#x<<":"<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<" : "<<f<<endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

ll n;
vi v;

const ll N=1e7;
vi prime;
bool check[N+1];
ll hm[N+1];

ll preCal[N+1];

void cal()
{
    for(ll i=1;i<=N;i++)
        check[i]=true;
    
    check[0]=check[1]=false;
    
    for(ll i=2;i<=N;i++)
    {
        if(check[i]==1)
        {
            for(ll j=i*i;j<=N;j+=i)
            {
                check[j]=0;
            }
        }
    }

    // prime.pb(1);

    for(ll i=2;i<=N;i++)
    {
        if(check[i]==1)
            prime.pb(i);
    } 

    for(auto p:prime)
    {
        for(ll j=p;j<=N;j+=p)
        {
            if(hm[j])
            {
                preCal[p]+=hm[j];
            }
        }
    }

    for(ll i=1;i<=N;i++)
    {
        preCal[i]=preCal[i]+preCal[i-1];
    }

}


void solve()
{
    ll i;
    cin>>n;
    v.resize(n);
    fo(i,n)
        cin>>v[i],hm[v[i]]++;

    cal();

    ll m;
    cin>>m;
    fo(i,m)
    {
        ll l,r;
        cin>>l>>r;
        if(l>N)
        {
            cout<<0<<endl;
            continue;
        }
        ll ans=0;
        r=min(N,r);
        ans=preCal[r]-preCal[l-1];
        cout<<ans<<endl;
    }


}


int main()
{
    fastio
    int t=1;
    // auto start1 = high_resolution_clock::now();

    while(t--)
    {
        solve();   
    }
	// auto stop1 = high_resolution_clock::now();
	// auto duration = duration_cast<microseconds>(stop1 - start1);
	// cerr << "Time: " << duration . count() / 1000 << endl;
 return 0;
}

ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(m_m(a,a,m),b/2,m);
    return m_m(fxp(a,b-1,m),a,m);
}
ll m_m(ll a,ll b,ll m) 
{
    ll res=0;
    a=a%m;
    while(b)
    {
        if(b&1)
        {
            res+=a; 
            res=res%m;
        }
        a=(a*2)%m;
        b=b/2;
    }
    return res;
}