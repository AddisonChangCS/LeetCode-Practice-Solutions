#include <string>
#include <numeric>
using namespace std;
class Solution {
public:
    //Time: O(N+M)
    //Space: O(N+M)
    string gcdOfStrings(string str1, string str2) {
        //verify if there is a GCD
        if (str1+str2!=str2+str1)//time: O(N+M), space: O(N+M)
        {
            return "";
        }

        //calculate the GCD of length
        int str_GCD_size=gcd(str1.size(), str2.size());

        //return string GCD by size
        return str1.substr(0,str_GCD_size);
    }
};