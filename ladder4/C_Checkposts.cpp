#include <bits/stdc++.h>
using namespace std;
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
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

const ll N=1e5+5;

vector<vi> g(N);
vector<vi> tg(N);
vi visited(N);
vi cost(N);
ll timer=0;
mii hm;
ll in_time[N],out_time[N];
ll mn,cnt;

void dfs1(ll node)
{
    timer++;
    visited[node]=1;
    in_time[node]=timer;

    for(auto nbr:g[node])
    {
        if(!visited[nbr])
        {
            dfs1(nbr);
        }
    }
    timer++;
    out_time[node]=timer;
    hm[-timer]=node;
}

void dfs2(ll node)
{
    // cout<<node<<" ";
    visited[node]=1;
    if(mn>cost[node])
    {
        mn=cost[node];
        cnt=1;
    }
    else if(mn==cost[node])
    {
        cnt++;
    }

    for(auto nbr:tg[node])
    {
        if(!visited[nbr])
        {
            dfs2(nbr);
        }
    }
}

void solve()
{
    ll n,m,i;
    cin>>n;
    fo(i,n)
    {
        cin>>cost[i+1];
    }

    cin>>m;

    fo(i,m)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        tg[y].pb(x);
    }
    
    Fo(i,1,n)
        if(!visited[i])
            dfs1(i);

    fo(i,n+1)
        visited[i]=0;

    ll ans_cost=0,num=1;

    for(auto it:hm)
    {
        // cout<<it.second<<" "<<-it.first<<endl;
        ll node=it.second;
        if(!visited[node])
        {
            mn=INT_MAX;
            cnt=0;
            dfs2(node);
            ans_cost+=mn;
            num*=cnt;
            num%=mod;
        }
    }
    cout<<ans_cost<<" "<<num<<endl;
}

int main()
{
    fastio
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();   
    }
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