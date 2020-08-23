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

ll solve(string &s,string str,ll i,ll n,ll k,ll cnt)
{
    if(i==n)
        return cnt;
    
    if(i<n-1)
    {
        if(s[i]==s[i-1])
        {
            if(k==2)
            {
                for(ll j=0;j<k;j++)
                {
                    if(str[j]!=s[i])
                    {
                        s[i]=str[j];
                        break;
                    }
                }
            }
            else
            {
                for(ll j=0;j<k;j++)
                {
                    if(str[j]!=s[i] && str[j]!=s[i+1])
                    {
                        s[i]=str[j];
                        break;
                    }
                }
            }    
        return solve(s,str,i+1,n,k,cnt+1);
        }
    }
    if(s[i]==s[i-1])
    {
        for(ll j=0;j<k;j++)
        {
            if(str[j]!=s[i])
            {
                s[i]=str[j];
                break;
            }
        }
        return solve(s,str,i+1,n,k,cnt+1);
    }
    return solve(s,str,i+1,n,k,cnt);
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    string s;
    cin>>n>>k>>s;
    string str;
    for(ll i=0;i<k;i++)
        str+=65+i;
    if(n==1)
    {
        cout<<0<<endl<<s;
        return 0;
    }
    cout<<solve(s,str,1,n,k,0)<<endl<<s;
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
