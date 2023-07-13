class Solution {
public:
    void summi(vector<int>& candidates , int target , int sumi , vector<vector<int>> &temp , vector<int> &temp2 , int index , int N , int left){
        if(left<0){
            return ;
        }
        if (left==0){
            temp.push_back(temp2) ;
            return ;
        }
        int tempi = -1 ;
        for(int i = index ; i<N ; i++) {
            if(tempi!=candidates[i]){
                tempi = candidates[i] ;
            }
            else{
                continue;
            }

            sumi += candidates[i] ;
            left -= candidates[i] ;
            temp2.push_back(candidates[i]);

            summi(candidates , target , sumi , temp , temp2 , i+1 , N , left);
            
            sumi -= candidates[i] ;
            left += candidates[i] ;
            temp2.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> temp ;
        vector<int> temp2 ;
        summi(candidates , target , 0 , temp , temp2 , 0 , candidates.size() , target);
        return(temp) ;
    }
};