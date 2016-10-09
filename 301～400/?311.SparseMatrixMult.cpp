class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        if (A.empty() || B.empty()) return res;
        
        int r1 = A.size(), c1 = A[0].size(), c2 = B[0].size();
        //A is [r1 * c1], B is [c1 * c2]
        //res is [r1 * c2]

        res.resize(r1, vector<int>(c2, 0));
        for (int i = 0; i < r1; i++) {
            for (int k = 0; k < c1; k++) {
                if (A[i][k] != 0) {
                    for (int j = 0; j < c2; j++) {
                        if (B[k][j] != 0)
                            res[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        return res;
    }
};

//////////
int am = A.size();//2
 int bm = B.size();//3
 //if(!am || !bm)
 //    return result;
 int an = A[0].size();//3
 int bn = B[0].size();//3 2*3 3*3 => 2*3
 vector<vector<int>> result(am,vector<int>(bn,0));
 vector<vector<int>> A_non_zero(am);
 vector<vector<int>> B_non_zero(bn);
 //an == bm
 for(int i=0;i<am;i++)
     for(int j=0;j<an;j++)
         if(A[i][j])A_non_zero[i].push_back(j);
         
 for(int j=0;j<bn;j++)
     for(int i=0;i<bm;i++)
         if(B[i][j])B_non_zero[j].push_back(i);
 
 for(int i=0;i<am;i++)
     for(int j=0;j<bn;j++){
         int m=0,n=0;
         while(m<A_non_zero[i].size() && n<B_non_zero[j].size()){
             int idx_A = A_non_zero[i][m];
             int idx_B = B_non_zero[j][n];
             if(idx_A == idx_B){
                 result[i][j]+= (A[i][idx_A]*B[idx_B][j]);
                 m++;
                 n++;
             }
             else if(idx_A > idx_B)
                 n++;
             else 
                 m++;
         }
     }
 return result;