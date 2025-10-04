class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftproducts(nums.size());
        vector<int> rightproducts(nums.size());

        vector<int> finalarr(nums.size());

        int leftproduct = 1;
        int rightproduct = 1;

        for(int i = 0; i < nums.size(); i++) {
            leftproducts.at(i) = leftproduct;
            leftproduct *= nums.at(i);
        }

        for(int i = nums.size() - 1; i >= 0; i--) {
            rightproducts.at(i) = rightproduct;
            rightproduct *= nums.at(i);
        }

        for(int i = 0; i < nums.size(); i++) {
            finalarr.at(i) = leftproducts.at(i) * rightproducts.at(i);
        }

        return finalarr;
    }
};
