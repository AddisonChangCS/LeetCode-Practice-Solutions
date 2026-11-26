class Solution {
public:
    //Time: O(NlogK)
    //Space: O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        int min=1, max=*max_element(piles.begin(), piles.end());
        while(min<max){
            int k=min+(max-min)/2;
            int hours=0;
            for(int i=0; i<piles.size(); i++){
                hours+=(piles[i]+k-1)/k;
            }
            if(hours<=h){
                max=k;
            }
            else if(hours>h){
                min=k+1;
            }
        }
        return min;
    }
};