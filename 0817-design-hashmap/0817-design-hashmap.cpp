class MyHashMap {
public:
vector<pair<int,int>>mp;
    MyHashMap() {
       
        
    }
    
    void put(int key, int value) {
    bool flag = false;
    for (auto &it : mp) {  // Use a reference to modify the original vector
        if (it.first == key) {
            it.second = value;
            flag = true;
            break;  // Exit the loop once the key is found and updated
        }
    }
    if (!flag) mp.push_back({key, value});
}

int get(int key) {
    for (const auto &it : mp) {  // Use a const reference
        if (it.first == key) {
            return it.second;
        }
    }
    return -1;
}

    
    void remove(int key) {
    for (int i = 0; i < mp.size(); i++) {
        if (mp[i].first == key) {
            mp.erase(mp.begin() + i);
            break;
        }
    }
}

    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */