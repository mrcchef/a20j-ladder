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

       ll n,sum=0,j;
       cin>>n;
       vector<ll> v={1,2,3,4,5};
       for(ll i=0;i<n;i++)
       {
           cin>>j;
           sum+=j;
       }
       ll cnt=0;
       for(ll i=0;i<5;i++)
       {
           ll x=(sum+v[i])%(n+1);
           if(x!=1)
                cnt++;
       }
    cout<<cnt<<endl;

}
