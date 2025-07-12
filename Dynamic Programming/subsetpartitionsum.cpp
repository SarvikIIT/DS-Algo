class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int newsum = sum / 2;
        // dp[i][j] -> true if sum j is possible using first i elements
        vector<vector<bool>> dp(n, vector<bool>(newsum + 1, false));

        for (int i = 0; i < n; ++i) dp[i][0] = true;

        if (nums[0] <= newsum)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= newsum; ++j) {
                bool notTaken = dp[i - 1][j];
                bool taken = false;
                if (j >= nums[i])
                    taken = dp[i - 1][j - nums[i]];
                dp[i][j] = notTaken || taken;
            }
        }

        return dp[n - 1][newsum];
    }
};