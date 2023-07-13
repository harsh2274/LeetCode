class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        /*if(prerequisites.size()==0){
            vector<int> temp4{0} ;
            return(temp4);
        }*/

       

        vector<int> temp ;
        vector<vector<int>> vec(numCourses,temp) ;

        vector<int> course(numCourses , 0 ) ;

        for (auto it : prerequisites ){
            course[it[0]]++ ;
            vec[it[1]].push_back(it[0]);    
        }

        queue<int> q ;
        int count = 0 ;
        for (auto it : course){
            cout << it << " " ;
            if(it==0){
                q.push(count) ;
            }
            count ++ ;
        }
        cout << endl ;


        int cnt = 0 ;
        vector<int> temp3 ;

        while(!q.empty()){
            int temp = q.front();
            cout << temp  << " ";
            temp3.push_back(temp) ;
            q.pop() ;
            cnt++ ;

            for (auto it : vec[temp] ) {
                course[it] -- ;
                if(course[it]==0){
                    q.push(it);
                }
            }
        }

        if (cnt==numCourses){
            return(temp3) ;
        }

        vector<int> temp2 ;
        return(temp2) ;
    }
};