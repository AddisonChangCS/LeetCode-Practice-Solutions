#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1)
    int compress(vector<char>& chars) {
        int write_ptr=0;
        for (int read_ptr = 0; read_ptr < chars.size();)
        {
            char cur_char=chars[read_ptr];
            int cons_count=0;
            while (read_ptr<chars.size() && chars[read_ptr]==cur_char)
            {
                cons_count++;
                read_ptr++;
            }
            chars[write_ptr++]=cur_char;
            if (cons_count>1)
            {
                for (char c: to_string(cons_count))
                {
                    chars[write_ptr++]=c;
                }
            }
        
        }
        return write_ptr;
    }
};