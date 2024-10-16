// LeetCode 781
#include <bits/stdc++.h>
using namespace std;
// Here we just to have to think of the math expression to club the numbers
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for(int color : answers){
            mp[color]++;
        }
        int totalRabbits = 0;
        for(auto ele : mp){
            if(ele.first == 0) totalRabbits += ele.second;
            else if(ele.second <= ele.first + 1) totalRabbits += ele.first + 1;
            else {
                totalRabbits += ceil((ele.second)/(float)(ele.first + 1))*(ele.first + 1);
            }
        }
        return totalRabbits;
    }
};