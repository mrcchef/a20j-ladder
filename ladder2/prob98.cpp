#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define deb(x) cout << #x << "=" << x << endl
const ll MOD = 1e9+7;

// In case someone did not understand the editorial of 166E — Tetrahedron, here is a simple way of looking at the solution : zD is the number of ways of 
// reaching D in i steps and zABC is the number of ways of reaching A or B or C in i steps(A , B, C are equivalent points). 
// Since the ant starts of from D, initially (at i = 0) zD = 1 and zABC = 0.

// Now in each subsequent step, 2 things can occur :

// If the ant was at D, it will come down to any of the A,B,C points. That means it has 3 options. Hence , nzABC = zD.

// If the ant was at either of the A,B,C positions, it can either climb upto point D or go to any of the 2 other equivalent points i.e.
// if the ant was at A, it can go to D and hence nzD= 3*nzABC ; or it can go to either B or C (2 available options) which increases nzABC by 2*zABC and
// hence nzABC += 2*zABC.
// This can also be solved using matrix exponentiation 
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
    int zD = 1;
    int zABC = 0;
    for (int i = 1; i <= n; i++) 
    {
	    int nzD = zABC * 3LL % MOD;
	    int nzABC = (zABC * 2LL + zD) % MOD;
    	zD = nzD;
	    zABC = nzABC;
    }
    cout << zD;
 return 0;
}