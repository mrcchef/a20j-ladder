#include <iostream>
#include <vector>
#include <string>
#include <map>
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
    string s;
    cin>>s;
    map<char,ll> m;
    for(ll i=0;i<s.size();i++)
    {
        m[s[i]]++;
        m[s[i]]%=2;
    }
    ll ones=0;
    for(auto it=m.begin();it!=m.end();it++)
        if(it->second==1)
            ones++;
    // for(auto it=m.begin();it!=m.end();it++)
    //     cout<<it->second<<" ";
    // cout<<endl;
    ll sz=s.size();
    ll turn=0;
    while(sz>0)
    {
        
        if((sz&1==0) && ones==0)
            break;
        else if((sz&1==1) && ones==1)
            break;
        sz--;
        ones--;
        turn++;
    }
    if(turn%2==0)
        cout<<"First";
    else    
        cout<<"Second";
    cout<<endl;
 return 0;
}
