#include<bits/stdc++.h>
using namespace std;


int minCost(vector<int>days,vector<int>costs)
{
    int n = days.size();
    vector<int> dp(n+1,365*costs[0]);
    dp[n]=0;

    for (int i=n-1;i>=0;i--)
    {
        int d7=i,d30=i;

        while(d7<n and days[d7]<days[i]+7)
        {
            d7++;
        }

        while(d30<n and days[d30]<days[i]+30)
        {
            d30++;
        }

        dp[i] = min({costs[0]+dp[i + 1],costs[1]+dp[d7],costs[2]+dp[d30]});
    }
    return dp[0];
}

int main()
{
    int n;
    cout<<"Enter the number of days you want to travel :- "<<endl;
    cin>>n;
    vector<int>days;
    cout<<"Enter the days :- "<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        days.push_back(x);
    }

    cout<<"Enter the cost of passes :- "<<endl;
    vector<int>costs;
    for(int i=0;i<3;i++)
    {
        int x;
        cin>>x;
        costs.push_back(x);
    }
    int ans=minCost(days,costs);
    cout<<"Minimum cost required :- "<<ans<<endl;
}
