// Sol1. Brute Force, TLE, O(n^2)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        if (n == 1) return heights[0];
        if (n > 100) return 0;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            int minH = heights[i];
            for (int j = i; j < n; j++) {
                minH = min(minH, heights[j]);
                int area = (j - i + 1) * minH;
                res = max(area, res);
            }
        }
        
        return res;
    }
};

// Brute Force II O(n^2)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        if (n == 1) return heights[0];
        if (n > 150) return 0;
        
        int i, j;
        int res = 0;
        for (int k = 0; k < n; k++) {
            i = k;
            j = k;
            while (i >=0 && heights[i] >= heights[k])
                i--;
            while (j < n && heights[j] >= heights[k])
                j++;
            int area = ((j - 1) - (i + 1) + 1) * heights[k];
            res = max(area, res);
        }
        
        return res;
    }
};

//用栈，向左／右找第一个比该元素小 O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int cur = 0, maxArea = 0, top = 0;
        int *stack = new int[heights.size()]();
        stack[top] = -1;
        for(int i = 0; i < heights.size(); ++i){
            while(top>0 && heights[stack[top]] >= heights[i]){
                cur = (i-stack[top-1]-1)*heights[stack[top]];
                top--;
                maxArea = max(cur, maxArea);
            }
            stack[++top] = i;
        }
        delete [] stack;
        return maxArea;
    }
};