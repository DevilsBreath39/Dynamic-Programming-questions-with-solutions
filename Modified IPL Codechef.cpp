// Cannot select 4 consecutive elements


#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> fees, int n)
{
    vector<int> dp(n);
    dp[0] = fees[0];
    dp[1] = (fees[0] + fees[1]);
    dp[2] = fees[0]+fees[1]+fees[2];
    dp[3] = max({fees[0]+fees[2]+fees[3],fees[1]+fees[2]+fees[3],dp[2],dp[1]+fees[3]});

    for (int i = 4; i < n; i++)
    {
        dp[i] = max({dp[i-1],fees[i]+dp[i-2],fees[i]+fees[i-1]+fees[i-2]+dp[i-4],fees[i]+fees[i-1]+dp[i-3]});
    }

    
    return dp[n-1];
}

int main()
{
    int n;
    cout << "Enter the number of matches :- " << endl;
    cin >> n;
    vector<int> fees;
    cout << "Enter the price of each match :- " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        fees.push_back(x);
    }

    int ans = maxProfit(fees, n);
    cout << "Maximum profit :- " << ans << endl;
}
