 class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> setBits;
        map<int, int> mp;
        for (auto num : nums) {
            int count = 0;
            for (int i = 0; i < 31; i++) {
                if ((num & 1 << i))
                    count++;
            }
            mp[num] = count;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    if (mp[nums[i]] != mp[nums[j]])
                        return false;
                }
            }
        }
        return true;
    }
};