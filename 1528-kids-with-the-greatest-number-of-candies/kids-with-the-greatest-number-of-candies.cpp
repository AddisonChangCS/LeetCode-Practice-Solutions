#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1)
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candidate=*(max_element(candies.begin(),candies.end()));//O(N)
        vector<bool> result(candies.size());
        for (int i = 0; i < candies.size(); i++)
        {
            result[i]=(candies[i]+extraCandies)>=max_candidate ? true : false;
        }
        return result;
    }
};