class SmallestInfiniteSet {
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
private:
    priority_queue<int, vector<int>, greater<int>> add_back;
    unordered_set<int> add_back_set;
    int pointer;
public:
    SmallestInfiniteSet() {
        pointer=1;
    }
    
    int popSmallest() {
        if(add_back.empty() || pointer < add_back.top()){
            return pointer++;
        }
        else{
            add_back_set.erase(add_back.top());
            int val=add_back.top();
            add_back.pop();
            return val;
        }
    }
    
    void addBack(int num) {
        if(!add_back_set.contains(num) && num<pointer){
            add_back_set.insert(num);
            add_back.push(num);
        }
    }
};