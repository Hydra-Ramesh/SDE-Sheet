#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        if (arr.empty()) return 0; // Handle edge case when array is empty

        int i = 0; // Pointer to track unique elements
        for (int j = 1; j < arr.size(); j++) {
            if (arr[i] != arr[j]) {
                i++;
                arr[i] = arr[j]; // Move the unique element to the front
            }
        }
        return i + 1; // Length of the unique element array
    }
};

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    
    Solution solution;
    int newSize = solution.removeDuplicates(arr);
    
    cout << "New size: " << newSize << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

