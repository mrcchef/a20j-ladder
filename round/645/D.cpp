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
// https://www.youtube.com/watch?v=DbDkQaXGLxg
int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll> a(2*n+1),sum(2*n+1),sd(2*n+1);
    sum[0]=a[0]=sd[0]=0;
    for(ll i=1;i<=2*n;i++)
    {
        if(i<=n)
            cin>>a[i];
        else
        {
            a[i]=a[i-n];
        }
        sum[i]=sum[i-1]+a[i];
        sd[i]=sd[i-1]+(a[i]*(a[i]+1))/2;
    }
    ll res=0;
    ll en;
    for(ll i=1;i<=n;i++)
    {
        en=lower_bound(sum.begin(),sum.end(),x+sum[i-1])-sum.begin();
        // cout<<"en "<<en<<endl;
        if(en==i)
        {
            ll cur=(a[i]*(a[i]+1))/2;
            ll left=a[i]-x;
            ll rem=(left*(left+1))/2;
            cur-=rem;
            res=max(res,cur);
        }
        else
        {
            ll cur=sd[en-1]-sd[i-1];
            ll left=x-(sum[en-1]-sum[i-1]);
            ll rem=(left*(left+1))/2;
            cur+=rem;
            ll extra=min(a[i]-1,a[en]-left);
            cur+=extra*left;
            // cout<<"cur "<<cur<<endl;
            res=max(res,cur);
        }
        
    }
    cout<<res<<endl;
    // for(int k=0;k<=2*n;k++)
    // {
    //     cout<<sum[k]<<" "<<sd[k]<<endl;
    // }
 return 0;
}
