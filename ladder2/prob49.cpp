#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
using namespace std;
#define ll long long int
const double mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll val,i,cnt=2;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    for(i=2;i<n;i++)
    {
        val=a[i-1]+a[i-2];
        if(val==a[i])
            cnt++;
        else
            break;
    }
    ll mx=INT_MIN;
    mx=max(mx,cnt);
    cnt=0;
    for(++i;i<n;i++)
    {
        val=a[i-1]+a[i-2];
        if(val==a[i])
            cnt++;
        else
        {
            mx=max(mx,cnt+2);
            cnt=0;
        }
    }
    mx=max(mx,cnt+2);
    cout<<mx;
 return 0;
}
