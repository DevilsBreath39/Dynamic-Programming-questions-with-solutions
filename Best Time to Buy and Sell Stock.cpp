#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>prices)
{
    int n=prices.size();
    int maxPro=0;
    int minPrice=1e9;

    for (int i=0;i<n;i++)
    {
        minPrice=min(minPrice,prices[i]);
        maxPro=max(maxPro,abs(prices[i]-minPrice));
    }
    return maxPro;
}

int main()
{
    int n;
    cout<<"Enter the number of stocks :- "<<endl;
    cin>>n;
    vector<int>prices;
    cout<<"Enter the prices of the stocks :- "<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        prices.push_back(x);
    }
    int ans=maxProfit(prices);
    cout<<"Maximum profit = "<<ans<<endl;
}
