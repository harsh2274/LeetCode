class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> ng ;
        vector<int> ngi ;
        int n = nums.size();

        for(int i = n-1 ; i>=0 ; i--) {
          ng.push(i);
        }

        for(int i = n-1 ; i> -1 ; i--) {
            while(!ng.empty() && nums[i]>=nums[ng.top()]){
                ng.pop() ;
            }
            if (ng.empty()){
                ngi.push_back(-1) ;
            }
            else {
                ngi.push_back(nums[ng.top()]) ;
            }
            ng.push(i) ;
        }

        reverse(ngi.begin() , ngi.end()) ;
        return(ngi) ;
    }
};