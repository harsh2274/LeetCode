class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long temp = 1 ;
        int tempi = -999999 ;
        int count = 0  ;
        int counti = 0 ;
        for (int i = 0 ; i<nums.size() ; i++ ){
            if(nums[i]!=0){
                temp *= nums[i];
            }
            if(nums[i]==0){
                counti++ ;
            }
            if(nums[i]>tempi and nums[i]<0){
                tempi = nums[i];
                count ++ ;
            }
        }
        if(nums.size()==1){
            if(nums[0]<=0){
                return(nums[0]);
            }
        }
        if(counti==nums.size()){
            return(0);
        }
        if(count==1 && (counti + count)== nums.size()){
            return(0);
        }
            
        if(temp<0){
            temp = temp / tempi ;
        }
        return(temp);
    }
};