#include <iostream>
using namespace std;

// class Solution {
// public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        if (n == 0) return true;
        if (n == 1)
            if (num == "1" || num =="8" || num == "0") return true;
        
        if (num[0] == '0' || num[0] == '8' || num[0] == '1')
            {if (num[0] != num[n-1]) return false;
             else isStrobogrammatic(num.substr(1,n-2));}
            //  {
            //     //  string tmp = num.substr(1, n-2);
            //     //  cout <<tmp<< endl;
            //      isStrobogrammatic(tmp);
            //  }
            // cout << (num.substr(1,n-2).size()==0) <<endl;

        if (num[0] == '6')
        {
            if (num[n-1] != '9') return false;
            else isStrobogrammatic(num.substr(1, n-2));
        }

        if (num[0] == '9')
          {  if (num[n-1] != '6') return false;
            else isStrobogrammatic(num.substr(1, n-2));}
            
       // return false;
}

int main()
{
    string a;
    while (cin >>a)
    {
        cout << "a:" << a; 
        if (isStrobogrammatic(a))
            cout << " true" <<endl;
        else
            cout <<" false" <<endl;
    }

}