//https://practice.geeksforgeeks.org/problems/a4f19ea532cee502aabec77c07e0d0a45b76ecf9/1/?track=30-DOC-day-30&batchId=320

class Solution
{
    public:
    int build_bridges_util(int i , int j , string str1 , string str2 , int n , int m , int dp[105][105])
    {
        if(i>=n or j>=m)
            return 0;
        
        int ans = dp[i][j];
        if(ans!=-1)
            return ans;
        
        ans = 0;
        if(str1[i]==str2[j])
            ans = 1 + build_bridges_util(i+1, j+1, str1, str2,n, m, dp);
        
        ans = max(ans, build_bridges_util(i+1, j, str1, str2, n, m, dp));
        ans = max(ans, build_bridges_util(i, j+1, str1, str2, n, m, dp));
        
        return dp[i][j] = ans;
    }
    
    int build_bridges(string str1, string str2)
    {
        int dp[105][105];
        memset(dp, -1, sizeof dp);
        int n = str1.size();
        int m = str2.size();
        return build_bridges_util(0,0,str1,str2,n,m,dp);
    }
};

