class Solution {
public:
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1) ;
        nums.push_back(1);
        int n = nums.size() ;
        vector<vector<int>> dp(n,vector<int>(n,0)) ;
        for (int i = n-2 ; i>=1 ; i--){
            for (int j = 1 ; j<=n-2 ; j++){
                if (i>j){
                   continue ;
                }
                int maxi = -1e7 ;
                for(int ind = i; ind<=j ; ind++){
                    int step = nums[i-1]*nums[j+1]*nums[ind] + dp[ind+1][j] + dp[i][ind-1] ;
                    maxi = max(maxi,step) ;
                }
                dp[i][j]=maxi ;
            }
        }
        return(dp[1][n-2]) ;
    }
};