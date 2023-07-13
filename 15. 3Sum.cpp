class Solution {
public:
    vector<vector<int>> twoSum(int temp , vector<int>& numi){
        int l = 0 ;
        //cout << ",,,,,,,,,,,,,,,," << endl  ;
        int u = numi.size()-1;
        //cout << temp << "  " ;
        //cout << endl ;
        set<vector<int>> dam ;
        while(l<u){
            //cout << "l:" << l << "u:" << u << endl ;
            vector<int> vec ;
            int i = numi[l] ;
            int j = numi[u] ;
            int rr = i + j + temp ;
            if (rr>0){
                u--;
            }
            else if (rr<0){
                l++ ;
            }
            else if (rr==0){
                vec.push_back(temp);
                vec.push_back(i) ;
                vec.push_back(j) ;
                dam.insert(vec) ;
                l++ ;
            }
            if(l>=u){
                break ;
            } 
        } 
        vector<vector<int>> v(dam.begin(), dam.end());
        return (v) ;
    }
    vector<int> b = {0,0,0};
    vector<vector<int>> toput = {{0,0,0}} ;
    //toput.push_back(b) ;

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> numi ;
        sort(nums.begin(), nums.end());
        int damn = 0 ;
        if (nums.size()<4){
            for (int i = 0 ; i < nums.size() ; i++){
                damn = damn + nums[i] ;
            }
            if (damn==0){
                numi.push_back(nums) ;
                return(numi) ;
            }
            else {
                return(numi) ;
            }
        }
        if (nums[0]==0 && nums[nums.size()-1] == 0){
            return(toput);
        }

        int temp = nums[0] ;
        vector<int> result = std::vector<int>(nums.begin()  + 1 , nums.end());
        vector<vector<int>> y =  twoSum(temp , result) ;
        numi.insert(numi.end(), y.begin(), y.end());
        int flag =0 ;
        for (int i =1 ; i<nums.size()-2 ; i++ ){
            temp = nums[i] ;
            /*if (temp == 0){ 
                // && nums[i+1]==0 && nums[i+2]==0 && flag ==0){
                flag = 1 ;
                numi.push_back(b) ;
            }*/
            if (temp>0){
                break ;
            }
            else if (nums[i]!=nums[i-1] ){
                if (i!=nums.size()-1){
                    result = std::vector<int>(nums.begin()  + 1 + i, nums.end());
                    vector<vector<int>> y =  twoSum(temp , result) ;
                    numi.insert(numi.end(), y.begin(), y.end());
                }
            }
        }
        return(numi) ; 
    }
};