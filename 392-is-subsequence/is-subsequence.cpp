#include <string>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1)
    bool isSubsequence(string s, string t) {
        int s_ptr = 0, t_ptr=0;
        for (; t_ptr < t.size(); t_ptr++)
        {
            if (s[s_ptr]==t[t_ptr])
            {
                s_ptr++;
            }
        }
        return s_ptr==s.size()?true:false;
    }
};