class Solution {
public:
    string largestGoodInteger(string nums) {
        string results;
        int n=nums.size();
        if(n<3){
            return results;
        }
        for(int i=0; i<=n-3; i++){
            if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) 
            {
                string current = nums.substr(i, 3);
                results = max(results, current);
            }
        }
        return results;
    }
};