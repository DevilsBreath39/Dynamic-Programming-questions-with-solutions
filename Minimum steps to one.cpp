#include<bits/stdc++.h>
using namespace std;

// Top Down
int minSteps(int n,int dp[])
{
    if(n==1)
    {
        return 0;
    }

    if(dp[n]!=0)
    {
        return dp[n];
    }

    int step1,step2,step3;
    step1=INT_MAX;
    step2=INT_MAX;
    step2=INT_MAX;

    if(n%3==0)
    {
        step1=minSteps(n/3,dp);
    }
    if(n%2==0)
    {
        step2=minSteps(n/2,dp);
    }
    
    step3=minSteps(n-1,dp);
    

    return dp[n]=min(step3,min(step2,step1))+1;
}

//Bottom Up
int minSteps_BU(int n)
{
    int dp[n+1];
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;

    for(int i=4;i<=n;i++)
    {
        int step1,step2,step3;
        step1=step2=step3=INT_MAX;
        if(i%3==0)
        {
            step1=dp[i/3];
        }
        if(i%2==0)
        {
            step2=dp[i/2];
        }
        step3=dp[i-1];
        dp[i]=min(step3,min(step2,step1))+1;
    }
    return dp[n];
}



int main()
{
    int n;
    cout<<"Enter the number :- "<<endl;
    cin >> n;
    int dp[n + 1] = {0};
    int ans = minSteps(n, dp);
    int ans2=minSteps_BU(n);
    cout<<ans<<endl;
    cout<<ans2<<endl;
}
