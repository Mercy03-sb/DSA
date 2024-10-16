#include <bits/stdc++.h>
using namespace std;
// Leetcode - 56
bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

class Solution {
public:
    // Sorting using end time would work if array is traversed from right to left;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        result.push_back(intervals[n-1]);
        for(int i=n-2;i>=0;i--) {
            vector<int> curr = intervals[i];
            if(curr[1] >= result[result.size()-1][0]) {
                result[result.size()-1][0] = min(result[result.size()-1][0], curr[0]);
                result[result.size()-1][1] = max(result[result.size()-1][1], curr[1]);
            }
            else {
                result.push_back(intervals[i]);
            }
        }
        // Result will be in reverse order.(Can be reversed)
        return result;
    }
};