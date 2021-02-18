#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int>price,int n)
{
    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=price[0];
    dp[2]=max(2*price[0],price[1]);
    dp[3]=max({price[0]*3,price[1]+price[0],price[2]});
    
    for(int i=4;i<=n;i++)
    {
        int ans=-1e9;
        for(int j=0;j<i;j++)
        {
            int cut=j+1;
            ans=max(ans,price[j]+dp[i-cut]);
        }
        dp[i]=ans;
    }
    return dp[n];
}



int main()
{
    int n;
    cout<<"Enter the length of the rod :- "<<endl;
    cin>>n;
    vector<int>price;
    cout<<"Enter the price of each cut :- "<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        price.push_back(x);
    }

    int ans=maxProfit(price,n);
    cout<<"Maximum profit :- "<<ans<<endl;
}
