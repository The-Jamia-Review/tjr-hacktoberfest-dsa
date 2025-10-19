class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        right[0] = height[0];
        for (int i = 1; i < n; i++) {
            right[i] = max(right[i - 1], height[i]);
        }

        left[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            left[i] = max(left[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};