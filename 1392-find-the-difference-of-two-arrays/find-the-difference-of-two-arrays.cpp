#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    //Time: O(N+M)
    //Space: O(N+M)
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        //reserve size for vector, optimized the time consumed for set resize
        set1.reserve(nums1.size());
        set1.insert(nums1.begin(), nums1.end());
        set2.reserve(nums2.size());
        set2.insert(nums2.begin(), nums2.end());

        vector<vector<int>> answer(2);
        for (int i : set1)
        {
            if (set2.find(i)==set2.end())
            {
                answer[0].push_back(i);
            }
        }
        for (int i : set2)
        {
            if (set1.find(i)==set1.end())
            {
                answer[1].push_back(i);
            }
        }
        
        return answer;
    }
};