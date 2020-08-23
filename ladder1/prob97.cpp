#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <algorithm>
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
        string s;
        cin>>s;
        vector<ll> v(26,0);
        for(ll i=0;i<s.size();i++)
            v[s[i]-'A']++;
        sort(v.begin(),v.end(),greater<ll>());
        ll res=0;
        for(ll i=0;i<v.size();i++)
        {
            if(v[i]<=k)
            {
                res+=v[i]*v[i];
                k=k-v[i];
            }
            else
            {
                res+=k*k;
                break;
            }
        }
        cout<<res<<endl;
    
 return 0;
}
