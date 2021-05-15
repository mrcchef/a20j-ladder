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

vector<vector<ll>> res(50);

class Graph{
    ll V;
    ll **l;
    bool *visited;
    public:
        Graph(ll V)
        {
            this->V=V;
            l=new ll*[V+1];
            for(ll i=1;i<=V;i++)
            {
                l[i]=new ll[V+1];
                for(ll j=1;j<=V;j++)
                {
                    l[i][j]=0;
                }       
            }
            visited=new bool[V+1]{false};
        }

        void add_edge(ll x,ll y)
        {
            l[x][y]=l[y][x]=1;
        }

        void dfs_helper(ll src,vi tm)
        {
            visited[src]=true;
            tm.pb(src);
            cout<<src<<"-->";

            for(ll i=1;i<=V;i++)
            {
                if(!visited[i] && l[src][i]==1)
                {
                    dfs_helper(i,tm);
                }
            }
        }

        void DFS()
        {
            for(ll node=1;node<=V;node++)
            {
                cout<<node<<": ";
                vi tm;
                for(ll nbr=1;nbr<=V;nbr++)
                {
                    if(l[node][nbr]==1 && !visited[nbr])
                    {
                        dfs_helper(nbr,tm);
                    }
                }
                
                cout<<endl;
            }
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
        ll v,e,i,x,y;
        cin>>v>>e;
        Graph g(v);
        ll check[v+1]={0};
        fo(i,e)
        {
            cin>>x>>y;
            check[x]=check[y]=1;
            g.add_edge(x,y);
        }
        g.DFS();

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