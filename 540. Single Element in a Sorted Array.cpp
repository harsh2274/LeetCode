class Solution {
public:

    int bin_search(vector<int>& nums , int low , int high ){
        if(low>high || low==nums.size()-1 || high==0 || (high==1 && low==0)){
            return(-1) ;
        }
        int mid  = (low + high) / 2 ;

        if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
            return(nums[mid]);
        }
        else{
            if((mid+1)%2==0){
                if(nums[mid]==nums[mid-1]){
                    return(bin_search(nums, mid+1 , high)) ;
                }
                else {
                    return(bin_search(nums, low , mid-1)) ;
                }
            }
            else{
                if(nums[mid]==nums[mid-1]){
                    return(bin_search(nums, low , mid-1)) ;
                }
                else {
                    return(bin_search(nums, mid+1 , high)) ;
                }
            }
        }

    }
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size()==0){
            return(-1) ;
        }
        if (nums.size()==1){
            return(nums[0]);
        }
        if(nums.size()>=2){
            if (nums[0]!=nums[1]){
                return(nums[0]);
            }
            if (nums[nums.size()-1]!=nums[nums.size()-2]){
                return(nums[nums.size()-1]) ;
            }
            return(bin_search(nums , 0 , nums.size()-1)) ;
        }
        return(-1); 
    }
};