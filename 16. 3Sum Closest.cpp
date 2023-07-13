class Solution {
public:
    int twoSum(int target , int temp , vector<int> vec) {
        int i = 0 ;
        int j = vec.size()-1 ;
        int yuo = 100000 ;
        int sumi = 0 ;
        while(i<j){
            int o = vec[i]+vec[j]+temp ;
            //cout << o ;
            int y = o - target ;
            int xx= 0 ;
            if (y<0){
                xx = y*(-1) ; 
                i++ ;
            } 
            if (y>0 ){
                j-- ;
                xx = y ;
            }

            if(y==0) {
                sumi = o ;
                break ;
            }

            if (xx<yuo){
                yuo = xx ;
                //cout << "yuo" << yuo << endl  ;
                sumi = o ;
                //cout << "--sumi : " << sumi << endl ;
            }
        }
        //cout << "sumi : " << sumi << endl ;
        return(sumi) ;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int flag = 1000000 ;
        int finall = 0 ;
        for (int i =0 ; i<nums.size() ; i++ ){
            int temp = nums[i] ;
            if (i!=nums.size()-1){
                vector<int> result = std::vector<int>(nums.begin()  + 1 + i, nums.end());
                if (result.size()<2){
                    break ;
                }
                int y =  twoSum(target , temp , result) ;
                int uu = y - target ;
                int jab  = 0 ;
                if (uu<0 ) {
                    jab = uu * (-1) ;
                } 
                else {
                    jab = uu ;
                }
                if (jab < flag ) {
                    flag  = jab ;
                    finall = y ;
                }

            }
        }
        return(finall) ; 
    }
};