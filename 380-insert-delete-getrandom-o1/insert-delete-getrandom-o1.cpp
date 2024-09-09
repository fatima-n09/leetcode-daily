class RandomizedSet {
private: 
    unordered_map<int, int>  valueToIndex;
    vector<int> elements;     
public:
    RandomizedSet() {}
    
    bool insert(int val) 
    {
        if(valueToIndex.find(val) != valueToIndex.end())
        {
            return false;
        }
        elements.push_back(val);
        valueToIndex[val] = elements.size() - 1;
        return true;
    }
    
    bool remove(int val) 
    {
        if(valueToIndex.find(val) == valueToIndex.end())
        {
            return false;
        }
        int index = valueToIndex[val];
        int lastElement = elements.back();
        elements[index] = lastElement;
        valueToIndex[lastElement] = index;
        elements.pop_back();
        valueToIndex.erase(val);

        return true;
    }
    
    int getRandom() 
    {
     int randomNumber = rand() % elements.size();
     return elements[randomNumber];   
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */