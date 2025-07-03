class Solution {
  public:
    int offset = 10000;  // to handle negative sums
    int dp[101][20001];  // dp[i][sum + offset] for sum range [-10000, 10000]

    int f(int i, int sum, vector<int>& A, int target) {
        if (i < 0)
            return sum == target ? 1 : 0;

        if (dp[i][sum + offset] != -1)
            return dp[i][sum + offset];

        int add = f(i - 1, sum + A[i], A, target);
        int sub = f(i - 1, sum - A[i], A, target);

        return dp[i][sum + offset] = add + sub;
    }

    long long findTargetSumWays(int n, vector<int>& A, int target) {
        memset(dp, -1, sizeof(dp));
        return f(n - 1, 0, A, target);
    }
};
