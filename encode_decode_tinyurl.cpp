// https://leetcode.com/problems/encode-and-decode-tinyurl/

class Solution {
protected:
    unordered_map<string, string> m_mapURLs;
    
    const string m_strBaseUrl = "http:////tinyurl.com//";
    
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        size_t hashedURL = hash<string>{}(longUrl);
        
        stringstream stream;
        stream << hex << hashedURL;
        string strHash( stream.str() );
        
        m_mapURLs[strHash] = longUrl;
        
        return m_strBaseUrl + strHash;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        // shortUrl should be [m_strBaseUrl + hash]
        size_t hashStart = shortUrl.rfind(m_strBaseUrl.back());
        if (hashStart == string::npos)
            return "";
        
        string strHash = shortUrl.substr(hashStart + 1, string::npos);
        
        return m_mapURLs[strHash];
    }
    
};
