// Problem - Return the length of highest mountain
/**
A mountain is defined as a set of adjacent integers that are
strictly increasing until they reach a peak, at which they
become strictly decreasing.
At least three numbers are required to form a mountain.
**/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findLargestMountain(vector<int> mountain){
    int result = 0;
    int tempResult = 0;
    for(int i = 1; i < mountain.size() - 1; i++){
        if(mountain[i - 1] < mountain[i] && mountain[i + 1] < mountain[i]){
            tempResult = 0;
            int x = i;
            int y = i - 1;
            while(mountain[y] < mountain[x]){
                if(y < 0)
                    break;
                x--;
                y--;
                tempResult++;
            }
        }
        else if(mountain[i] < mountain[i-1]){
            tempResult++;
        }
        if(result < tempResult){
            result = tempResult;
        }
    }

    return result + 1;
}

int main() {
    vector<int> mountain = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,2,4};
    int largestMountain = findLargestMountain(mountain);

    cout << "Largest Mountain is: " << largestMountain;
}