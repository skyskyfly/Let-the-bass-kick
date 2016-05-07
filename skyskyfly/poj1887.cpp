#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int maxn=40000;
int a[maxn],dp[maxn];
int kase=0;
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1) break;
        int k=0;
        a[k]=n;
        k++;
        while(1)
        {
            scanf("%d",&n);
            if(n==-1) break;
            a[k]=n;
            k++;
        }
        for(int i=0;i<k;i++)
        {
            //cout<<a[i]<<endl;
            dp[i]=1;
            for(int j=i-1;j>=0;j--)
            {
                if(a[j]>=a[i]) dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        sort(dp,dp+k);
        cout<<"Test #"<<++kase<<":"<<endl;
        cout<<"  maximum possible interceptions: "<<dp[k-1]<<endl<<endl;
    }
    return 0;
}
