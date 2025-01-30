class Solution {
private: 
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        int startColor = image[sr][sc];
        
        if(image[sr][sc] == color) return image;
       
        q.push({sr,sc});

        image[sr][sc] = color;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int newr = row + drow[i];
                int newc = col + dcol[i];

                if(newr >= 0 && newc >= 0 && newr < n && newc < m){
                    if(image[newr][newc] == startColor){
                        image[newr][newc] = color;
                        q.push({newr,newc});
                    }
                }
            }
        }
        return image;

    }
};