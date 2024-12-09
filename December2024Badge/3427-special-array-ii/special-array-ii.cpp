class Solution {
public:
  vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<bool> answer(queries.size(), true);
    vector<int> sameParityCount(n - 1, 0);

    // Fill the sameParityCount array
    for (int i = 0; i < n - 1; i++) {
        if ((nums[i] % 2) == (nums[i + 1] % 2)) {
            sameParityCount[i] = 1; // Mark as same parity
        }
    }

    // Create a prefix sum array for same parity counts
    for (int i = 1; i < n - 1; i++) {
        sameParityCount[i] += sameParityCount[i - 1];
    }

    // Answer each query
    for (int i = 0; i < queries.size(); i++) {
        int from = queries[i][0];
        int to = queries[i][1];

        // Check the number of same parity pairs in the range
        if (from < to) {
            int count = sameParityCount[to - 1] - (from > 0 ? sameParityCount[from - 1] : 0);
            if (count > 0) {
                answer[i] = false; // Found at least one same parity pair
            }
        }
    }

    return answer;
}
};