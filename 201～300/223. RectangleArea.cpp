class Solution {
    int getArea(int A, int B, int C, int D) {
        return (C - A) * (D - B);
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A,E), right = max(min(C,G), left);
        int bottom = max(B,F), top = max(min(D,H), bottom);
        
        return getArea(A, B, C, D) + getArea(E, F, G, H) - getArea(left, bottom, right, top);
    }
};