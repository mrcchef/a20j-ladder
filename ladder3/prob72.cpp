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
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

ll LCM(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i;
    cin>>n;
    ll ans=INT_MIN;
    if(n<=2)
    {
        cout<<n;
        return 0;
    }
    if(n&1)
    {
        ans=n*(n-1)*(n-2);
    }
    else
    {
       // Since we know that for n to be even, there some issues
       // n*(n-1)*(n-2) then n-2 and n both are multiple of 2
       // n*(n-1)*(n-3) then n-3 and n may be multiple of 3 until n-3 or n are not prime n0.
       // similary we can also go gor (n-1)(n-2)(n-3) that means there are alot possibilities
       // since we know that as n increases the density of primes start decreasing
       // the number of primes not exceeding x is approx. x/lnx;
       // thats why we took a range of last 100 numbers 
       
       for(ll i=n;i>=max(n-100,1LL);i--)
       {
           for(ll j=i-1;j>=max(n-100,1LL);j--)
           {
               for(ll k=j-1;k>=max(n-100,1LL);k--)
               {
                   ans=max(ans,LCM(LCM(i,j),k));
               }
           }
       }
    }
    cout<<ans<<endl;
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
