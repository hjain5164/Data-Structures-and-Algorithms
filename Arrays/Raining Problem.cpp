// Problem - Given N non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water can be trapped after raining.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trappedWater(vector<int> height){
    int water = 0;
    vector<int> leftMax(height.size(), 0);
    vector<int> rightMax(height.size(), 0);
    leftMax[0] = height[0];
    rightMax[height.size()-1] = height[height.size() - 1];
    for(int i = 1; i < height.size(); i++){
        if(leftMax[i - 1] < height[i])
            leftMax[i] = height[i];
        else
            leftMax[i] = leftMax[i - 1];
    }
    for(int i = height.size() - 2; i >= 0; i--){
        if(rightMax[i + 1] < height[i])
            rightMax[i] = height[i];
        else
            rightMax[i] = rightMax[i + 1];
    }

    for(int i = 0; i < height.size(); i++){
        water += min(leftMax[i], rightMax[i]) - height[i];
    }

    return water;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "Water Trapped is: " << trappedWater(height) << " units";

}
