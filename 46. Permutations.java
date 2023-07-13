class Solution {
public:

    

    void main(vector<int> &nums , int N , vector<int> &availability , vector<vector<int>> &soln , vector<int> &temp ){
        if(nums.size()==temp.size()){
            soln.push_back(temp);
            return;
        }

        for(int i = 0 ; i< N ; i++) {
            if(availability[i]==0){
                availability[i] = 1;
                temp.push_back(nums[i]);
                main(nums , N , availability , soln , temp ) ;
                for(int i = 0 ; i< nums.size(); i++){
                    cout << nums[i] << " " ;
                }
                for(int i = 0 ; i< availability.size(); i++){
                    cout << availability[i] << " " ;
                }
                cout << endl ;
                availability[i] = 0;
                temp.pop_back();
            }
        }
        return ;
    } 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> availability(nums.size(),0) ;
        vector<vector<int>> soln ;
        vector<int> temp ;

        main(nums , nums.size() , availability , soln , temp ) ;
        return(soln) ;
    }
};