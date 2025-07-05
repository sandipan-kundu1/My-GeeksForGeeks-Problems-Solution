class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        if(n == 0) return 0;

        vector<int> lis(n, 1); // LIS ending at i
        vector<int> lds(n, 1); // LDS starting at i

        // Compute LIS
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        // Compute LDS
        for(int i = n - 2; i >= 0; i--) {
            for(int j = n - 1; j > i; j--) {
                if(nums[i] > nums[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

        // Compute maximum valid Bitonic subsequence length
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            if(lis[i] > 1 && lds[i] > 1) {
                maxLen = max(maxLen, lis[i] + lds[i] - 1);
            }
        }

        return maxLen;
    }
};
