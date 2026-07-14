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
        int operation_count=0;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement=k-nums[i];
            if (count.find(complement)!=count.end() && count[complement]>0)
            {
                count[complement]--;
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