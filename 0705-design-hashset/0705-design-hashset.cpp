class MyHashSet {
vector<bool>set;
public:
    MyHashSet() {
        
        set = vector<bool>(1e6+1);
    }
    
    void add(int key) {
        set[key]= true;
    }
    
    void remove(int key) {
        set[key] = false;   
    }
    
    bool contains(int key) {
        return set[key] == true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */