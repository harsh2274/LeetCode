class Solution {
public:
    int conquer(vector<int> &nums , int si , int mid , int ei ){
        vector<int> merged(ei-si+1);
        int counti = 0 ;
        int idx1 = si ;
        int idx2 = mid+1 ;
        int counto = 0 ;
        int j = mid+1 ;

        for(int i=si;i<=mid;i++){
            while(j<=ei && nums[i]>(2*(long)nums[j])){
                j++;
            }
            counto += j-(mid+1);
        }
        
        while(idx1<=mid && idx2<=ei){
            if(nums[idx1]<nums[idx2]){
                merged[counti] = nums[idx1] ;
                idx1 ++ ;
            }
            else{
                merged[counti] = nums[idx2] ;
                idx2 ++ ;
            }
            counti++ ;
        }
        
        while (idx1<=mid){
            merged[counti] = nums[idx1] ;
            idx1 ++ ;
            counti++ ;
        }

        while (idx2<=ei){
            merged[counti] = nums[idx2] ;
            idx2 ++ ;
            counti ++ ;
        }

        for (int i = 0 , j=si ; i<merged.size() ; i++ , j++ ){
            nums[j] = merged[i] ;
        }

        return(counto);
    }

    int divide(int si , int ei , vector<int> &nums){
       if (si>=ei){
            return(0);
        }

        int mid = si + (ei-si)/2 ;
        
        int inv = divide(si,mid,nums);
        inv += divide(mid+1,ei,nums);
        inv += conquer(nums , si , mid ,ei);
        
        return(inv);
    }

    int reversePairs(vector<int>& nums) {
        int sizi = nums.size() ;
        int main_sol = divide(0,sizi-1,nums) ;

        for(int i = 0 ; i < nums.size() ; i++) {
            cout <<  nums[i] << " " ;
        }

        cout << endl << endl ;
        return(main_sol) ;
    }
};