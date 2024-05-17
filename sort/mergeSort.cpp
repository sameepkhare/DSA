#include <bits/stdc++.h>

using namespace std;

class mergeSortClass{
    private:
        void helper(vector<int>& arr, int l, int r){
            if( l >= r){
                return;
            }
            int m =  l + (r-l)/2;

            helper(arr, l, m);
            helper(arr, m+1, r);
            //merge left and right
            merge(arr, l, m, r);
        }
        void merge(vector<int>& arr, int l, int m, int r){
            int p1 = l, p2 = m + 1;
            vector<int> res;
            while( p1 <= m && p2 <= r){
                if(arr[p1] <= arr[p2]){
                    res.push_back(arr[p1]);
                    p1++;
                }
                else{
                    res.push_back(arr[p2]);
                    p2++;
                }
            }
            while( p1 <= m ){
                res.push_back(arr[p1++]);
            }
            while( p2 <= r ){
                res.push_back(arr[p2++]);
            }
            for (int i=0; i < res.size(); i++){
                arr[l+i] = res[i];
            }
        }
    public:
        vector<int> mergeSort ( vector<int>& arr ){
            helper(arr, 0, arr.size()-1);
            return arr;
        }
};
int main() {
    mergeSortClass sorter;
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    sorter.mergeSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
