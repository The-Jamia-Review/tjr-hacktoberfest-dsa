class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] answer = new int[n];

        int leftproduct = 1;
        int rightproduct = 1;

        for (int i = 0; i < n; i++) {
            answer[i] = leftproduct;
            leftproduct *= nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= rightproduct;
            rightproduct *= nums[i];
        }

        return answer;
    }
}
