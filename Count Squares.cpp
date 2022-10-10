class DetectSquares {
    //intuition 
    //https://leetcode.com/problems/detect-squares/discuss/1472289/Intuition-Explained-with-Diagram-oror-Coordinate-Geometry-oror-C%2B%2B
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        x_axis[x][y]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int res = 0;
        // For all points lying on x_axis with value x_coordinate = x
         for (auto& it : x_axis[x]) {   
            int y_coord = it.first;
            if (y == y_coord) continue;
             
            int sideLength = abs(y_coord - y);
             // counting for p3' and p4' , square points on the right 
            if (x + sideLength <= 1000)    // x_coordinate should be within range [0, 1000]
            {
                int newX = x + sideLength;
                res += x_axis[x][y_coord] * x_axis[newX][y_coord] * x_axis[newX][y];
            }
             // counting for p3'' and p4'', square points on the left
            if (x - sideLength >= 0)       // x_coordinate should be within range [0, 1000]
            {
                int newX = x - sideLength;
                res += x_axis[x][y_coord] * x_axis[newX][y_coord] * x_axis[newX][y];
            }
             
         }
        return res;
    }
    private:
    unordered_map<int,unordered_map<int , int>> x_axis;
};
