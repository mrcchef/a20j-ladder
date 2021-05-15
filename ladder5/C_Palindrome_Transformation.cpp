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

void solve()
{
    ll n,pos;
    cin>>n>>pos;
    ll i;
    string s;
    cin>>s;

    ll cost=0;

    fo(i,n/2)
    {
        if(s[i]!=s[n-i-1])
        {
            // cost+=abs(s[i]-s[n-i-1]);
            char tch=min(s[i],s[n-i-1]);
            char tch2=max(s[i],s[n-i-1]);
            ll cnt=abs('a'-tch);
            cnt+=abs('z'-tch2)+1;
            ll val=min(cnt,1ll*abs(s[i]-s[n-i-1]));
            cost+=val;
            // trace3(i,n-i-1,val);
        }
    }

    if(cost==0)
    {
        cout<<cost<<endl;
        return;
    }

    // ll fr=-1,ls=-1;
    // fo(i,n/2)
    // {
    //     if(s[i]!=s[n-i-1])
    //     {
    //         fr=i;
    //         break;
    //     }
    // }

    // for(i=n-1;i>n/2;i--)
    // {
    //     if(s[i]!=s[n-i-1])
    //     {
    //         ls=i;
    //         break;
    //     }
    // }

    ll lf1=-1,rt1=-1;
    ll lf,rt;
    i=0;
    while(i<n/2)
    {
        if(s[i]!=s[n-i-1])
        {
            if(lf1!=-1)
            {
                rt1=i;
            }
            else
                lf1=i;
        }
        i++;
    }

    ll mn=INT_MAX;

    // ll lf,rt;
    if(pos-1<n/2)
    {
        lf=lf1;
        rt=rt1;
    }
    else
    {
        lf=lf1==-1?-1:n-lf1-1;
        rt=rt1==-1?-1:n-rt1-1;
    }
    
    trace3(lf,rt,pos-1);
    if(lf==-1)
    {
        mn=min(mn,1ll*abs(rt-(pos-1)));
    }
    else if(rt==-1)
    {
        mn=min(mn,1ll*abs(lf-(pos-1)));
    }
    else
    {
        if(pos-1<=lf)
        {
            mn=min(mn,rt-(pos-1));
        }
        if(pos-1>=rt)
        {
            mn=min(mn,pos-1-lf);
        }
        if(pos-1>=lf && pos-1<=rt)
        {
            mn=min(mn,pos-1+rt-lf);
            mn=min(mn,rt-(pos-1)+rt-lf);
        }

    }



    trace2(cost,mn);

    cout<<cost+mn<<endl;


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