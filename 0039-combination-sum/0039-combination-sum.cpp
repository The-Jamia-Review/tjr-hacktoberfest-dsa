class Solution {
public:
    vector<vector<int>> res;
    
    void dfs(vector<int>& candidates, int target, int idx, vector<int>& path) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (idx >= candidates.size() || target < 0) return;
        
        path.push_back(candidates[idx]);
        dfs(candidates, target - candidates[idx], idx, path);
        path.pop_back();
        
        dfs(candidates, target, idx + 1, path);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        dfs(candidates, target, 0, path);
        return res;
    }
};
