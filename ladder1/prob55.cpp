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
        ll s=n;
        for(ll i=0;i<2*n+1;i++)
        {
            if(i<=n)
            {
                for(ll j=n;j>i;j--)
                    cout<<"  ";
                for(ll j=0;j<i+1;j++)
                    cout<<j<<" ";
                for(ll j=i;j>0;j--)
                    cout<<j-1<<" ";
            }
            else
            {
                for(ll j=n;j<i;j++)
                    cout<<"  ";
                for(ll j=0;j<s;j++)
                    cout<<j<<" ";
                for(ll j=s-2;j>=0;j--)
                    cout<<j<<" ";
                s--;
            }
            cout<<endl;
        }
 return 0;
}
