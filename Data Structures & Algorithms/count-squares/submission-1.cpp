class CountSquares {
private:
    map<pair<int, int>, int> points;

public:
    CountSquares() {
        points = {};
    }
    
    void add(vector<int> point) {
        points[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int c = 0;
        int px = point[0];
        int py = point[1];

        for(auto const& [coord, count] : points){
            int x = coord.first;
            int y = coord.second;
            if(abs(px - x) == abs(py - y) && px != x){
                if(points.count({x, py}) && points.count({px, y})){
                    c += count * points[{x, py}] * points[{px, y}];
                }
            }
        }

        return c;
    }
};
