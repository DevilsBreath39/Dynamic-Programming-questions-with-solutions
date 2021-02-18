#include <bits/stdc++.h>
using namespace std;

int totalWays(int n, int k)
{
    int dp[1000] = {0};
    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                dp[i]+=dp[i-j];
            }
        }
    }

    return dp[n];
}



int main()
{
    int n, k;
    cout << "Enter the value of N and K :- " << endl;
    cin >> n >> k;
    int dp[1000] = {0};
    int ways = totalWays(n, k);
    cout << "Total number of ways = " << ways << endl;
}
