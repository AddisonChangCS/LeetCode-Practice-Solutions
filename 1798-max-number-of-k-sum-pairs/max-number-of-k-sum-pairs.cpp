#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        return solution1(nums, k);
    }
private:

    //using hash tabel
    //Time: O(N)
    //Space: O(N)
    int solution1(vector<int>& nums, int k){
        
        int operation_count=0;
        
        unordered_map<int,int> count;
        count.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            int complement=k-nums[i];
            auto it = count.find(complement);
            if (it!=count.end() && it->second)
            {
                it->second--;
                operation_count++;
            }
            else
            {
                count[nums[i]]++;
            }
        }
        return operation_count;
    }

    //using two pointer
    //Time: O(NlogN)
    //Space: O(1)
    int solution2(vector<int>& nums, int k){
        
        int operation_count=0;

        sort(nums.begin(),nums.end());

        for (int left_ptr=0, right_ptr=nums.size()-1; left_ptr < right_ptr;)
        {
            int sum=nums[left_ptr]+nums[right_ptr];
            if (sum<k)
            {
                left_ptr++;
            }
            else if (sum>k)
            {
                right_ptr--;
            }
            else
            {
                operation_count++;
                left_ptr++;
                right_ptr--;
            }
        }
        return operation_count;
    }
};