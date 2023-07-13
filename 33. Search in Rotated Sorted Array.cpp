class Solution {
public:

    int search_element(vector<int>& arr,int x,int l,int h) {
    if(l>h){
        return(-1);
    }
    else {
        int temp = (l+h)/2 ;
        if (arr[temp]==x){
            return(temp) ;
        }
        else if (arr[temp]>x){
            return (search_element(arr , x , l , temp-1)) ;
        }
        else {
            return (search_element(arr , x , temp+1 , h)) ;
        }
    }
}

    int search_pivot(vector<int>& nums , int target , int l , int h ){
        int temp = (l+h)/2 ;
        cout << "search :: temp :: " <<  temp << endl ;
        if (nums[temp]<nums[temp-1]){
            return(temp) ;
        }
        else if(l>=h){
            return(-1) ;
        }
        else{
            if(nums[temp]>nums[h]){ 
                return(search_pivot(nums , target , temp+1 , h)) ;
            }
            else if(nums[temp]<nums[h]){
                return(search_pivot(nums , target , l , temp )) ;
            }
        }
        return(-2) ;
    }

    
    int search(vector<int>& nums, int target) {
        int temp = 0 ;
        int flagi = 0 ;
       
        if (nums.size()==2){
           if (nums[0]==target){
                return(0) ;
            }
            else if (nums[1]==target){
                return(1) ;
            }
            else{
                return(-1) ;
            }
        }

        if (nums[0]>nums[nums.size()-1]){
            temp = search_pivot(nums,target,0,nums.size()-1) ;
            cout << "pivot : " << temp << endl ; 
            flagi = 1 ;
        }
        else {
            return(search_element(nums , target , 0 , nums.size()-1)) ; 
        }

        int temp2 = -1  ;
        if (temp!=-3){
            cout << ":::" << temp2 << endl ;
            if (target==nums[temp]){
                return(temp) ;
            }

            else if(target==nums[nums.size()-1]){
                return(nums.size()-1);
            }
            else if(target==nums[0]){
                return(0);
            }

            else if (target<nums[0]){
                temp2 = search_element(nums,target,temp,nums.size()-1) ;
                cout << temp2 << endl; 
            }

            else if(target>nums[nums.size()-1])
            {
                if (flagi==1){
                    temp2 = search_element(nums,target,0,temp-1) ;
                }
                else {
                    temp2 = search_element(nums,target,0,nums.size()-1) ;
                }
                cout << temp2 << endl; 
            }

        }
        return(temp2) ;
    }
};