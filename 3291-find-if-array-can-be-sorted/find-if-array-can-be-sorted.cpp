 class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> setBits;
        map<int, int> map;
        for (auto num : nums) {
            int count = 0;
            for (int i = 0; i < 31; i++) {
                if ((num & 1 << i))
                    count++;
            }
            map[num] = count;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    if (map[nums[i]] != map[nums[j]])
                        return false;
                }
            }
        }
        return true;
    }
};