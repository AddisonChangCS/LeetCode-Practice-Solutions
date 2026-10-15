#include <queue>
using namespace std;
static const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
//Overall Time: O(N)
//Overall Space: O(1)
class RecentCounter {
public:
    RecentCounter() {};
    //Time: Amortized O(1) per ping
    //Space: O(1)(<3000)
    int ping(int t) {
        while (time_seg.front()<t-3000 && !time_seg.empty())
        {
            time_seg.pop();
        }
        time_seg.push(t);
        return time_seg.size();
    }
private:
    queue<int> time_seg;
};