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
    ll n,m;
    cin>>n>>m;
    ll min,max;
    max=m;
    min=m/2;
    if(!(m&1))
    {
        min--;
    }
    // deb(min);
    if(n>=min && n<=max)
    {
        string s;
        while(m>n+1)
        {
            if(m>=2)
            {
                s+="11";
                m-=2;
            }    
            if(n>=1)
            {
                s+="0";
                n-=1;
            }    
        }
        while(m>0)
        {
            if(m>=1)
            {
                s+="1";
                m--;
            }
            if(n>0)
            {
                s+="0";
                n--;
            }
        }
        cout<<s<<endl;
    }
    else if(m==n-1)
    {
        string s="0";
        while(m)
        {
            s+="10";
            m--;
        }
        cout<<s<<endl;
    }
    else
    {
        cout<<-1;
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