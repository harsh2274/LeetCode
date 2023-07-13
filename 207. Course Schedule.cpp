class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        if(prerequisites.size()==0){
            return(1);
        }

        if(prerequisites.size()==1 && numCourses>=2){
            return(1);
        }

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
        while(!q.empty()){
            int temp = q.front();
            cout << temp  << " ";
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
            return(1) ;
        }

        return(0) ;
    }
};