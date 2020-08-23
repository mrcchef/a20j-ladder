#include <iostream>
#include <vector>
#include <map>
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

string repeat(string s, int n) 
{ 
    // Copying given string to temparory string. 
    string s1 = s; 
  
    for (int i=1; i<n;i++) 
        s += s1; // Concatinating strings 
  
    return s; 
} 

int main()
{
        ll k;
        cin>>k;
        string s;
        cin>>s;
        map<char,ll> m;
        for(ll i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            ll x=(it->second)%k;
            if(x!=0)
            {
                cout<<-1;
                return 0;
            }
            it->second=(it->second)/k;
        }
        string v;
        for(auto it=m.begin();it!=m.end();it++)
        {
            ll x=it->second;
            while(x>0)
            {
                v=v+(it->first);
                x--;
            }   
        }
        cout<<repeat(v, k) << endl;
}
