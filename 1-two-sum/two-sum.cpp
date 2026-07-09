class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Time: O(N)
        //Space: O(N)
        unordered_map<int,int> seen;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement=target-nums[i];
            if (seen.find(complement) != seen.end())
            {
                //found a complement
                return {seen[complement],i};
            }
            seen[nums[i]]=i;
        }
        return {};
    }
};