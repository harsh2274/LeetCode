class Solution {
public:

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector <int> dp(arr.size()+1,0) ;
        int n = arr.size() ;
        for(int index = n-1; index>=0 ; index--){
            int maxi = INT_MIN ;
            int maxii = INT_MIN ;
            for (int j = index ; j<index+k ; j++){
                if(j<n){
                    maxi = max(maxi,arr[j]) ;
                    maxii = max(maxi*(j-index+1) + dp[j+1],maxii);
                }
            }
            dp[index]=maxii ;
        }
        return(dp[0]);        
    }
};