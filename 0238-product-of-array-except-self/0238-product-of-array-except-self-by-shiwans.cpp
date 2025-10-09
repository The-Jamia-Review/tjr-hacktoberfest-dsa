#include <bits/stdc++.h>
using namespace std;

/*
 * Function: productExceptSelf
 * ---------------------------
 * Given an integer array 'nums', this function returns an array 'answer'
 * where answer[i] is the product of all elements of nums except nums[i].
 *
 * Constraint: Do not use division and achieve O(n) time complexity.
 *
 * Approach:
 * 1. Use two passes:
 *    - First pass (left to right): Compute prefix product for each element.
 *    - Second pass (right to left): Compute suffix product and multiply it with the prefix.
 * 2. Maintain running prefix and suffix multipliers to achieve O(1) extra space (excluding output).
 */
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> answer(n, 1);  // Initialize all elements as 1

    int prefix = 1;  // Product of all elements to the left of current index
    for (int i = 0; i < n; i++) {
        answer[i] = prefix;   // Store product of elements before i
        prefix *= nums[i];    // Update prefix for next index
    }

    int suffix = 1;  // Product of all elements to the right of current index
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= suffix;  // Multiply current prefix with right-side product
        suffix *= nums[i];    // Update suffix for next index (moving left)
    }

    return answer;  // Final result
}

int main() {
    // Example Input
    vector<int> nums = {1, 2, 3, 4};

    // Compute result
    vector<int> res = productExceptSelf(nums);

    // Output
    cout << "Output: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}

/*
Expected Output:
Output: 24 12 8 6

Explanation:
- For index 0: 2 * 3 * 4 = 24
- For index 1: 1 * 3 * 4 = 12
- For index 2: 1 * 2 * 4 = 8
- For index 3: 1 * 2 * 3 = 6
*/
