// https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/description/



class Solution {
public:
    vector<int> par, siz;
    void init(int n){
        for(int i=0;i<n;i++){
            par[i] = i;
            siz[i] = 1;
        }
    }
    int FindPar(int u){
        return (par[u] == u ? u : FindPar(par[u]));
    }
    void Con(int u,int v){
        u = FindPar(u);
        v = FindPar(v);
        if(u == v)return;
        if(siz[u] < siz[v])swap(u,v);
        siz[u] += siz[v];
        par[v] = u;
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        par = vector<int>(n + 1);
        siz = vector<int>(n + 1);
        init(n);
        for(int i=0;i<queries.size();i++) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [&](auto & i, auto &j){
            return i[2] < j[2];
        });
        sort(edgeList.begin(), edgeList.end(), [&](auto & i, auto &j){
            return i[2] < j[2];
        });
        int j = 0;
        vector<bool>ans(queries.size(), false);
        for(auto i: queries){
            while(j < edgeList.size() && edgeList[j][2] < i[2]){
                Con(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            if(FindPar(i[0]) == FindPar(i[1]))
                ans[i[3]] = true;
        }
        return ans;
    }
};
