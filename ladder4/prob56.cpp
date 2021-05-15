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

bool check(string s,ll len)
{
    ll j,v;
    
    for(ll i=0;i+len<s.size();i++)
    {
        ll flag=1;
        for( j=i;j<i+len;j++)
        {
            if(s[j]!=s[j+len] && !(s[j+len]=='?' || s[j]=='?'))
            {
                flag=0;
                break;
            }    
        }
        if(flag==1)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        string s;
        ll k,ans=0;
        cin>>s;
        ll n=s.size();
        cin>>k;
        if(n<=k)
        {
            if((n+k)&1)
                cout<<n+k-1;
            else
                cout<<n+k;
            return 0;
        }
        for(ll i=0;i<k;i++)
        {
            s+='?';
        }
        n+=k;
        for(ll len=n/2;len>=1;len--)
        {
            for(ll i=0;i+2*len<=n;i++)
            {
                ll flag=1;
                for(ll j=i;j<i+len;j++)
                {
                    if(s[j]==s[j+len] || s[j+len]=='?' || s[j]=='?')
                        continue;
                    flag=0;
                    break;
                }
                if(flag==1)
                {
                    ans=len;
                    break;
                }
            }
            if(ans!=0)
                break;
        }
        cout<<2*ans<<endl;
        
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