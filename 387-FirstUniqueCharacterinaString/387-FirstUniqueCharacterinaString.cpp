class Solution {
public:
    int firstUniqChar(string s)
    {
        unsigned int count[26] = { 0 };

        for (const auto & c : s)
            count[c - 'a']++;

        int ans = 0;
        for (const auto & c : s)
            if (count[c - 'a'] == 1) return ans;
            else ans++;

        return -1;
    }
};