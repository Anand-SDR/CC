class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       std::unordered_set<int>ans;
       for (int i = 0; i < nums.size(); i++) {
        if (ans.count(nums[i])) {
                return true;
            }
            ans.insert(nums[i]);
       if (ans.size() > k) {
                ans.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};
