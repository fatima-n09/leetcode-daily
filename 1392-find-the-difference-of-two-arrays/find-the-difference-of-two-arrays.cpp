class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> answer(2);
        unordered_set<int> s1{nums1.begin(), nums1.end()};
        unordered_set<int> s2{nums2.begin(), nums2.end()};
        for( const int num : s1)
        {
            if(!s2.count(num))
            {
                answer [0].push_back(num);
            }
        }
         for( const int num : s2)
        {
            if(!s1.count(num))
            {
                answer [1].push_back(num);
            }
        }
        return answer;
    }
};