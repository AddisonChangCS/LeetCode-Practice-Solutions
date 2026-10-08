#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(N)
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        stack.reserve(asteroids.size());
        for (int const& cur_asteroid:asteroids)
        {
            bool destroyed=false;
            while (!stack.empty() && cur_asteroid < 0 && stack.back() > 0)
            {
                if (abs(cur_asteroid) > abs(stack.back())) 
                {
                    stack.pop_back();
                } 
                else if (abs(cur_asteroid) == abs(stack.back())) 
                {
                    stack.pop_back();
                    destroyed = true;
                    break;
                } 
                else 
                {
                    destroyed = true;
                    break;
                }   
            }
            if(!destroyed) stack.push_back(cur_asteroid);
            
        }
        return stack;
    }
};