//
//  main.cpp
//  arrays_mergeIntervals
//
//  Created by CodeBreaker on 30/12/24.
//
/*
 Merge Intervals
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You have a set of non-overlapping intervals. You are given a new interval [start, end], insert this new interval into the set of intervals (merge if necessary).
 You may assume that the intervals were initially sorted according to their start times.


 Problem Constraints
 0 <= |intervals| <= 105


 Input Format
 First argument is the vector of intervals
 second argument is the new interval to be merged


 Output Format
 Return the vector of intervals after merging


 Example Input
 Input 1:
 Given intervals [1, 3], [6, 9] insert and merge [2, 5] .
 Input 2:
 Given intervals [1, 3], [6, 9] insert and merge [2, 6] .


 Example Output
 Output 1:
  [ [1, 5], [6, 9] ]
 Output 2:
  [ [1, 9] ]


 Example Explanation
 Explanation 1:
 (2,5) does not completely merge the given intervals
 Explanation 2:
 (2,6) completely merges the given intervals


 Expected Output
 Enter your input as per the following guideline:
 There are 3 lines in the input

 Line 1 ( Corresponds to arg 1 ) : An array of intervals. First number represents the number of intervals to follow. Then for every interval we get a pair of integers.
     For example, Intervals: [(1, 3), (6, 9)] will be written as "2 1 3 6 9"(without quotes).

 Line 2 & Line 3 ( Corresponds to arg 2 ) : New Interval represented by a pair of integers.
     For example, Interval: (2, 5) will be written as "2 5"(without quotes)

 */
#include <iostream>
#include<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval ():start(0), end(0){}
    Interval(int s, int e): start(s), end(e) {}
    
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
//    vector<Interval> ans(0);
    size_t N = intervals.size();
//    int s = newInterval.start, e = newInterval.end;
//    for(int i=0;i<N;i++)
//    {
//        if(intervals[i].end < s)
//        {
//            ans.push_back(intervals[i]);
//        } else if(e < intervals[i].start) {
//            ans.push_back(newInterval);
//            for(int j=i;j<N;j++)
//            {
//                ans.push_back(intervals[j]);
//            }
//            return ans;
//        } else {
//            s = min(s, intervals[i].start);
//            e = max(e, intervals[i].end);
//        }
//    }
//    ans.push_back(Interval(s,e));
//    return ans;
    vector<Interval> ans;
    int i = 0;

    // Add intervals that come before newInterval
    while(i < N && intervals[i].end < newInterval.start) {
        ans.push_back(intervals[i++]);
    }

    // Merge overlapping intervals
    while(i < N && intervals[i].start <= newInterval.end) {
        newInterval.start = min(newInterval.start, intervals[i].start);
        newInterval.end = max(newInterval.end, intervals[i].end);
        i++;
    }

    // Add merged interval and remaining intervals
    ans.push_back(newInterval);
    while(i < N) {
        ans.push_back(intervals[i++]);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Arrays merge inetervals!\n";
    //[1, 3], [6, 9] insert and merge [2, 5]
    vector<Interval> A;
    vector<vector<int>> v{{1,2},{8,10}};
    for(int i=0;i<v.size();i++)
    {
        Interval In;
        In.start=v[i][0];
        In.end=v[i][1];
        A.push_back(In);
    }
    Interval nwInt;
    nwInt.start=3;nwInt.end=6;
    vector<Interval> rtV = insert(A,nwInt);
    for(int i=0;i<rtV.size();i++)
    {
        cout<<rtV[i].start<<"-"<<rtV[i].end<<endl;
    }
    
    return 0;
}
