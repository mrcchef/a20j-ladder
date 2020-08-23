#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long int
#define mod 1e9+7

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
    
        ll a,b,n;
        cin>>n>>a>>b;
        n=n-a;
        n--;
        ll cnt=0;
        while(n!=-1)
        {
            if(n<=b)
                cnt++;
            n--;
        }
        cout<<cnt;
    
 return 0;
}
