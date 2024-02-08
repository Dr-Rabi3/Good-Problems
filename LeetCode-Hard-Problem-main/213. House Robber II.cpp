class Solution {
public:
    int robber(vector<int> nums){
        vector<int> dp(nums.size(), 0);
        dp[0]=max(nums[0],0);
        dp[1]=max({0,nums[0], nums[1]});
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1], nums[i]+dp[i-2]);
        }
        return max(dp[nums.size()-1],0);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return max(nums[0],0);
        else if(n==2) return max({0,nums[0], nums[1]});
        vector<int> v1(nums.begin()+1, nums.end());
        vector<int> v2(nums.begin(), nums.end()-1);
        return max(robber(v1), robber(v2));
    }
};
