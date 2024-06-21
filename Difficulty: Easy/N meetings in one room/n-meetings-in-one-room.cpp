//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Create a vector of pairs where each pair consists of the end time
        // and the start time of a meeting.
        vector<pair<int, int>> meetings;
        
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }
        
        // Sort the meetings based on their end time.
        sort(meetings.begin(), meetings.end());
        
        // Initialize the count of meetings and the end time of the last attended meeting.
        int cnt = 1;
        int last_end_time = meetings[0].first;
        
        // Iterate through the sorted meetings.
        for (int i = 1; i < n; i++) {
            // If the start time of the current meeting is greater than the end time
            // of the last attended meeting, attend this meeting.
            if (meetings[i].second > last_end_time) {
                cnt++;
                last_end_time = meetings[i].first;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends