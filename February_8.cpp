class NumberContainers {
public:
    unordered_map<int,set<int>>nums;
    unordered_map<int,int>indx;
    NumberContainers() {}

    void change(int index, int number) {
        if(indx.find(index)!=indx.end()){
            int num = indx[index];
            nums[num].erase(index);
        }
        nums[number].insert(index);
        indx[index] = number;
    }
    
    int find(int number) {
        if(nums[number].size())return *nums[number].begin();
        else return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */