#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    if(a[1] != b[1]) return a[1] < b[1];
    return a[0] < b[0];
}
// Concept
// Agar interval overlapping hai toh mai woh pick karunga jo jaldi khatam hoga 
// And for detecting overlapping we sort the intervals based on finishing time or starting time
class Solution {
public:
    // Similar to Merge Intervals can be solved by sorting acc. to Start time or end time
    // Jo interval pehle khatam hoga usse pick karke shuruat karenge for end time sorting
    // Therefore We will traverse left to right here.
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int remove = 0;
        int n = intervals.size();
        int lastIntervalIndex = 0; // For not using extra space for result just track last pushed interval
        for(int i=1;i<n;i++){
            vector<int> curr = intervals[i];
            if(intervals[lastIntervalIndex][1] > curr[0]) {
                remove++;
            }
            else{
                lastIntervalIndex = i;
            }
        }
        return remove;
    }
};