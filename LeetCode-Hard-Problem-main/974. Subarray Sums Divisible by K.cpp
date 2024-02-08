class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int>mp;
        int cursum = 0, ans = 0;
        for (int i = 0;i < n;i++) {
            cursum += nums[i];
            cursum = ((cursum%k)+k)%k; // may be less than 0 make this
            if (cursum % k == 0)ans++;
            if (mp[cursum % k] > 0) {
                ans += mp[cursum % k];
            }
            mp[cursum % k]++;
        }
        return ans;
    }
};
