#include <algorithm>
class Solution {
    int candays(vector<int> & weights, int cap){
        int load = 0,days = 1;
        for(int i = 0; i < weights.size(); i++){
            if (weights[i]+load > cap) load = weights[i], days+=1;
            else load += weights[i];
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end()),high = accumulate(weights.begin(),weights.end(),0),mid = 0;
        while(low <= high){
            mid = (low + high)/2;
            if (candays(weights,mid)<=days) high = mid - 1;
            else low = mid + 1;
        }    
        return low;
    }
};