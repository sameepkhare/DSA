#include<bits/stdc++.h>

using namespace std;

class solution{

private:
    void helper(vector<int> &arr, int s, int e, int index){
        // Base case: if the start index is greater than or equal to the end index, return
        if ( s >= e ){
            return;
        }
        
        // Randomly select a pivot index
        int pivotIndex = s + (rand()% (e - s + 1));
        // Move the pivot element to the start of the array
        swap(arr[pivotIndex], arr[s]);
        
        int r = s + 1;
        int g = s;
        while ( r <= e ){
            if(arr[r] <= arr[s]){
                g++;
                swap(arr[g],arr[r]);
            }
            r++;
        }
        // Move the pivot element to its correct position
        swap(arr[g],arr[s]);
        
        // If the pivot is at the kth largest position, return
        if (g == index){
            return;
        }
        // If the pivot is to the left of the kth largest position, recursively call helper for the right subarray
        else if(g < index){
            helper( arr, g+1, e, index);
        }
        // If the pivot is to the right of the kth largest position, recursively call helper for the left subarray
        else{
            helper(arr, s, g-1, index);
        }
    }

public:
    vector<int> findKthLargest(vector<int> &arr, int k){
        // Calculate the index of the kth largest element
        int index = arr.size() - k;
        // Call helper function to find the kth largest element
        helper(arr,0,arr.size()-1, index);
        return arr;
    }
};

int main(){
    // Create an instance of the solution class
    solution sol;

    // Example array
    vector<int> arr = {10,9,8,7,6,5,4,3,2,1,90};

    // Find the 2nd largest element
    arr = sol.findKthLargest(arr, 2);

    // Print the kth largest element
    cout << "Kth largest: " << arr[arr.size() - 2] << endl;

    return 0;
}
