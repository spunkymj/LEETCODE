class Solution {
public:
    vector<int> nmin(vector<int>& heights){
        stack<int> st;
        st.push(heights.size());
        vector<int> temp(heights.size());
        for(int i=heights.size()-1 ; i>-1 ; i--){
            while( (st.top()!=heights.size() )&&(heights[st.top()]>=heights[i])){
                st.pop();
            }
            temp[i]=st.top();
            st.push(i);
        }
        return temp;
    }
    
    vector<int> pmin(vector<int>& heights){
        stack<int> st;
        st.push(-1);
        vector<int> temp(heights.size());
        for(int i=0 ; i<heights.size() ; i++){
            while((st.top() !=-1) && (heights[st.top()]>=heights[i])){
                st.pop();
            }
            temp[i]=st.top();
            st.push(i);
        }
        return temp;
    }
    
    
    
    int largestRectangleArea(vector<int>& heights) {
        int maxi=0;
        vector<int> n=nmin(heights);
        vector<int> p=pmin(heights);
        for(int i=0 ; i<heights.size() ; i++){
            int area=(n[i]-p[i]-1)*heights[i];
            maxi=max(maxi,area);
        }
        return maxi;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> temp(matrix[0].size(),0);
        int ans=0;
        for(int i=0 ; i < matrix.size(); i++){
            for(int j=0 ; j<matrix[0].size() ; j++){
                if(matrix[i][j]=='1'){
                    temp[j]+=1; 
                }
                else{
                    temp[j]=0;
                }
            }
            int maxarea=largestRectangleArea(temp);
            ans=max(ans,maxarea);
        }
        return ans;
    }
};