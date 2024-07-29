class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
    return processString(s) == processString(t);
    }
    private:
    string processString(string str)
    {
        string res;
        for( char ch: str)
       {
         if(ch=='#')
         {
             if(!res.empty())
            {
                res.pop_back();
            }
         } 
            else
            {
                res.push_back(ch); 
            }           
        }
        return res;
    }
};