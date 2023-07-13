class Solution {
public:
    void summi(vector<int>& candidates , vector<vector<int>> &temp , vector<int> &temp2 , int index , int N){
        
        temp.push_back(temp2);
        if(index==N){
            return ;
        }

        for (int i = index ; i <N  ; i++ ){
            if (i!=index && candidates[i]==candidates[i-1]){
                continue;
            }
            temp2.push_back(candidates[i]);
            summi(candidates , temp , temp2 , i+1 , candidates.size());
            temp2.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> temp ;
        vector<int> temp2 ;
        int N = nums.size() ;
        sort(nums.begin(),nums.end());
        summi(nums , temp , temp2 , 0 , N);
        return(temp) ;
    }
};