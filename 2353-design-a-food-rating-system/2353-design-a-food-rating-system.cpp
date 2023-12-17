class FoodRatings {
public:
    map<string,set<pair<int,string>>> c;
    map<string,pair<string,int>> f; 
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0 ; i<foods.size() ; i++){
            f[foods[i]]={cuisines[i],ratings[i]};
            c[cuisines[i]].insert({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cui=f[food].first;
        int r=f[food].second;
        c[cui].erase({r,food});
        c[cui].insert({newRating,food});
        f[food].second=newRating;
    }
    
    string highestRated(string cuisine) {
        int hr=(*(--c[cuisine].end())).first;
        string ans=(*(c[cuisine].lower_bound({hr,""}))).second;
        return ans;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */