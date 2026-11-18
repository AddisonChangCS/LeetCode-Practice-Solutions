class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        int front_ptr=0, back_ptr=costs.size()-1;
        //build heap
        //Time: O(ClogC);
        for(int i=0; i<candidates; i++){
            if(front_ptr<=back_ptr) min_heap.push({costs[front_ptr], front_ptr++});
            if(front_ptr<=back_ptr) min_heap.push({costs[back_ptr], back_ptr--});
        }
        long long sum=0;
        //pick candidate
        //Time: O(KlogC)
        for(int i=0; i<k; i++){
            auto [cost, index]=min_heap.top();
            min_heap.pop();
            sum+=cost;
            if(index<front_ptr && front_ptr<=back_ptr){
                min_heap.push({costs[front_ptr], front_ptr++});
            }
            else if(front_ptr<=back_ptr){
                min_heap.push({costs[back_ptr], back_ptr--});
            }
        }
        return sum;
    }
};