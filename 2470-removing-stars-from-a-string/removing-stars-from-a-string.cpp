#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1) (two pointer inplace write)
    string removeStars(string s) {
        int write_ptr=0;
        for (int read_ptr=0; read_ptr < s.size(); read_ptr++)
        {
            if (s[read_ptr]=='*'&&write_ptr>0) write_ptr--;
            else s[write_ptr++]=s[read_ptr];
        }
        s.resize(write_ptr);
        return s;
    }
};