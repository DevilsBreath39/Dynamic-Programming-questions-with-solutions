#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
 
ll Ways_BU(ll n, ll x, vector<ll> coins)
{
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
 
    for (ll i=0; i <coins.size(); i++)
    {
        for (ll j = 0; j <=x; j++)
        {
            if (j-coins[i]>= 0)
            {
                dp[j] = (dp[j] + dp[j-coins[i]]) % mod;
            }
        }
    }
    return dp[x] % mod;
}
 
int main()
{
    ll n, x;
    cout << "Enter the number of coins and sum of money :- " << endl;
    cin >> n >> x;
    cout << "Enter the coins :- " << endl;
    vector<ll> coins(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    ll ways2 = Ways_BU(n, x, coins);
    cout << ways2 << endl;
}
