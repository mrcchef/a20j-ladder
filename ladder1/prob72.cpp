#include <iostream>
#include <vector>
#include <string>
#include <climits>
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
        ll i,j,k;
        vector<pair<ll,ll>> v;
        for(i=0;i<n;i++)
        {
            cin>>j>>k;
            v.push_back({j,k});
        }
        ll ma=INT_MIN,mi=INT_MAX;
        for(auto it=v.begin();it!=v.end();it++)
        {
            ma=max(ma,it->second);
            mi=min(mi,it->first);
        }
        ll cnt=0;
        for(auto it=v.begin();it!=v.end();it++)
        {
            cnt++;
            if(it->first==mi && it->second==ma)
            {
                cout<<cnt<<endl;
                return 0;
            }
        }
        if(cnt==v.size())
            cout<<-1;
        cout<<endl;
        
 return 0;
}
