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
    
        ll n,k;
        cin>>n>>k;
        vector<ll> v;
        ll j;
        for(ll i=0;i<n;i++)
        {
            cin>>j;
            v.push_back(j);
        }    
        auto itt=v.begin()+k-1;
        ll val=*itt;
        ll i=0;
        ll flag=0;
        if(k>1)
        {
            for(ll it=k-2;it>=0;it--)
            {
                i++;
                if(v[it]!=val)
                {
                    flag=1;
                    break;
                }    
            }
        } 
        ll cnt=0;
        if(flag==1)
            cnt=k-i;
        for(itt++;itt!=v.end();itt++)
        {
            if(*itt!=val)
            {
                cnt=-1;
                break;
            }
        }
        cout<<cnt<<endl;
 return 0;
}
