class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> curr(n+1,0) ;
        vector<int> next(n+1,0) ;
        for (int curr_index = n-1 ; curr_index>=0 ; curr_index--){
            for (int prev_index = curr_index-1 ; prev_index>=-1 ; prev_index--){
                int nottake  = 0 + next[prev_index+1] ;
                if (prev_index==-1 || nums[curr_index]>nums[prev_index]){
                    nottake = max( nottake , 1 + next[curr_index+1]) ; 
                }
                curr[prev_index+1]=nottake;
            }
            next = curr ;
        }
        return(curr[0]);

    }
};