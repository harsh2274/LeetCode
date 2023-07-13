class DisjointSet {
    vector<int> rank , parent , size ;
public :
    DisjointSet(int n){
        rank.resize(n+1,0) ;
        parent.resize(n+1) ;
        size.resize(n+1) ;
        for (int i = 0 ; i<n ; i++ ){
            parent[i] = i ;
            size[i] = 1 ;
        }
    }

    int findUPar(int node){
        if(node==parent[node]){
            return(node) ;
        }
        return parent[node] = findUPar(parent[node]) ;
    }

    void unionbyrank(int u, int v ){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return ;
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u ;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v ;
        }
        else{
            parent[ulp_v] = ulp_u ;
            rank[ulp_u]++ ;
        }
    }

    void unionbysize(int u, int v ){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v] = ulp_u ;
            size[ulp_u] += size[ulp_v] ;
        }
        else{
            parent[ulp_u] = ulp_v ;
            size[ulp_v] += size[ulp_u] ;
        }
    }

    int parent_loc(int i) {
        return(parent[i]) ;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string,int> mapi ;
        DisjointSet ds(accounts.size()) ;

        for (int i = 0 ; i<accounts.size() ; i++ ){
            cout << endl ;
            int flag = 0 ;
            for (int j = 1 ; j<accounts[i].size() ; j++ ){
                if(mapi.find(accounts[i][j])==mapi.end()){
                    mapi[accounts[i][j]] = i ;
                    //cout << "here 1  " ;
                }
                else {
                    ds.unionbysize(i,mapi[accounts[i][j]]) ;
                    //cout << "here 2  " ;
                }
            }
        }

        vector<string> tosubmit[accounts.size()] ;

        for (auto it : mapi){
            string mail = it.first ;
            int node = ds.findUPar(it.second) ;
            tosubmit[node].push_back(mail) ;
        }
        

        int i = 0 ;
        
        vector<vector<string>> temp ;

        while(i<accounts.size()){
            if(tosubmit[i].size()!=0){
                string temp2 = tosubmit[i][0] ;
                tosubmit[i][0] = accounts[i][0] ;
                tosubmit[i].push_back(temp2) ;

                sort(tosubmit[i].begin()+1,tosubmit[i].end()) ;
                for (auto it : tosubmit[i] ){
                    cout << it << " " ; 
                }

                temp.push_back(tosubmit[i]);
            }
            i++ ;

        }
        return(temp) ;
    }
};