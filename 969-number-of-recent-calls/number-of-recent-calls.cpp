#include <queue>
using namespace std;
//Overall Time: O(N)
//Overall Space: O(1)
class RecentCounter {
public:
    RecentCounter() {};
    //Time: Amortized O(1) per ping
    //Space: O(1)(<3000)
    int ping(int t) {
        time_seg.push(t);
        while (time_seg.front()<t-3000)
        {
            time_seg.pop();
        }
        return time_seg.size();
    }
private:
    queue<int> time_seg;
};