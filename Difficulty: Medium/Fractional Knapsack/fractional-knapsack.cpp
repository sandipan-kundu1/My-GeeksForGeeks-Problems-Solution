// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double,double>> v;
        int n=wt.size();
        for(int i=0;i<n;i++)
        {
            double ratio = (double)val[i] / wt[i]; // Use floating point
            v.push_back({ratio, wt[i]});
        }
        sort(v.rbegin(),v.rend());
        double total=0.0;
        for(auto &p:v)
        {
            if(p.second<=capacity)
            {
                total+=p.first*p.second;
                capacity-=p.second;
            }
            else
            {
                total+=p.first*capacity;
                break;
            }
        }
        return total;
    }
};
