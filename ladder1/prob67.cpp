#include <iostream>
#include <vector>
#include <map>
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
        map<ll,ll> m;
        ll j;
        for(ll i=1;i<=n;i++)
        {
            cin>>j;
            m[j]++;
        }
        // for(ll i=1;i<=7;i++)
        //     cout<<m[i]<<" ";
        //     cout<<endl;
        if(m[5]>0 || m[7]>0)
        {
             cout<<-1;
            return 0;
        }   
        if(m[3]>m[1] || m[3]>m[6])
        {
            cout<<-1;
            return 0;
        }
        ll x=m[2]+m[3]+m[4]+m[6];
        if(m[1]!=x/2)
        {
            cout<<-1;
            return 0;
        }   
        if(m[2]+m[3]!=m[4]+m[6])
        {
            cout<<-1;
            return 0;
        }  
        while(m[4]!=0)
        {
            cout<<"1 2 4"<<endl;
            m[4]--;
            m[2]--;
            m[1]--;
        }
        while(m[6]!=0 && m[2]!=0)
        {
            cout<<"1 2 6"<<endl; 
            m[6]--;
            m[2]--;
            m[1]--;       
        }
        while(m[6]!=0 && m[3]!=0)
        {
            cout<<"1 3 6"<<endl;
            m[6]--;
            m[1]--;
            m[3]--;
        }
    
 return 0;
}
