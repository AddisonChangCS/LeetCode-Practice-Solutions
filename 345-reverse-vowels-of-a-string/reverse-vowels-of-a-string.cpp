#include <string>
#include <utility>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1)
    string reverseVowels(string s) {
        int left_ptr = 0, right_ptr = s.size()-1;
        while(left_ptr < right_ptr)
        {
            while (!isVowel(s[left_ptr]) && left_ptr<right_ptr)
            {
                left_ptr++;
            }
            while (!isVowel(s[right_ptr]) && left_ptr<right_ptr)
            {
                right_ptr--;
            }
            if (left_ptr<right_ptr)
            {
                swap(s[left_ptr],s[right_ptr]);
                left_ptr++;
                right_ptr--;
            }
        }
        return s;
    }
private:
    const string vowels="aeiouAEIOU";
    bool isVowel(char c){
        return vowels.find(c) != string::npos;
    }
};