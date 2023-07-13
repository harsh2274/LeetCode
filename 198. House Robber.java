class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
    if (n==1){
        return(nums[0]);
    }
    if(n==2){
        return(max(nums[0],nums[1])) ;
    }

    int prev1 ;
    int prev2 ;
    if (n>2){
        prev1 = nums[0] ;
        prev2 = max(nums[0],nums[1]) ;
    }

    int i = 2;
    int temp ;
    while(i<nums.size()){
        if(prev2 > prev1+nums[i]){
            prev1 = prev2 ;
        }
        else {
            temp = prev2 ;
            prev2 = prev1 + nums[i] ;
            prev1 = temp ; 
        }
        i++ ;
    }
    return(prev2);
    }
};