#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    //Time: O(N)(N is final string size)
    //Space: O(N)(N is final string size)
    string decodeString(string s) {
        int cur_count=0;
        string cur_str="", copy_str="";
        vector<pair<int, string>> stack;
        for (char const& c : s)
        {
            if (is_digit(c))
            {
                cur_count=get_digit(c, cur_count);
            }
            else if (c=='[')
            {
                stack.push_back({cur_count, cur_str});
                cur_count=0;
                cur_str="";
            }
            else if (c==']')
            {
                auto [last_count, last_str] = stack.back();
                stack.pop_back();

                copy_str="";
                for(int i=0; i<last_count; i++)copy_str+=cur_str;
                cur_count=0;
                cur_str=last_str+copy_str;
            }
            else
            {
                cur_str+=c;
            }
        }
        return cur_str;
    }
private:
    bool is_digit(char c){
        return c>='0' && c<='9';
    }
    int get_digit(char c, int cur_count){
        return cur_count*10+(c-'0');
    }
};