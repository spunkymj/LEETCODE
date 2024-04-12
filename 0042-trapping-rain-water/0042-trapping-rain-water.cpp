class Solution {
public:
    int trap(vector<int>& height) {
    if (height.size()<3){
        return 0;
    }
    int hightest=max_element(height.begin(),height.end())-height.begin();
    int rain=0;
    int m=-1;
    
    for(int i=0 ; i<hightest ; i++){
        m=max(m,height[i]);
        rain+=m-height[i];
    }
    m=-1;
        
    for(int j=height.size()-1 ; j > hightest ; j--){
        m=max(m,height[j]);
        rain+=m-height[j];
    }
    return rain;
    }
};