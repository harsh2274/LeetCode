class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sumi = 0 ; 
        int n = nums.size() ;
        for (auto it :nums ){
            sumi += it ;
        }
        if(sumi-target<0 || (target+sumi)%2==1){
            return(false) ;
        }

        int to_sumi = (target+sumi)/2 ;
        
        //vector<vector<int>> dp(n,(vector<int>(to_sumi+1001,0))) ;
        map<pair<int, int>, int> dp ;
        
        if (nums[0]==0) dp[{0,0}]=2 ;
        else dp[{0,0}] = 1 ;
        if(nums[0]!=0 && nums[0]<=to_sumi ){
            dp[{0,nums[0]}] = 1 ;
        }
        
        for(int index = 1 ; index<n ; index++){
            for(int to_sum = 0 ; to_sum<=to_sumi ; to_sum++){
                int nottake = dp[{index-1,to_sum}] ;
                int take = 0 ;
                if(nums[index]<=to_sum){
                    
                    take = dp[{index-1,to_sum-nums[index]}] ;
                }
                
                dp[{index,to_sum}] = (take+nottake) ;
            }
        }
        return(dp[{n-1,to_sumi}]);
    }
};