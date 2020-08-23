#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long int
#define mod 1e9+7

ll fxp(ll a,ll b,ll m)
{
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}

void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

int main() {
	// your code goes here
	ll a[3][3],b[3][3];
    for(ll i=0;i<3;i++)
    {
        for(ll j=0;j<3;j++)
        {
            b[i][j]=1;
            cin>>a[i][j];
        }    
    }
    for(ll i=0;i<3;i++)
    {
        for(ll j=0;j<3;j++)
        {
            if(a[i][j]%2==1)
            {
                if(b[i][j]==1)
                    b[i][j]=0;
                else
                    b[i][j]=1;
                if(i+1<3)
                {
                    if(b[i+1][j]==1)
                        b[i+1][j]=0;
                    else
                    {
                        b[i+1][j]=1;
                    }
                }
                if(i-1>=0)
                {
                    if(b[i-1][j]==1)
                        b[i-1][j]=0;
                    else
                    {
                        b[i-1][j]=1;
                    }
                }
                if(j+1<3)
                {
                    if(b[i][j+1]==1)
                        b[i][j+1]=0;
                    else
                    {
                        b[i][j+1]=1;
                    }
                }
                if(j-1>=0)
                {
                    if(b[i][j-1]==1)
                        b[i][j-1]=0;
                    else
                    {
                        b[i][j-1]=1;
                    }
                }
            }
            
        }
    }
    for(ll i=0;i<3;i++)
    {
        for(ll j=0;j<3;j++)
            cout<<b[i][j];
        cout<<"\n";
    }
    return 0;
}
