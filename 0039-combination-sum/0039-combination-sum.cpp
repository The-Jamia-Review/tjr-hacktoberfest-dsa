class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int> &candidates, int target, int index,
                   vector<int> &current, vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(current);
            return;
        }
        if (target < 0 || index == candidates.size())
        {
            return;
        }

        current.push_back(candidates[index]);
        backtrack(candidates, target - candidates[index], index, current, result);
        current.pop_back();

        backtrack(candidates, target, index + 1, current, result);
    }
};
