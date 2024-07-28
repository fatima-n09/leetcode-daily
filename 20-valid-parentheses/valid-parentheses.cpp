class Solution {
public:
     bool isValid(string s) {
        stack<char> brackets;
        unordered_map<char, char> bracketsMap = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                brackets.push(c);
            } else {
                if(brackets.empty() || brackets.top() != bracketsMap[c]) {
                    return false;
                }
                brackets.pop();
            }
        }
        return brackets.empty();
    }
};
