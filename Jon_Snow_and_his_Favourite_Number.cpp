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

ll msum(ll array,ll b,ll m) { return (array%m+b%m)%m; }
ll msub(ll array,ll b,ll m) { return (array%m-b%m)%m; }
ll mpro(ll array,ll b,ll m) { return ((array%m)*(b%m))%m; }
ll fxp(ll array,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(array*array,b/2,m);
    return fxp(array,b-1,m)*array;
}
void swap(ll &array,ll &b){ ll t=array; array=b; b=t;}

int main()
{
    ll n,k,x;
    cin>>n>>k>>x;
    ll *freq=new ll[1500](); // this syntax intialize freq array with 0;
    for(ll i=0;i<n;i++)
    {
        ll t;
        cin>>t;
        freq[t]++;
    }
    ll *temp=new ll[1500]();
    
    for(ll i=0;i<1500;i++)
            temp[i]=freq[i];

    while(k--)
    {
        ll flag=1;
        for(ll i=0;i<1500;i++)
        {
            if(freq[i]>0)
            {
                ll new_val=i^x;
                ll change_val=freq[i]/2;
                if(flag==1)
                {
                    change_val+=(freq[i]&1);
                }
                temp[i]-=change_val;
                temp[new_val]+=change_val;
                if(freq[i]&1)
                    flag*=-1;
            }
        }        
        for(ll i=0;i<1500;i++)
            freq[i]=temp[i];
    }
    ll ma=INT_MIN,mi=INT_MAX;
    for(ll i=0;i<1500;i++)
    {
        if(freq[i]>0)
        {
            ma=max(ma,i);
            mi=min(mi,i);
        }
    }
    cout<<ma<<" "<<mi;
 return 0;
}
