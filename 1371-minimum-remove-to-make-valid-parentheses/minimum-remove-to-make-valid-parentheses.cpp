class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
     stack<int> S;
     for(int i = 0; i < s.length(); ++i)
     {
        if(s[i] =='(')
        {
            S.push(i);
        }
        else if(s[i] == ')')
        {
            if(!S.empty())
            {
                S.pop();
            }
            else
            {
               s[i] = '*'; 
            }
        }
      }   
      while(!S.empty())
      {
         s[S.top()] = '*';
         S.pop();
      }
      string ans = "";
      for(char c : s)
      {
        if( c != '*')
        {
            ans += c;
        }
      }
      return ans;
    }
};