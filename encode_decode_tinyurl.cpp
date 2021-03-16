// https://leetcode.com/problems/encode-and-decode-tinyurl/

class Solution {
protected:
    unordered_map<unsigned long, string> m_mapURLs;
    
    const string m_strBaseUrl = "http:////tinyurl.com//";
    
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        unsigned long hashedURL = static_cast<unsigned long>(hash<string>{}(longUrl));
        
        m_mapURLs[hashedURL] = longUrl;
        
        stringstream stream;
        stream << m_strBaseUrl << hex << hashedURL;
        
        return stream.str();
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        // shortUrl should be [m_strBaseUrl + hash]
        size_t hashStart = shortUrl.rfind(m_strBaseUrl.back());
        if (hashStart == string::npos)
            return "";
        
        string strHash = shortUrl.substr(hashStart + 1, string::npos);
        unsigned long ulHash = stoul(strHash, 0, 16);
        
        return m_mapURLs[ulHash];
    }
};
