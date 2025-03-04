//
//  main.cpp
//  cpp_operatoroverlaoding
//
//  Created by CodeBreaker on 28/02/25.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix{
    public:
    vector<vector<int>> a;
    Matrix &operator+(Matrix &obj)
    {
        Matrix *m = new Matrix();
        vector<vector<int>> result(a.size(), vector<int>(a[0].size()));
        int r = this->a.size();
        int c = this->a[0].size();
        for(int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
            {
                result[i][j] = this->a[i][j]+obj.a[i][j];
            }
        }
        m->a = result;
        return *m;
    }
    
};
int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }
   return 0;
}

