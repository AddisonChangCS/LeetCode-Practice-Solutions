#include <vector>
using namespace std;
class Solution {
public:
    //Time: O(N)
    //Space: O(1)
    int maxArea(vector<int>& height) {
        int max_area=0;
        for (int left_ptr = 0, right_ptr = height.size()-1; left_ptr < right_ptr;)
        {
            int cur_area=0;
            if (height[left_ptr]>height[right_ptr])
            {
                cur_area=height[right_ptr]*(right_ptr-left_ptr);
                max_area = (max_area<cur_area) ? cur_area : max_area;
                right_ptr--;
            }
            else if (height[left_ptr]<=height[right_ptr])
            {
                cur_area=height[left_ptr]*(right_ptr-left_ptr);
                max_area = (max_area<cur_area) ? cur_area : max_area;
                left_ptr++;
            }
        }
        return max_area;
    }
};