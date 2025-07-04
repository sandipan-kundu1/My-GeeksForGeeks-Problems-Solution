class Solution {
  public:
    bool row(int i, vector<vector<int>>& mat) {
        vector<int> vis(10, 0);
        for(int col = 0; col < 9; col++) {
            if(mat[i][col] != 0) {
                if(vis[mat[i][col]]) return false;
                vis[mat[i][col]] = 1;
            }
        }
        return true;
    }

    bool col(int j, vector<vector<int>>& mat) {
        vector<int> vis(10, 0);
        for(int row = 0; row < 9; row++) {
            if(mat[row][j] != 0) {
                if(vis[mat[row][j]]) return false;
                vis[mat[row][j]] = 1;
            }
        }
        return true;
    }

    bool subbox(int i, int j, vector<vector<int>>& mat) {
        vector<int> vis(10, 0);
        for(int row = i; row < i + 3; row++) {
            for(int col = j; col < j + 3; col++) {
                if(mat[row][col] != 0) {
                    if(vis[mat[row][col]]) return false;
                    vis[mat[row][col]] = 1;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<int>>& mat) {
        for(int i = 0; i < 9; i++) {
            if(!row(i, mat)) return false;
        }

        for(int j = 0; j < 9; j++) {
            if(!col(j, mat)) return false;
        }

        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                if(!subbox(i, j, mat)) return false;
            }
        }

        return true;
    }
};
