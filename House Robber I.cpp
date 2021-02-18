#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> fees, int n)
{
    if (n==0)
        return 0;

    if (n==1)
        return fees[0];


    vector<int> dp(n);
    dp[0]=fees[0];
    dp[1]=max(fees[0],fees[1]);
    

    for(int i=2;i<n;i++)
    {
        dp[i]=max(fees[i]+dp[i-2],dp[i-1]);
    }

    return dp[n-1];
}

int main()
{
    int n;
    cout << "Enter the number of houses :- " << endl;
    cin >> n;
    vector<int> fees;
    cout << "Enter the loot at each house :- " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        fees.push_back(x);
    }

    int ans = maxProfit(fees, n);
    cout << "Maximum profit :- " << ans << endl;
}
