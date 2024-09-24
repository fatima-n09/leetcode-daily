class Solution {
public:
    int maxLength(vector<string>& arr)
    {
        auto hasUniqueCharacters = [](const string& str)
        {
            unordered_set<char> charSet;

            for (char c : str)
            {
                if (charSet.count(c) > 0)
                {
                    return false;
                }

                charSet.insert(c);
            }

            return true;
        };

        int maxLength = 0;

        for (int i = 0; i < (1 << arr.size()); ++i)
        {
            string concatenatedString;
            for (int j = 0; j < arr.size(); ++j)
            {
                if (i & (1 << j))
                {
                    concatenatedString += arr[j];
                }
            }

            if (hasUniqueCharacters(concatenatedString))
            {
                maxLength = max(maxLength, static_cast<int>(concatenatedString.size()));
            }
        }

        return maxLength;
    }
};