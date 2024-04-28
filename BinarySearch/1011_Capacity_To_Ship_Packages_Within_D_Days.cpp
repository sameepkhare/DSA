/*

A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

< Here we use template to get the asnwer the only problem >
*/

class Solution {
public:
    bool condition(vector<int>& weights, int days, int capacity){
        int d = 1;
        int sum = 0; 
        for (int w: weights){
            sum += w;
            if ( sum > capacity){
                d++;
                sum = w;
            }
            if (d > days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int len = weights.size();
        int l = 0;
        int r = 0;
        for (int i = 0; i < len; i++ ){
            r += weights[i];
            if ( l < weights[i]){
                l = weights[i];
            }
        }
        while (l < r){
            int m = l + (r-l)/2;
            if ( condition(weights,days,m) == true )
                r = m; 
            else{
                l = m + 1;
            }
        }
    return l;
        
    }
};
