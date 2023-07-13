class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> pos(nums.size()) ;
        if(nums.size()==1) {
            return(1) ;
        }
        for (int i = 0 ; i<nums.size() ; i++) {
           pos[i] = i + nums[i] ;
           cout << pos[i] << " " ;
        }
        cout << endl ;
        int start = pos[0] ;
        int j = 0 ; 
        int jump = 1 ;
        if(pos[0]>=nums.size()-1){
            return(1) ;
        }
        if(pos[0]==0){
            return(0) ;
        }
        while(j<pos.size()-1) {
            int max = -1 ;
            while (j<=start){
                if (pos[j]>max){
                    max = pos[j] ;
                }
                //cout << max  << " ";
                j++ ;
            }
            start = max ;
            cout << max  << " " << nums.size() << endl;
            if (max==-1){
                return(0) ;
            }
            if (max>=nums.size()-1){
                cout << "I am here " << endl ;
                return(1) ;
            }
            
        }
        return(0) ;
    }
};