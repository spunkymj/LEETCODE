class LRUCache {
public:
    int sz;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> lst;
    LRUCache(int capacity) {
        sz=capacity;
    }
    
    int get(int key) {
        auto it=mp.find(key);
        if(it==mp.end()){
            return -1;
        }

        /*
        The list::splice() is a built-in function in C++ STL which is used to      transfer elements from one list to another.
        
        list1_name.splice (iterator position, list2)
               or 
        list1_name.splice (iterator position, list2, iterator i)
               or 
        list1_name.splice (iterator position, list2, iterator first, iterator last)
        */

        lst.splice(lst.begin(),lst,it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it=mp.find(key);
        if(it!=mp.end()){
            lst.splice(lst.begin(),lst,it->second);
            it->second->second=value;
            return;
        }
        if(lst.size()==sz){
            int key_to_delete=lst.back().first;
            lst.pop_back();
            mp.erase(key_to_delete);
        }
        lst.push_front({key,value});
        mp[key]=lst.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */