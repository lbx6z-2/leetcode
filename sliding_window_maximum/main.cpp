#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int 
*/
void display(deque<int> nums) {
    deque<int>::iterator it;
    for (it = nums.begin(); it != nums.end(); it ++) {
        cout << *it << ' ';
    }
    cout << endl;
}

int findMax(deque<int>& nums) {
    deque<int>::iterator it;
    int max = *nums.begin();
    for (it = nums.begin(); it != nums.end(); it ++) {
        if (*it > max)
            max = *it;
    }
    return max;
}

int main() {
    int arrayNums[] = {1,3,-1,-3,5,3,6,7};
    vector<int> nums;
    int len = sizeof(arrayNums) / sizeof(arrayNums[0]);
    for (int i = 0; i < len; i ++) {
        nums.push_back(arrayNums[i]);
    }

    int k = 3;

    deque<int> maxWindow;
    for (int i = 0; i < k; i ++) {
        maxWindow.push_back(nums[i]);
    }
    cout << findMax(maxWindow) << ' ';
    vector<int>::iterator it;
    for (it = nums.begin() + k; it != nums.end(); it ++) {
        maxWindow.pop_front();
        maxWindow.push_back(*it);
        cout << findMax(maxWindow) << ' ';
    }
    cout << endl;

    return 0;
}    
