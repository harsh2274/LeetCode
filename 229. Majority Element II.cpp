class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1  ;
        int ele1_cnt = 0 ;
        int ele2  ;
        int ele2_cnt = 0 ;
        vector<int> vec ;
        for (int i =0 ; i< nums.size() ; i++ ) {
            if(ele1_cnt == 0 && nums[i]!=ele2){
                ele1 = nums[i] ;
                ele1_cnt += 1 ;
            }

            else if(ele2_cnt == 0 && nums[i]!=ele1 ){
                ele2 = nums[i] ;
                ele2_cnt += 1 ;
            }

            else if(ele1 == nums[i]){
                ele1_cnt += 1 ;
            }

            else if(ele2 == nums[i]){
                ele2_cnt += 1 ;
            }

            else{
                ele1_cnt -= 1 ;
                ele2_cnt -= 1 ;  
            }
        }

        ele1_cnt = 0 ;
        ele2_cnt = 0 ;

        for (int i =0 ; i< nums.size() ; i++ ) {
            if(ele1==nums[i]){
                ele1_cnt += 1 ;
            }

            if(ele2==nums[i]){
                ele2_cnt += 1 ;
            }
        }

        int num = nums.size()/3 +1 ;

        if (ele1_cnt>=num){
            vec.push_back(ele1);
        }
        if (ele2_cnt>=num){
            vec.push_back(ele2);
        }
        sort(vec.begin() , vec.end());
        return(vec) ;

    }
};