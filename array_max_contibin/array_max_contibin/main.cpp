//
//  main.cpp
//  array_max_contibin
//
//  Created by CodeBreaker on 19/08/1946 Saka.
//

#include <iostream>
#include<vector>
using namespace std;

int solve(string A) {
    int ans=0;
    size_t N = A.length();
    vector<int> PFS(N,0), SFS(N,0);
    int i=0,j=N-1,psm=0, ssm=0, T=0;
    while(i<N&&j>=0)
    {
        if(A[i]=='1') {
            psm+=1;
            T+=1;
        } else {
            psm=0;
        }
        PFS[i]=psm;
      
        if(A[j]=='1') {
            ssm+=1;
        } else {
            ssm=0;
        }
        SFS[j]=ssm;
        i++;j--;
    }
    cout<<"Totoal ones : "<< T<<endl;
   if(T==0) return 0;
    if(T==N) return T;
    int L=0,R=0;
    for(int i=0;i<N;i++)
    {
        
        if(A[i]=='0')
        {
            if(i==0)
            {
                L=0;
            } else {
                L=PFS[i-1];
            }
            if(i==L-1)
            {
                R=0;
            } else {
                R=SFS[i+1];
            }
            if(R+L==T)
            {
                if(R==0 || L==0)
                 {
                     return (L>R)?L:R;
                 }
                else {
                    return R+L;
                }
            } else {
                ans=max(ans,(L+R+1));
            }
        }
    }
//    cout<<"PFS : ";
//    for(int i=0;i<L;i++)
//    {
//        cout<<PFS[i]<<" ";
//    }
//    cout<<"\nSFS : ";
//    for(int i=0;i<L;i++)
//    {
//        cout<<SFS[i]<<" ";
//    }
//    cout<<endl;
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Continuos maximum binary array!\n";
    cout<<"-------------------\n";
    string A="0111110110";
    cout<<"Max continous ones : "<<solve(A)<<endl;
    
    return 0;
}
