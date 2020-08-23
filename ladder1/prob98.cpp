#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
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

// bool comp(vector<ll> &v1,vector<ll> &v2)
// {
//     return v1>v2;
// }    

int main()
{
    
        ll n;
        cin>>n;
        vector<ll> v;
        ll j;
        for(ll i=0;i<n;i++)
        {
            cin>>j;
            v.push_back(j);
        }
        ll start=0,end=0,flag=1;
        vector<ll> temp;
        for(ll i=0;i<n-1;i++)
        {
            if(v[i]>v[i+1])
            {
                if(flag==1)
                {
                    start=i;
                    flag=0;
                }
                temp.insert(temp.begin(),v[i]);
            }
            if(v[i]<v[i+1] && flag==0)
            {
                end=i;
                flag=1;
                temp.insert(temp.begin(),v[i]);
                break;
            }
        }
        if(end==0 && start==0)
        {
            if(temp.size()!=0)
            {
                end=n-1;
                temp.insert(temp.begin(),v[n-1]);
            }
        }
        ll i=0;
        flag=0;
        while(i<temp.size())
        {
            v[start+i]=temp[i];
            i++;
        }
        for(ll i=1;i<n;i++)
        {
            if(v[i-1]>v[i])
            {
               flag=1; 
               break;
            }    
        }
        if(flag==0)
        {
            cout<<"yes"<<endl;
            cout<<start+1<<" "<<end+1;
        }
        else
            cout<<"no";
 return 0;
}
