class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //sort potions
        //Time: O(NlogN)
        std::sort(potions.begin(), potions.end(), [](const auto&a, const auto&b){
            return a<b;
        });
        //binary search on spells
        //Time: O(SlogN)
        vector<int> pairs(spells.size());
        for(int i=0; i<spells.size(); i++){
            int left=0, right=potions.size()-1;
            int pick;
            while(left<right){
                pick=left+(right-left)/2;
                if(static_cast<long long>(spells[i])*potions[pick]>=success) right=pick;
                else left=pick+1;
            }
            if(static_cast<long long>(spells[i])*potions[left]<success) left=potions.size();
            pairs[i]=potions.size()-left;
        }
        return pairs;
    }
};