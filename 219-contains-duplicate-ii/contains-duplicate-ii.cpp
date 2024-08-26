class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numMp;
        for( int i =0; i<nums.size(); ++i)
        {
            if(numMp.find(nums[i]) != numMp.end() && i - numMp[nums[i]] <= k)
            {
                return true;
            }
            numMp[nums[i]] = i;
        }
        return false;
    }
};