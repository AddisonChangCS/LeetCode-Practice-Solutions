class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        //build pair vector
        //Time: O(N)
        vector<pair<int,int>> nums(nums1.size());
        for(int i=0; i<nums.size(); i++){
            nums[i]={nums1[i], nums2[i]};
        }
        //sort pair vector
        //Time: O(NlogN)
        std::sort(nums.begin(), nums.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });
        //use K minHeap to find maximum
        //Time: O(NlogK)
        priority_queue<int, vector<int>, greater<int>> min_heap;
        long long sum=0, max_score=0;
        for(int i=0; i<k; i++){
            min_heap.push(nums[i].first);
            sum+=nums[i].first;
        }
        max_score=sum*nums[k-1].second;
        for(int i=k; i<nums.size(); i++){
            if(nums[i].first>min_heap.top()){
                sum=sum - min_heap.top() + nums[i].first;
                min_heap.pop();
                min_heap.push(nums[i].first);
            }
            if(sum*nums[i].second>max_score){
                max_score=sum*nums[i].second;
            }
        }
        return max_score;
    }
};