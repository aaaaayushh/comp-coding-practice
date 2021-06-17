
#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct Point
{
    int x, y;
};

int compareX(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}
int compareY(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float brute(Point p[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (dist(p[i], p[j]) < min)
                min = dist(p[i], p[j]);
    return min;
}

float min(float x, float y)
{
    return (x < y) ? x : y;
}
// A utility function to find the distance between the closest points of
// strip of a given size. All points in strip[] are sorted according to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
float stripClosest(Point strip[], int size, float d)
{
    float min = d;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; j++)
        {
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);
        }
    }
    return min;
}
// A recursive function to find the smallest distance. The array Px contains
// all points sorted according to x coordinates and Py contains all points
// sorted according to y coordinates
float closestUtil(Point Px[], Point Py[], int n)
{
    if (n <= 3)
        return brute(Px, n);

    int mid = n / 2;
    Point midPoint = Px[mid];
    // Divide points in y sorted array around the vertical line.
    // Assumption: All x coordinates are distinct.
    Point Pyl[mid];     //y sorted points on left of verical line
    Point Pyr[n - mid]; //y sorted points on right of vertical line
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++)
    {
        if (Py[i].x <= midPoint.x && li < mid)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }
    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    float dl = closestUtil(Px, Pyl, mid);
    float dr = closestUtil(Px + mid, Pyr, n - mid);

    float d = min(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j++] = Py[i];

    return stripClosest(strip, j, d);
}

float closest(Point p[], int n)
{
    Point px[n];
    Point py[n];
    for (int i = 0; i < n; i++)
    {
        px[i] = p[i];
        py[i] = p[i];
    }
    qsort(px, n, sizeof(Point), compareX);
    qsort(py, n, sizeof(Point), compareY);

    return closestUtil(px, py, n);
}

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << closest(P, n);
    return 0;
}