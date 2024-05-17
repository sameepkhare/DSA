#include<bits/stdc++.h>
using namespace std;
class solution{
    private:
        void helper(vector<int> &arr, int s, int e ){
            if ( s >= e ){
                return;
            }
            int pivotIndex = s + (rand() % (e - s + 1));
            swap(arr[pivotIndex],arr[s]);
            int r = s + 1; 
            int g = s;
            while( r <= e){
                if(arr[r] <= arr[s]){
                    g++;
                    swap(arr[g],arr[r]);
                }
                r++;
            }
            swap(arr[g],arr[s]);
            helper( arr, s, g-1);
            helper( arr, g+1, e);
        }
    public:
        vector<int> quickSort(vector<int> &arr){
            helper(arr, 0, arr.size()-1 );
            return arr;
        }
};

int main(){
    // Create an instance of the solution class
    solution sol;

    // Example array to be sorted
    vector<int> arr = {10,9,8,7,6,5,4,3,2,1,90};

    // Call quickSort function to sort the array
    arr = sol.quickSort(arr);

    // Print the sorted array
    cout << "Sorted array: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}