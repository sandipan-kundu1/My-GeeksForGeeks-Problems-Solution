class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int cnt5=0,cnt10=0;
        for(int i=0;i<N;i++)
        {
            if(bills[i]==5)
            cnt5++;
            else if(bills[i]==10)
            {
                if(cnt5>=1)
                {
                    cnt5--;
                    cnt10++;
                }
                else
                return false;
            }
            else
            {
                if(cnt10>=1 && cnt5>=1)
                {
                    cnt10--;
                    cnt5--;
                }
                else if(cnt5>=3)
                cnt5=cnt5-3;
                else
                return false;
            }
        }
        return true;
    }
};