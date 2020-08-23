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
        ll n;
        cin>>n;
        if(n%2==1)
        {
            cout<<-1;
            return 0;
        }
        int a[n+1]={0};
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                if(a[j]==0 && i!=j)
                {
                    cout<<j<<" ";
                    a[j]=1;
                    break;
                }
            }
        }
 return 0;
}
