class Solution {
public:
    void summi(vector<int>& candidates , int target , int sumi , vector<vector<int>> &temp , vector<int> &temp2 , int index , int N){
        if(sumi>target){
            return ;
        }
        if (sumi==target){
            temp.push_back(temp2) ;
            return ;
        }

        for(int i = index ; i<N ; i++) {
            sumi += candidates[i] ;
            temp2.push_back(candidates[i]);
            summi(candidates , target , sumi , temp , temp2 , i , N);
            sumi -= candidates[i] ;
            temp2.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> temp ;
        vector<int> temp2 ;
        summi(candidates , target , 0 , temp , temp2 , 0 , candidates.size());
        return(temp) ;
    }
};