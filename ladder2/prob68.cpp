#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb puah_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
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
    int n;
    cin>>n;
    ll a[n];
    ll cnt=0;
    bool visited[n]={false};
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==i)
        {
            cnt++;
            visited[i]=true;
        }    
    }
    // cout<<"cnt "<<cnt<<endl; 
    ll val=0;
    for(ll i=0;i<n;i++)
    {
        if(a[i]!=i && !visited[a[i]] && !visited[a[a[i]]])
        {
            if(i==a[a[i]])
            {
                val=2; 
                // cout<<"i "<<i<<" cnt "<<cnt<<endl;
            swap(a[i],a[a[i]]);
            visited[a[i]]=visited[a[a[i]]]=true;
            }
            // else
            // {
            //     cnt++;
            // }
            
        }
    }
    if(val==0 && cnt<n)
        cout<<cnt+1<<endl;
    else
    {
        cout<<cnt+val<<endl;
    }
    
 return 0;
}
