#include <vector>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1)
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        for (int i = 0; i < flowerbed.size(); i++)
        {
           if (flowerbed[i]==0)
           {
                bool left_empty=(i==0 || flowerbed[i-1]==0);
                bool right_empty=(i==flowerbed.size()-1 || flowerbed[i+1]==0);

                if (left_empty && right_empty)
                {
                    flowerbed[i]=1;
                    n--;
                }
           }
           if (n<=0)
           {
                return true;
           }
        }

        return false;
    }
};