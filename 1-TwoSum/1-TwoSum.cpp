class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ans(2);
        unordered_map<int,int> diffPosition;

        int i = 0;
        for (const int & n : nums)
            if (diffPosition.contains(n)) {
                ans[0] = i;
                ans[1] = diffPosition[n];
                break;
            }
            else diffPosition[target - n] = i++;

        

        return ans;
    }
};