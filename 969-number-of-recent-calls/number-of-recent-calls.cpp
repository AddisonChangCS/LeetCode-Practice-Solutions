#include <vector>
using namespace std;
//Overall Time: O(N) (with sliding window optimize)
//Overall Space: O(N)
class RecentCounter {
public:
    RecentCounter() {};
    //Time: Amortized O(1) per ping
    //Space: O(N)
    int ping(int t) {
        time_seg.push_back(t);
        while (time_seg[left_ptr]<t-3000) left_ptr++;
        return time_seg.size()-left_ptr;
    }
private:
    vector<int> time_seg;
    int left_ptr=0;
};