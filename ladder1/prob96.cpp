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

        ll x,y,n;
        cin>>x>>y>>n;
        ll dp[6]={0};
        dp[0]=x;
        dp[1]=y;
        for(ll i=2;i<6;i++)
            dp[i]=dp[i-1]-dp[i-2];
        ll val=fmod(n,6),res=0;
        if(val==0)
            val=6;
        // if(n==1)
        //     res=fmod(fmod(x,mod)+mod,mod);
        // if(n==2)
        //     res=fmod(fmod(y,mod)+mod,mod);
        // else
            res=fmod(fmod(dp[val-1],mod)+mod,mod);
        cout<<res<<endl;
    
 return 0;
}
