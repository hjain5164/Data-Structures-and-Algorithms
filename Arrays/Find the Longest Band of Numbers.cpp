// Problem - Find the longest band of sequences from a given array of integers.
/**
A band is define as a subsequence which can be reordered in such a manner that
all elements appear consecutive (i.e. with absolute difference of 1 between
neighbouring elements). A longest band is the band with maximum number of integers.
**/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestBand(unordered_set<int> s){
    int result = 0;
    for(int i: s){
        int lookup = i - 1;
        int count = 0;
        if(s.find(lookup) == s.end()){
            int nextNum = lookup + 1;
            while(s.find(nextNum) != s.end()){
                nextNum++;
                count++;
            }
        }
        if(result < count)
            result = count;
    }

    return result;
}

int main() {
    unordered_set<int> s = {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};

    cout << "Longest Band is: " << longestBand(s);
}
