class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxDiag = 0;
        int area = 0;
        for(int i = 0; i < n; i++){
            int length = dimensions[i][0] ;
            int breadth = dimensions[i][1] ;
            int diag = length*length + breadth*breadth;
            if(diag > maxDiag){
                area = length*breadth;
                maxDiag = diag;
            }else if ( diag == maxDiag){
                area = max(area, length*breadth);
            }
        }
        return area;
    }
};