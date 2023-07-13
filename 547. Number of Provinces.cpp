class Solution {
public:

    void bfs(vector<int> adj[],queue<int> q ,vector<int> &visited){
        while(!q.empty()){
            int i = q.front() ;
            //cout << i << endl ;
            int n = adj[i].size() ;

            for (int j = 0 ; j< n ; j++){
                //cout << adj[i][j] << " " ;
                if(visited[adj[i][j]]==0){
                    q.push(adj[i][j]);
                    visited[adj[i][j]] = 1 ;
                }
            }
            q.pop();
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> adj[isConnected.size()] ;
        vector<int> visited (isConnected.size(),0) ;
        for (int i =  0 ; i<isConnected.size() ; i++ ){
            for (int j =  0 ; j<isConnected.size() ; j++ ){
                if(isConnected[i][j] && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        queue<int> q;

        int count = 0 ;
        for(int i = 0 ; i< isConnected.size() ; i++ ){
            if(visited[i]==0){
                q.push(i);
                visited[i] = 1 ;
                cout << i << "  " ;
                bfs( adj , q , visited );
                count ++ ;
            }
        }
        return(count) ;
    }
};