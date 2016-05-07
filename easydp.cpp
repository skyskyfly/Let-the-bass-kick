#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int maxn=1005;
int dp[maxn][maxn];
int main()
{
       char s1[maxn],s2[maxn];
       while(scanf("%s%s",s1,s2)!=EOF)
       {
           memset(dp,0,sizeof(dp));
           int l1=strlen(s1);
           int l2=strlen(s2);
           for(int i=0;i<l1;i++)
           {
               for(int j=0;j<l2;j++)
               {
                   if(s1[i]==s2[j])
                    {
                       if(i>0&&j>0)
                        dp[i][j]=dp[i-1][j-1]+1;
                       else dp[i][j]=1;
                    }
                    else
                    {
                        if(i==0&&j==0)
                            dp[i][j]=0;
                        else if(i>0&&j==0)
                            dp[i][j]=dp[i-1][j];
                        else if(i==0&&j>0)
                            dp[i][j]=dp[i][j-1];
                        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
               }
           }
           cout<<dp[l1-1][l2-1]<<endl;
       }
}
