#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(int target,const std::vector<int> &vec) {
    int low = 0;
    int high = vec.size()-1;
    while (low<=high) {
        int mid = low + (high-low)/2;
        if (target==vec[mid]) return mid;
        else if (target<vec[mid]) high = mid-1;              //changing the low and high ends accordingly
        else low = mid+1;
    }
    return -1;
}

int main() {
    int size;
    std::cout << "Enter the size of the array: " << "\n";  //inputing the size of the array form the user
    std::cin  >> size;
    std::vector<int> arr(size);
    std::cout << "Enter the elements of the array: " << "\n";
    for (int i=0;i<size;i++) {
        std::cin >> arr[i];                                 //intialising the array
    }
    std::sort(arr.begin(),arr.end());
    int target;
    std::cout << "Enter the element to be checked" << "\n";
    std::cin >> target;
    int index = binarySearch(target,arr);
    if (index == -1) std::cout << "Element isn't available in the Array";
    else std::cout << "Element exists at index: " << index << "\n";
}


// ------ NOTE ----- //
// Whenever the target is not available in the list .. and the moment binary search ends up the pointer
// left stores the index of next greater element and right stores the index of next smaller element than target