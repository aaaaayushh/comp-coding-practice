/*
Given N jobs where every job is represented by following three elements of it.

    Start Time
    Finish Time
    Profit or Value Associated

Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Algo:
1.sort the jobs by non-decreasing finish times.
2.for each i from 1 to n, determine the max value of the schedule from the subsequence of jobs[0...i].Do this by comparing the inclusion of
job[i] to the schedule to the exclusion of job[i] to the schedule, and then taking the max.
To find the profit with inclusion of job[i]. we need to find the latest job that doesn’t conflict with job[i]. 
The idea is to use Binary Search to find the latest non-conflicting job.

*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
    int start, finish, profit;
};

bool comp(Job s1, Job s2)
{
    return s1.finish < s2.finish;
}

int binSearch(Job jobs[], int index)
{
    int lo = 0, hi = index - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (jobs[mid].finish <= jobs[index].start)
        {
            if (jobs[mid + 1].finish <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }

    return -1;
}

int findProfit(Job arr[], int n)
{
    sort(arr, arr + n, comp);

    int *table = new int[n];
    table[0] = arr[0].profit;

    for (int i = 1; i < n; i++)
    {
        int inclProfit = arr[i].profit;
        int l = binSearch(arr, i);
        if (l != -1)
        {
            inclProfit += table[l];
        }
        table[i] = max(table[i - 1], inclProfit);
    }
    int res = table[n - 1];
    delete[] table;
    return res;
}
int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Optimal profit is " << findProfit(arr, n) << endl;
    return 0;
}