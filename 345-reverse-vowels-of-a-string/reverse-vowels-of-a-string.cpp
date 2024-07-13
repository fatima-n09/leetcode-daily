class Solution {
public:
    string reverseVowels(string s) 
    {
        int i = 0;
        int j = s.size() - 1;
        string vowels = "aeiouAEIOU";  // Include uppercase vowels too
        
        while (i < j)
        {
            // Move i forward until it points to a vowel or surpasses j
            while (i < j && vowels.find(s[i]) == string::npos) {
                i++;
            }
            // Move j backward until it points to a vowel or surpasses i
            while (i < j && vowels.find(s[j]) == string::npos) {
                j--;
            }
            // Swap the vowels and move both pointers
            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
