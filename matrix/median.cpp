//program to find the median in a row wise sorted matrix
//binary search method

//for a number to be median there should be exactly n/2 numbers which are less than this number. Find the count of numbers less than all the
//numbers.
// algo:
/*
1.find the min and max element in the matrix. 
2.use binary search on range of numbers from min to max, find the mid of the min and max and get a count of number less than mid. accordingly change
the min and max.
3.for a number to be median there should be (r*c)/2 numbers smaller than that number. So, for every number, get the count of numbers less than
that by using upper_bound() in each row of the matrix, if it is less than the required count, the median must be greater than the selected 
number, else the median must be less than or equal to selected number.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int binaryMedian(int m[][MAX], int r, int c)
{
    int min = INT_MAX, max = INT_MIN;
    //find min and max in matrix
    for (int i = 0; i < r; i++)
    {
        min = min < m[i][0] ? min : m[i][0];
        max = max > m[i][c - 1] ? max : m[i][c - 1];
    }
    //binary search
    //upper_bound() returns an iterator pointing to the first element in the range [first,last) that is greater than value, or last if no such 
    //element exists. The elements in the range should be sorted.
    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
        //find count of elements smaller than mid
        for (int i = 0; i < r; i++)
        {
            place += upper_bound(m[i], m[i] + c, mid) - m[i];
        }
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}
int main()
{
    int r = 3, c = 3;
    int m[][MAX] = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << "Median is " << binaryMedian(m, r, c) << endl;
    return 0;
}