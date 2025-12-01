//
//  main.cpp
//  PN_LuckyNumbers
//
//  Created by CodeBreaker on 05/01/25.
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(int A) {
    int ans=0;
    int N = A+1;
    int pFact[N];
    fill_n(pFact, N, 0);
    for(int i=2;i<N;i++)
    {
        if(pFact[i]==0)
        {
            for(int j=2*i;j<N;j+=i)
            {
                pFact[j]+=1;
            }
        }
    }
    for(int j=0;j<N;j++)
    {
        if(pFact[j]==2) ans+=1;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, get lucky numbers!\n";
    cout<<"Count of luckyNumbers : "<<solve(40)<<endl;
    return 0;
}
