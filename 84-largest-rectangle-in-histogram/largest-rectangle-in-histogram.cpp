class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        std::vector<int> pse(n, -1); 
        std::vector<int> nse(n, n); 
        std::stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }
            st.push(i);
        }

        int max_area = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int current_area = heights[i] * width;
            max_area = std::max(max_area, current_area);
        }

        return max_area;
    }
};
