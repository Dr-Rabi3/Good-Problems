class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size() ;
        vector<vector<int>>ans;
        sort(v.begin(), v.end());
        for (int i = 0;i < n;i++) {
            if ((i && v[i] != v[i - 1]) || !i) {
                int l = i + 1, r = n - 1;
                while (l < r) {
                    int sum = v[i] + v[l] + v[r];
                    if (sum > 0)r--;
                    else if (sum < 0) l++;
                    else {
                        ans.push_back({ v[i],v[l],v[r] });
                        l++;
                        while (v[l] == v[l - 1] && l < r)l++;
                    }
                }
            }
        }
        return ans;
    }
};

// https://www.youtube.com/watch?v=jzZsG8n2R9A&t=719s
