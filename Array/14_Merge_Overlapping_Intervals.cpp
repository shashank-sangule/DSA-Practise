/*
Merge Overlapping Intervals

Given a set of time intervals in any order,
merge all overlapping intervals into one and output the result
which should have only mutually exclusive intervals.

Example:

Input: Intervals = {{1,3},{2,4},{6,8},{9,10}}
Output: {{1, 4}, {6, 8}, {9, 10}}
Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10],
we have only two overlapping intervals here,[1,3] and [2,4].
Therefore we will merge these two and return [1,4],[6,8], [9,10].

Input: Intervals = {{6,8},{1,9},{2,4},{4,7}}
Output: {{1, 9}}

*/

#include <iostream>
#include <algorithm>

struct Intervals
{
    int start, end;
};

bool comparision(Intervals a, Intervals b)
{
    return (a.start < b.start);
}

int mergeIntervals(Intervals arr[], int size)
{

    std::sort(arr, arr + size, comparision);
    int index = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[index].end > arr[i].start)
        {
            arr[index].end = std::max(arr[index].end, arr[i].end);
        }
        else
        {
            index++;
            arr[index] = arr[i];
        }
    }
    return index;
}

int main()
{

    Intervals arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    int size = sizeof(arr) / sizeof(arr[0]);

    int ansIndex = mergeIntervals(arr, size);

    std::cout << std::endl
              << "Merged array :\n";
    for (int i = 0; i <= ansIndex; i++)
    {
        std::cout << "[" << arr[i].start << ", " << arr[i].end << "] ";
    }

    return 0;
}
