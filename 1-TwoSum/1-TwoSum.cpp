class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ans(2);
        unordered_map<int,int> diffPosition;

        int i = 0;
        for (const int & n : nums)
            if (diffPosition.contains(n)) break;
            else diffPosition[target - n] = i++;

        ans[0] = i;
        ans[1] = diffPosition[nums[i]];

        return ans;
    }
};