#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
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

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

class Graph{
    ll V;
    list<pair<ll,ll>> *l;
    // ll cnt;
    public:
        Graph(ll V)
        {
            // cnt=0;
            this->V=V;
            l=new list<pair<ll,ll>>[V+1];
        }

        void add_edge(ll x,ll y,ll c)
        {
            l[x].pb({y,c});
            l[y].pb({x,c});
        }

        void dfs_helper(pair<ll,ll> src,ll visited[105][105],ll req,ll &cnt)
        {

            visited[src.first][src.second]=1;

            if(src.first==req)
            {
                cnt++;
                return;
            }

            for(auto nbr:l[src.first])
            {
                ll cost=nbr.second;
                if(visited[nbr.first][nbr.second]==0 && src.second==cost)
                {
                    dfs_helper(nbr,visited,req,cnt);
                }
            }
        }

        ll DFS(ll st,ll ed)
        {
            ll cnt=0;
            ll visited[105][105];
            memset(visited,0,sizeof(visited));
            // ll prev=-1;
            // for(ll i=1;i<=V;i++)
            // {
            //     visited[i]=false;
            // }

            for(auto nbr:l[st])
            {
                if(!visited[nbr.first][nbr.second])
                {
                    visited[nbr.first][nbr.second]=1;
                    dfs_helper(nbr,visited,ed,cnt);    
                }
            }

            return cnt;
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll v,e,i;
        cin>>v>>e;
        Graph g(v);
        fo(i,e)
        {
            ll x,y,c;
            cin>>x>>y>>c;
            g.add_edge(x,y,c);
        }
        ll q;
        cin>>q;
        fo(i,q)
        {
            ll x,y;
            cin>>x>>y;
            cout<<g.DFS(x,y)<<endl;
        }

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