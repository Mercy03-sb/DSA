// GFG Practice (Minimum Cost to cut a board into squares).
// TotalCost = TotalCost + edgeCost*TotalPieces.  (Imp)
// Approach we will cut the edge having maxCost first as totalPieces will get minimize
#include <bits/stdc++.h>
using namespace std;
// TotalPieces to consider for performing horizontalCut is verticalCuts + 1 and vice-versa
class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        int horizontalCuts = 0;
        int verticalCuts = 0;
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<X.size();i++) pq.push({X[i], 1});
        for(int i=0;i<Y.size();i++) pq.push({Y[i], 0});
        // '1' depicts Vertical Cut
        // '0' depicts Horizontal Cut
        int TotalCost = 0;
        while(pq.size() > 0){
            int cutCost = pq.top().first;
            int cutType = pq.top().second;
            pq.pop();
            if(cutType == 0) {
               TotalCost += cutCost*(verticalCuts + 1);
               horizontalCuts++;
            } 
            else {
                TotalCost += cutCost*(horizontalCuts + 1);
                verticalCuts++;
            }
        }
        return TotalCost;
    }
};