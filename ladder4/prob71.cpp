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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,l,x,y,i,j;
        cin>>n>>l>>x>>y;
        vi v;
        vi res;
        mii m;
        fo(i,n)
        {
            ll tm;
            cin>>tm;
            v.pb(tm);
            m[tm]=1;
        }

        ll check_x=0,check_y=0,res1=-1;

        for(i=0;i<n;i++)
        {
            if(m[v[i]+x])
                check_x=1;
            if(m[v[i]+y])
                check_y=1;
            if(m[v[i]+y+x] && res1==-1)
            {
                res1=v[i]+y;
            }
            if(m[v[i]+y-x] && res1==-1)
            {
                if(v[i]+y<=l)
                    res1=v[i]+y;
                if(v[i]-x>=0)
                    res1=v[i]-x;
            }
        }   

        if(check_x&&check_y)
            cout<<0;
        else if(check_x)
            cout<<1<<endl<<y;
        else if(check_y)
            cout<<1<<endl<<x;
        else if(res1!=-1)
            cout<<1<<endl<<res1;
        else
        {
            cout<<2<<endl;
            cout<<x<<" "<<y;
        }
        cout<<endl;
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