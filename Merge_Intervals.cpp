#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals by starting time
        sort(intervals.begin(), intervals.end());

        // Step 2: Initialize answer array and add first interval
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        // Step 3: Initialize temp to the end of the first interval
        int temp = intervals[0][1];

        // Step 4: Iterate over intervals starting from the second one
        for (int i = 1; i < n; i++) {
            // If the current interval overlaps with the previous one in ans
            if (temp >= intervals[i][0]) {
                // Merge intervals by updating the end of the last interval in ans
                temp = max(intervals[i][1], temp);
                ans.back()[1] = temp;
            } else {
                // If there is no overlap, add the interval to ans
                ans.push_back(intervals[i]);
                temp = intervals[i][1];
            }
        }
        return ans;
    }
};

int main() {
    // Example intervals
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    // Create Solution object
    Solution sol;
    
    // Call the merge function
    vector<vector<int>> result = sol.merge(intervals);

    // Output the merged intervals
    cout << "Merged Intervals: ";
    for (const auto& interval : result) {
        cout << "{" << interval[0] << ", " << interval[1] << "} ";
    }
    cout << endl;

    return 0;
}
