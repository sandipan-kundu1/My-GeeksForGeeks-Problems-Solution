class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n=words.size();
        vector<vector<int>> adj(26);
        vector<int> present(26,0);
        
        for(string& word : words)
            for(char c : word)
                present[c-'a'] = 1;

        for(int i=0;i<n-1;i++) {
            string first=words[i], second=words[i+1];
            int minLen = min(first.size(), second.size());
            bool found = false;
            for(int j=0;j<minLen;j++) {
                if(first[j]!=second[j]) {
                    adj[first[j]-'a'].push_back(second[j]-'a');
                    found = true;
                    break;
                }
            }
//found used for "abcd", "abc" case when all chars are equal ,can't get a specific order
            if(!found && first.size() > second.size()) 
            return ""; // edge case: invalid order
        }

        vector<int> indegre(26,0);
        for(int u=0; u<26; u++) {
            if(present[u]) {
                for(int v : adj[u])
                    indegre[v]++;
            }
        }

        queue<int> q;
        string topo = "";
        for(int i=0;i<26;i++) {
            if(present[i] && indegre[i]==0)
                q.push(i);
        }

        while(!q.empty()) {
            int node = q.front(); 
            q.pop();
            topo += (char)(node + 'a');
            for(int nei : adj[node]) {
                indegre[nei]--;
                if(indegre[nei]==0)
                    q.push(nei);
            }
        }

        int count=0;
        for(int i=0;i<26;i++) 
        if(present[i]) count++;
        
        if(topo.size() < count) return "";
        return topo;
    }
};