class Solution {
public:
    vector<int> Prime(int n) {
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) 
                    isPrime[j] = false;
            }
        }
        
        for (int i = 2; i <= n; i++) 
            if (isPrime[i]) 
                primes.push_back(i);
        
        return primes;
    }
    
    bool primeSubOperation(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        vector<int> primes = Prime(n);
        

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] >= nums[i + 1]) {
                int diff = nums[i] - nums[i + 1];
                auto it = upper_bound(primes.begin(), primes.end(), diff);
                

                if (it == primes.end() || *it >= nums[i]) 
                    return false;
                
                nums[i] -= *it; 
            }
        }
        
        return true;
    }
};
