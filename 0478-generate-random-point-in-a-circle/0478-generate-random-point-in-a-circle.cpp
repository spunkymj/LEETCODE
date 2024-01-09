class Solution {
    double R, X, Y;
public:
    Solution(double radius, double x_center, double y_center) : R(radius), X(x_center), Y(y_center) {
        srand(time(0));
    }
    double random(){
        return (double)rand() / RAND_MAX; // for generating random points between 0 to 1
    }
    vector<double> randPoint() {
        double len = sqrt(random())*R;
        double deg = 2 * M_PI * random();
        double x = X + len * cos(deg);
        double y = Y + len * sin(deg);
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */