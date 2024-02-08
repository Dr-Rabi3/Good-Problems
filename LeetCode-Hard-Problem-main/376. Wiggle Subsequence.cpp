class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int>v = nums;
        int n = v.size();
        int dp[1000][1000][3];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, int)>MaxLength = [&](int i, int last, int ok) {
            if (i == n)return 1;
            if (~dp[i][last][ok])return dp[i][last][ok];
            int ans = 0;
            ans = max(ans, MaxLength(i + 1, last, ok));
            if (v[i] == v[last])ans = max(ans, MaxLength(i + 1, last, ok));
            if(ok != 0 and v[i] - v[last] < 0)ans = max(ans, MaxLength(i + 1, i, 0) + 1);
            if(ok != 1 and v[i] - v[last] > 0)ans = max(ans, MaxLength(i + 1, i, 1) + 1);
            return dp[i][last][ok] = ans;
        };
        return MaxLength(0, 0, 2);
    }
};

// -------------------------------------------------------------------------------

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size=nums.size(), peak=1, valley=1;
        for(int i=1; i<size; ++i){
                 if(nums[i]>nums[i-1]) peak = valley + 1;
            else if(nums[i]<nums[i-1]) valley = peak + 1;
        }
        return max(peak , valley );
    }
};
