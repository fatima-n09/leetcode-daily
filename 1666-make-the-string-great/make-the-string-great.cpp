class Solution {
public:
    string makeGood(string s) {
        stack<char> charStack;
        
        for(char c : s)
         {
            if (!charStack.empty() && abs(c-charStack.top()) == 32)        
            {
                charStack.pop();
            } else
            {
                charStack.push(c);
            }
        }
        string ans;
        while(!charStack.empty())
        {
            ans = charStack.top() + ans;
            charStack.pop();
        }
        return ans;
    }
};