#include "bits/stdc++.h"
using namespace std;

/**
 * Leetcode 27: https://leetcode.com/problems/remove-element
 * 
 * input:
 *      2
 *      8 2
 *      0 1 2 2 3 0 4 2
 *      4 3
 *      3 2 2 3
 * 
 * ouput:
 *      5 & 0 1 3 0 4
 *      2 & 2 2
 */

int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] != val) {
            nums[k++] = nums[i];
        }
    }

    for (int i = 0; i < n - k; i++) nums.pop_back();

    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC; cin >> TC;
    while (TC--) {
        int n, val; cin >> n >> val;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        cout << removeElement(nums, val) << endl;
        for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
        cout << endl;
    }

    return 0;
}










