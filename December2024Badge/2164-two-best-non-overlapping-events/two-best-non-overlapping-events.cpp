class Solution {
public:
int maxTwoEvents(vector<vector<int>>& events) {
    // Sort events by their end time
    sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    vector<pair<int, int>> dp; // {endTime, maxValueSoFar}
    int result = 0, maxValueSoFar = 0;

    for (const auto& event : events) {
        int startTime = event[0], endTime = event[1], value = event[2];

        // Find the last event that doesn't overlap with the current event
        auto it = upper_bound(dp.begin(), dp.end(), make_pair(startTime - 1, INT_MAX));
        int bestNonOverlappingValue = (it == dp.begin()) ? 0 : prev(it)->second;

        // Calculate the max sum including the current event
        result = max(result, bestNonOverlappingValue + value);

        // Update maxValueSoFar and the dp vector
        maxValueSoFar = max(maxValueSoFar, value);
        if (dp.empty() || endTime > dp.back().first) {
            dp.emplace_back(endTime, maxValueSoFar);
        } else {
            dp.back().second = max(dp.back().second, maxValueSoFar);
        }
    }

    return result;
}
};