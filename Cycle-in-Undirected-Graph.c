bool dfs(vector<int>& vis,vector<vector<int> >& adj,int i,int par){
    vis[i]=1;

    for(auto it:adj[i]){
        if(!vis[it]){
            if(dfs(vis,adj,it,i))
                return true;
        }else if(it!=par){
            return true;
        }
    }
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> vis(A+2,0);
    vector<vector<int> > adj(A+1);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    for(int i=1;i<=A;i++){
        if(!vis[i]){
            if(dfs(vis,adj,i,-1))return 1;
        }
    }
    return 0;
}
