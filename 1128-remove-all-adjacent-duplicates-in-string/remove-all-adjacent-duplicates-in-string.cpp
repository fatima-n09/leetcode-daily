class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char> charStack;
        for (char c: s)
        {
            if(!charStack.empty() && c == charStack.top())
            {
                charStack.pop();
            }
            else{
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