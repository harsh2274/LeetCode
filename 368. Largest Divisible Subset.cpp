class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==1){
            return(nums) ;
        }
        sort(nums.begin(),nums.end()) ;
        vector<int> dp(nums.size(),1) ;
        vector<int> hash(nums.size()) ;
        int maxi = -1 ;
        int index_main = -1 ;

        for (int index = 0 ; index<nums.size() ; index++ ){
            hash[index] = index ;
            for(int j = index-1 ; j>=0 ; j--){
                if ((nums[index]%nums[j]==0)){
                    if (1+dp[j]>dp[index]){
                        dp[index] = 1 + dp[j] ;
                        hash[index] = j ;
                    }
                }
            }
            if (dp[index]>maxi){
                maxi = dp[index] ;
                index_main = index ;
            }
        }
        vector<int> tempi ;
        int index = index_main ;
        tempi.push_back(nums[index]) ;
        while(hash[index]!=index){
            index = hash[index] ;
            tempi.push_back(nums[index]) ;
        }
        reverse(tempi.begin(),tempi.end()) ;
        return(tempi) ;
    }
};