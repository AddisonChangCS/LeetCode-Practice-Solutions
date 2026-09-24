#include <string>
#include <algorithm>
#include <array>
using namespace std;
class Solution {
public:
    //Time: O(N+M)
    //Space: O(1)
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;

        array<int, 26> set1={0}, set2={0};
        //cost time: O(N+M)
        for (char const& ch : word1) set1[ch-'a']++;
        for (char const& ch : word2) set2[ch-'a']++;
        
        //cost time: O(1)
        for (int i = 0; i < 26; i++)
        {
            if((set1[i]>0)^(set2[i]>0)) return false;
        }
        
        //cost time:O(1)
        sort(set1.begin(), set1.end());
        sort(set2.begin(), set2.end());
        for (int i = 0; i < 26; i++)
        {
            if(set1[i]!=set2[i]) return false;
        }
        return true;
    }
};