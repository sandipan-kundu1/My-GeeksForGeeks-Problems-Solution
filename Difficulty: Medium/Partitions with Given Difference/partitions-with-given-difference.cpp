class Solution {
  public:
    int f(int i, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if(i == 0) {
            if(sum == 0 && arr[0] == 0) return 2;
            if(sum == 0 || sum == arr[0]) return 1;
            return 0;
        }

        if(dp[i][sum] != -1) return dp[i][sum];

        int notTake = f(i - 1, sum, arr, dp);
        int take = 0;
        if(arr[i] <= sum)
            take = f(i - 1, sum - arr[i], arr, dp);

        return dp[i][sum] = (notTake + take) ;
    }

    int countPartitions(vector<int>& arr, int d) {
        int total = accumulate(arr.begin(), arr.end(), 0);

        // Check if (total + d) is even and valid
        if((total + d) % 2 != 0 || (total + d) < 0) return 0;

        int target = (total + d) / 2;

        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, target, arr, dp);
    }
};
