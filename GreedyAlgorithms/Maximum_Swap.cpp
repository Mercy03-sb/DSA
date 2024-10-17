#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        int maxIndex = -1;
        int swapIndex1 = -1;
        int swapIndex2 = -1;
        string number = to_string(num);
        int n = number.length();
        for(int i=n-1;i>=0;i--){
            if(maxIndex == -1 || number[i] > number[maxIndex]){
                maxIndex = i;
            }
            else if(number[i] < number[maxIndex]){
                swapIndex1 = i;
                swapIndex2 = maxIndex;
            }
        }
        if(swapIndex1 != -1 && swapIndex2 != -1){
            swap(number[swapIndex1], number[swapIndex2]);
        }
        return stoi(number);
    }
};