class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Sort the banned array for easier checking
    sort(banned.begin(), banned.end());
    
    int sum = 0;
    int count = 0;

    // Iterate through the range [1, n]
    for (int i = 1; i <= n; ++i) {
        // Check if the current integer is in the banned list
        if (find(banned.begin(), banned.end(), i) == banned.end()) {
            // Check if adding this integer exceeds maxSum
            if (sum + i <= maxSum) {
                sum += i; // Add the integer to the sum
                count++;  // Increment the count of chosen integers
            } else {
                break; // Stop if we exceed maxSum
            }
        }
    }
    
    return count; // Return the maximum count of integers chosen
    }
};