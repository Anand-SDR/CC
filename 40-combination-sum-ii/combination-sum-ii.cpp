class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& nums, int target, int start) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < nums.size(); i++) {

            if (i > start && nums[i] == nums[i - 1])
                continue;

            if (nums[i] > target)
                break;

            temp.push_back(nums[i]);

            solve(nums, target - nums[i], i + 1);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        solve(candidates,target, 0);

        return ans;
    }
};