//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
   // Initialize floor and ceil
    int floor = -1, ceil = -1;

    // Sort the array first
    sort(arr, arr + n);

    // Use lower_bound to find the first element that is not less than x
    auto it = lower_bound(arr, arr + n, x);

    // Determine the ceil
    if (it != arr + n) {
        ceil = *it;
    }

    // Determine the floor
    if (it != arr && (it == arr + n || *it != x)) {
        floor = *(it - 1);
    } else if (it != arr + n && *it == x) {
        floor = ceil = *it;
    }

    // Handle edge cases where all elements are greater than x
    // if (it == arr) {
    //     floor = -1;
    // }

    // Handle edge cases where all elements are less than x
    // if (it == arr + n) {
    //     ceil = -1;
    // }

    return {floor, ceil};
}