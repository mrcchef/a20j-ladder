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
    
        ll n;
        cin>>n;
        ll a[n],b[n];
        ll k=-1,sum1=0,sum2=0;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
            sum1+=a[i];
            sum2+=b[i];
            if(((a[i]&1)==1 && (b[i]&1)==0)||((a[i]&1)==0 && (b[i]&1)==1))
                k=i;   
        }
        if((sum1&1==1) && (sum2&1==1))
        {
            if(n==1)
                cout<<-1;
            else if(k!=-1)
                cout<<1;
            else
                cout<<-1;
        }
        else if((sum1&1)==0 && (sum2&1)==0)
            cout<<0;
        else
        {
            cout<<-1;
        }

    
 return 0;
}
