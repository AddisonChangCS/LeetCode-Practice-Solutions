#include <string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        //Time: O(M+N)
        //Space: O(1)
        int length1=word1.size(), length2=word2.size();
        string result="";
        for (int i = 0; i < max(length1,length2); i++)
        {
            if (i<length1)
            {
                result.push_back(word1[i]);
            }
            if (i<length2)
            {
                result.push_back(word2[i]);
            }
        }
        return result;
    }
};