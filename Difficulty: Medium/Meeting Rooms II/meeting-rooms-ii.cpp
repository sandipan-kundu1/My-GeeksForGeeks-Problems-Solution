class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n=start.size();
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int s=0,e=0,room=0,maxroom=0;
        while(s<n)
        {
            if(start[s]<end[e])//collision cases
            {
                room++;
                s++;
            }
            else
            {
                room--;
                e++;
            }
            maxroom=max(room,maxroom);
        }
        return maxroom;
    }
};
