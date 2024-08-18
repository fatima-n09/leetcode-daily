class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() <= 2) {
            return -1;
        }
        
        insertionSort(nums);

        return nums[1]; 
    }

private:
    void insertionSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            int temp = nums[i];
            int j;
            for (j = i; j > 0 && nums[j - 1] > temp; --j) {
                nums[j] = nums[j - 1];
            }
            nums[j] = temp;
        }
    }
};
