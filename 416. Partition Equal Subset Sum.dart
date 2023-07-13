class Solution {
public:
    bool num_check(vector<int> &arr, int sum, int index , vector<vector<int>> &dp){
        if(sum==0){
            return(1) ;
        }
        if(index==0){
            return(sum==arr[0]) ;  
        } 
        if(dp[index][sum]!=-1){
            return(dp[index][sum]);
        }
        bool notTake = num_check(arr,sum,index-1,dp);
        bool Take = 0 ;
        if(arr[index]<=sum) Take = num_check(arr,sum-arr[index],index-1,dp);
        return (dp[index][sum] = Take | notTake) ;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        for(auto it : nums){
            sum += it ;
        }
        if(sum%2==1){
            return(0) ;
        }
        else{
            sum = sum / 2 ;
        }

        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1)) ;        
        return(num_check(nums,sum,nums.size()-1,dp)) ;


    }
};