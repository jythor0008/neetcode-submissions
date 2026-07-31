class TimeMap {
    unordered_map<string, vector<pair<int, string>> > hm;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hm[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!hm.count(key)) return "";
        vector<pair<int, string>>& v = hm[key];
        int l = 0, r = v.size()-1;
        string res = "";
        int largest = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(v[mid].first > timestamp) r = mid - 1;
            else{
                res = v[mid].second;
                l = mid + 1;
            }
        }
        return res;
        
    }
};
