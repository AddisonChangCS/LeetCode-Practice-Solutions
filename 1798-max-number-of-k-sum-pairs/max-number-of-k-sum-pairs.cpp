#include <vector>
#include <unordered_map>
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
        
        unordered_map<int,int> count;
        count.reserve(nums.size());

        int operation_count=0;

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
};