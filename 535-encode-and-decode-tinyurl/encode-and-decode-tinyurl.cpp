class Solution {
public:
    unordered_map<string, string> UrlMap;
    int id  = 0;
    string base ="http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string shortUrl = base + to_string(id);
        UrlMap[shortUrl] = longUrl;
        id++;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
     return UrlMap[shortUrl];   
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));