// https://leetcode.com/problems/lru-cache/

class LRUCache
{
protected:
    const int m_nCapacity;
    
    struct cacheData {
        int value;
        
        // store iterators from m_usageTracker to allow put and get to have O(1) time complexity
        std::list<int>::iterator itTrackerPos;
    };
    
    std::unordered_map<int, cacheData> m_mapCacheData;
    
    // track order of item usage
    std::list<int> m_usageTracker;
    
private:
    // move key to the top of the usage queue
    void resetUsage(int key)
    {
        m_usageTracker.erase(m_mapCacheData[key].itTrackerPos);
        m_mapCacheData[key].itTrackerPos = m_usageTracker.insert(m_usageTracker.begin(), key);
    }
    
public:
    LRUCache(int capacity) : m_nCapacity(capacity)
    {
        m_mapCacheData.reserve(capacity);
    }
    
    int get(int key)
    {
        std::unordered_map<int, cacheData>::iterator it = m_mapCacheData.find(key);
        if(it != m_mapCacheData.end())
        {
            resetUsage(key);
            return it->second.value;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value)
    {
        // update value
        std::unordered_map<int, cacheData>::iterator dataIterator = m_mapCacheData.find(key);
        if(dataIterator != m_mapCacheData.end())
        {
            resetUsage(key);
            dataIterator->second.value = value;
            return;
        }
        
        // remove least recent items
        while(m_mapCacheData.size() >= m_nCapacity)
        {
            int nLRUKey = m_usageTracker.back();
            
            m_mapCacheData.erase(nLRUKey);

            m_usageTracker.pop_back();
        }
        
        // add new value
        m_mapCacheData[key] = {
            value, 
            m_usageTracker.insert(m_usageTracker.begin(), key)
        };
    }
};
