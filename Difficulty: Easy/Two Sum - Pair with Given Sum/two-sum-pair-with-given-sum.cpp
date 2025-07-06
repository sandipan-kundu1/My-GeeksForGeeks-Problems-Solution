class Solution {
  public:
    bool twoSum(vector<int>& A, int B) {
        // code here
        unordered_map<int, int> mp; // value → index (1-based)
        int n = A.size();
        for (int i = 0; i < n; i++) {
            int target = B - A[i];
            if (mp.count(target)) {
                // Found the pair
                return true;
            }
            // Only store first occurrence
            if (!mp.count(A[i])) {
                mp[A[i]] = i;
            }
        }
        return false;
    }
};