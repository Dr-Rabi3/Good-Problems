///  https://leetcode.com/problems/all-paths-from-source-to-target/description/?envType=study-plan&id=graph-i


class Solution {
public:
    void dfs(int i,vector<vector<int>>& graph,vector<bool>&vis,vector<vector<int>>&res,vector<int>temp){
        if(vis[i])return;
        temp.push_back(i);
        if(i==graph.size()-1){res.push_back(temp);return;}
        vis[i]=1;
        for(auto u:graph[i]){
            if(!vis[u]){
                dfs(u,graph,vis,res,temp);
            }
        }
        vis[i]=0;

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<bool>vis(graph.size(),0); 
    vector<int>temp;   
    vector<vector<int>>res;
    dfs(0,graph,vis,res,temp);
    return res;
    }
};
