used prefix and suffx product arrays 

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the product of all
// elements except the current element
vector<int> productExceptSelf(vector<int> &arr) {
    int n = arr.size();
    vector<int> prefProduct(n), suffProduct(n), res(n);

    // Construct the prefProduct array
    prefProduct[0] = 1;
    for (int i = 1; i < n; i++)
        prefProduct[i] = arr[i - 1] * prefProduct[i - 1];

    // Construct the suffProduct array
    suffProduct[n - 1] = 1;
    for (int j = n - 2; j >= 0; j--)
        suffProduct[j] = arr[j + 1] * suffProduct[j + 1];

    // Construct the result array using
    // prefProduct[] and suffProduct[]
    for (int i = 0; i < n; i++)
        res[i] = prefProduct[i] * suffProduct[i];
    
    return res; 
}

int main() {
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = productExceptSelf(arr);

    for (int val : res)
        cout << val << " ";
}
