class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        function<void(int,int)> dfs = [&](int start, int remain){
            if (remain == 0) { ans.push_back(cur); return; }
            for (int i = start; i < (int)candidates.size(); ++i) {
                if (candidates[i] > remain) break;
                cur.push_back(candidates[i]);
                dfs(i, remain - candidates[i]);
                cur.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};
