#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
 
 
ll Ways_BU(ll n)
{
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
 
    for (ll i = 2; i <= n; i++)
    {
        for (ll j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
            {
                dp[i] = (dp[i] % mod + dp[i - j] % mod) % mod;
            }
        }
    }
    return dp[n] % mod;
}
 
int main()
{
    ll n;
    cin>>n;
    ll ans=Ways_BU(n);
    cout<<ans<< endl;
}
