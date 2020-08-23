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
// Logic is simple we will iterate all the pairs and for each pair we will check that if freq. of 
//first element of that pair is zero in 2nd column that means that patricular brand of 
//bollte can not be able to open in any case and if two values of same pair are equal 
//then we will subtract the freq by 1 b/c a bottle can not be opened by itself.

int main()
{
        ll n,j,k;
        cin>>n;
        vector<pair<ll,ll>> vp;
        ll secd[1001]={0};
        for(ll i=0;i<n;i++)
        {
            cin>>j>>k;
            vp.push_back({j,k});
            secd[k]++;
        }
        ll cnt=0;
        for(auto it=vp.begin();it!=vp.end();it++)
        {
            secd[it->second]--; 
            if(secd[it->first]==0)
            {
                cnt++;
            }
            secd[it->second]++;
        }
        cout<<cnt<<endl;
    
 return 0;
}
