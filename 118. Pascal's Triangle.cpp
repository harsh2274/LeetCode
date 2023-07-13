class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> main ;
        vector<int> vec1 = {1} ;
        vector<int> vec2 = {1,1} ;
        main.push_back(vec1) ;
        if (numRows==1){
            return(main) ;
        }
        main.push_back(vec2) ;
        if (numRows==2){
            return(main) ;
        }
        for (int i=1 ; i<numRows-1 ; i++) {
            vector<int> vec3 = {1} ;
            for(int j=0 ; j<main[i].size()-1 ; j++) {
                vec3.push_back(main[i][j] + main[i][j+1]) ;
            }
            vec3.push_back(1) ;
            main.push_back(vec3) ;
        }
        return(main) ;
    }
};