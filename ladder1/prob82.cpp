#include <iostream>
#include <vector>
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
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll i=1,j,cnt=0,c=0;
        while(i<n)
        {
            j=i;
            c=0;
            while(c<=n)
            {
                j++;
                b=
                c=fxp(j,2,mod)+fxp(i,2,mod);
                cout<<c<<" ";
                if(c<=n)
                    cnt++;
            }
            i++;
        }
        cout<<cnt<<endl;
    }
 return 0;
}
