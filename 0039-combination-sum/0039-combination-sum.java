class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        backtrack(candidates, target, 0, new ArrayList<>(), ans);
        return ans;
    }

    private void backtrack(int[] candidates, int remain, int start, List<Integer> cur, List<List<Integer>> ans) {
        if (remain == 0) {
            ans.add(new ArrayList<>(cur));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            if (candidates[i] > remain) break;
            cur.add(candidates[i]);
            backtrack(candidates, remain - candidates[i], i, cur, ans);
            cur.remove(cur.size() - 1);
        }
    }
}
