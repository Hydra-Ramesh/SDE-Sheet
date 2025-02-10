#include <iostream>
#include <vector>
#include <algorithm> // For sort function

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals by starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        // Step 2: Merge overlapping intervals
        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& last = result.back();  // Get the last interval in the result

            if (intervals[i][0] <= last[1]) {
                // Merge intervals if overlapping
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // No overlap, add a new interval
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

// Function to print intervals
void printIntervals(const vector<vector<int>>& intervals) {
    for (const auto& interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> intervals = {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}
    };

    cout << "Original Intervals:\n";
    printIntervals(intervals);

    Solution sol;
    vector<vector<int>> mergedIntervals = sol.merge(intervals);

    cout << "\nMerged Intervals:\n";
    printIntervals(mergedIntervals);

    return 0;
}
