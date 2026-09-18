class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> v;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        v.push_back(val);
        mp[val]=v.size()-1;
        return true;
    }

    void swap(int val) {
        int pos=mp[val];
        int lastitem=v[v.size()-1];
        v[pos]=lastitem;
        mp[lastitem]=pos;
        v.pop_back();
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        swap(val);
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */