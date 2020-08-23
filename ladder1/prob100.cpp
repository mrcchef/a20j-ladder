#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
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
// Here the logic is very simple b/c if we found any number which is divisible by any other 
//number then adding zero in decimal expansion would not change the divisibility of that number
int main()
{
    
        ll a,b,n,t;
        cin>>a>>b>>n;
        t=a;
        for(ll i=0;i<10;i++)
        {
            if((t*10+i)%b==0)
            {
                t=t*10+i;
                break;
            }    
        }
        if(t==a)
        {
            cout<<-1;
            return 0;
        }
        a=t;
        cout<<a;
        for(ll i=1;i<n;i++)
            cout<<0;
    
 return 0;
}
