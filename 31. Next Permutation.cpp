class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int temp = nums[nums.size()-1 ];
        int i = 1 ;
        int flag = 0 ;
        vector<int> peaks ;
        int peak =-1;
        int itr ;
        
        if (nums.size()==1) {
            return;
        }

        if (nums[nums.size()-1 ] > nums[nums.size()-2 ]) {
            swap(nums[nums.size()-1 ] , nums[nums.size()-2 ]) ;
            return ;
        }
        
        for ( i = 1 ; i<nums.size() ; i++) {
            if ((nums[nums.size()-1-i]) < nums[nums.size()-i]){
                cout << "toott" << endl ;
                if (flag==0){
                    peak = nums[nums.size()-i] ;
                    itr = i ;
                    cout << peak << endl;

                    break ;
                }
            }
            else {
                flag = 0 ;
            }
        }
        if (peak==-1){
            cout << "I am out" << endl ;
            sort(nums.begin(),nums.end());
            return;
        }

        temp = nums[nums.size()-itr-1 ] ;
        int flagi = 0 ;
        cout << nums.size()-itr << endl ;

        for (int j = nums.size()-itr ; j<nums.size() ; j++){
            if (nums[j]>temp && nums[j]<peak){
                cout << "I am in  " << endl ;
                flagi = 1 ;
                swap(nums[j] , nums[nums.size()-itr-1 ]) ;
            }
        } 
        if (flagi==0){
            swap(nums[nums.size()-itr ] , nums[nums.size()-itr-1 ]) ;
        }
        sort(nums.begin() + nums.size()-itr ,nums.end()) ;
        return;

    }
};