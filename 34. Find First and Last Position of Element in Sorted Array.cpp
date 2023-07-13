class Solution {
public:
    int bin_search_high(vector<int> vec , int low , int high , int n , int r ){
       if (low>high){
            return(r);
        }

        int mid = low + (high-low)/2;

        if (n==vec[mid]){
            r = mid ;
            return(bin_search_high(vec , mid+1 , high ,n ,r)) ;
        }

        else if (vec[mid]>n){
            return(bin_search_high(vec,low,mid-1,n,r));
        }
        else{
            return(bin_search_high(vec,mid+1,high,n,r));
        }
    }
  
    int bin_search_low(vector<int> vec , int low , int high , int n , int l ){
        if (low>high){
            return(l);
        }

        int mid = low + (high-low)/2;
        
        if (n==vec[mid]){
            l = mid ;
            return(bin_search_low(vec , low , mid-1,n,l)) ;
        }

        if (vec[mid]>n){
            return(bin_search_low(vec,low,mid-1,n,l));
        }
        else{
            return(bin_search_low(vec,mid+1,high,n,l));
        }
    }
  
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vec ;
        int n = nums.size() ;
        if (n>=2 && nums[0]==target && nums[n-1]==target){
            vec.push_back(0) ;
            vec.push_back(n-1) ;
            return(vec) ;
        }

        if (nums.size()==0){
            vec.push_back(-1) ;
            vec.push_back(-1) ;
            return(vec) ;
        }

        int l = -1 ;
        int r = -1 ;

        if (nums[0]>target || nums[n-1]<target){
            vec.push_back(-1) ;
            vec.push_back(-1) ;
            return(vec) ;
        }
        
        if (nums[0]!=target){
            vec.push_back(bin_search_low(nums,0,nums.size()-1,target,l));
        }
        
        else {
            vec.push_back(0);
        }
        
        vec.push_back(bin_search_high(nums,0,nums.size()-1,target,r));
        
        return(vec);
    }
};