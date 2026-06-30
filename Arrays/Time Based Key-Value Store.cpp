/*
    Time Complexity:
        set() -> O(1)
        get() -> O(log n)

    Space Complexity:
        O(N)
        where N is the total number of (timestamp, value) pairs stored.

    Intuition:
        - For every key, maintain a list of (timestamp, value) pairs.
        - The problem guarantees that timestamps are inserted in strictly
          increasing order, so the vector is already sorted.
        - For set(), simply append the new pair.
        - For get(), perform binary search to find the largest timestamp
          less than or equal to the given timestamp.
        - After binary search:
              * r = index of the largest timestamp <= target.
              * If r < 0, no valid timestamp exists.
*/

class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";
        vector<pair<int,string>> &arr=mp[key];
        int n=arr.size();
        int l=0,r=n-1;
        
        while(l<=r)
        {
            int m=l+((r-l)/2);
            if(arr[m].first==timestamp)
            {
                return arr[m].second;
            }
            else if(arr[m].first>timestamp)
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }

        if(r<0) return "";
        return arr[r].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
