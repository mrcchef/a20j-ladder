#include <iostream>
#include <vector>
// #include <map>
// #include <unordered_map>
// #include <climits>
// #include <math.h>
// #include <string>
#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define deb(x) cout << #x << "=" << x << endl
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

ll solve(ll sz)
{
    ll num=0;
    ll i=0;
        for(i=0;i<sz/2;i++)
        {
            num=num*10+4;
        }
        for(i;i<sz;i++)
        {
            num=num*10+7;
        }
    return num;
}

int main()
{
    ll n;
    cin>>n;
    ll sz=log10(n)+1;
    ll num=0;
    if(sz&1)
    {
        num=solve(sz+1);
    }   
    else
    {
        ll no=0,t=n,cnt4=0,cnt7=0,flag=0,four=0,seven=0;
        for(ll i=sz-1;i>=0;i--)
        {
            ll lt=t/fxp(10,i,mod);
            if(lt<=4 && cnt4<sz/2)
            {
                cnt4++;
                if(lt!=4)
                    four++;
            }
            else if(lt<=7 && cnt7<sz/2)
            {
                cnt7++;
                if(lt!=7)
                    seven++;
            }
            else
            {
                if(seven && cnt4<sz/2)
                {
                    cnt4++;
                    four++;
                }
                else
                {
                    sz=sz+2;
                    flag=1;
                    break;    
                }
            }
            // deb(seven);
            
            // deb(t);  
            t=t-lt*fxp(10,i,mod); 
            
        }
        // deb(cnt4);
        // deb(cnt7);
        ll temp4=four;
        if(flag==1)
        {
            num=solve(sz);
        }
        else
        {
            for(ll i=sz-1;i>=0;i--)
            {
                ll lt=n/fxp(10,i,mod);
                // deb(lt);
                if(lt<=4 && cnt4)
                {
                    if(lt!=4)
                    {
                        if(temp4!=four)
                        {
                            if(i&1)
                            {
                                num=num*fxp(10,i+1,mod)+solve(i+1);
                            }
                            else
                            {
                                num=num*10+4;
                               num=num*fxp(10,i,mod)+solve(i); 
                            }
                            break;
                        }
                        num=num*10+4;
                        temp4--;
                    }
                    else
                    {
                        num=num*10+4;
                    cnt4--;    
                    }
                    
                }
                else
                {
                    if(lt<=7)
                    {
                        if(lt!=7)
                        {
                            num=num*10+7;
                            num=num*fxp(10,i,mod)+solve(sz-i);
                            break;
                        }
                        num=num*10+7;
                        cnt7--;
                    }

                }
                // deb(cnt4);
                // deb(cnt7);
                n=n-lt*fxp(10,i,mod);
            }
        }   
    }
    cout<<num<<endl;
 return 0;
}
