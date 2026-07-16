#include <string>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1)
    int maxVowels(string s, int k) {
        int max_count=0, cur_count=0;
        
        for (int i = 0; i < k; i++)
        {
            cur_count+=isVowel(s[i]);
        }
        max_count=cur_count;

        for (int right_ptr = k; right_ptr < s.size(); right_ptr++)
        {
            cur_count=cur_count-isVowel(s[right_ptr-k])+isVowel(s[right_ptr]);
            max_count=max(cur_count,max_count);
        }
        return max_count;
    }
private:
    inline bool isVowel(char c)
    {
        switch (c)
        {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                return true;
            default:
                return false;
        }
    }
};