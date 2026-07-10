#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1): reverse function is in place
    string reverseWords(string s) {
        //space filter(preprocessing)
        int fast_ptr=0,slow_ptr=0;
        for (;fast_ptr<s.size(); fast_ptr++)
        {
            if (s[fast_ptr] != ' ')
            {
                if (slow_ptr > 0)
                {
                    s[slow_ptr++]=' ';
                }
                while (s[fast_ptr]!=' ' && fast_ptr<s.size())
                {
                    s[slow_ptr++]=s[fast_ptr++];
                }
            }
        }
        s.resize(slow_ptr);

        reverse(s.begin(),s.end());
        
        //head|tail: head|tail of the word
        for (int head = 0, tail = 0; tail <= s.size(); tail++)
        {
            if (s[tail]==' ' || tail==s.size())
            {
                reverse(s.begin()+head,s.begin()+tail);
                head=tail+1;
            }
        }
        return s;
    }
};