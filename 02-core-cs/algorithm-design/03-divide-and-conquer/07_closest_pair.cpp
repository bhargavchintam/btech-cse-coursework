// closest pair of points in a plane by divide and conquer
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

struct Point {
    double x, y;
};

bool byX(const Point &a, const Point &b)
{
    return a.x < b.x;
}

bool byY(const Point &a, const Point &b)
{
    return a.y < b.y;
}

double dist(const Point &a, const Point &b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double closest(vector<Point> &px, int lo, int hi)
{
    if (hi - lo <= 2) {                    // 3 or fewer points, just check every pair
        double best = 1e18;
        for (int i = lo; i <= hi; i++)
            for (int j = i + 1; j <= hi; j++)
                best = min(best, dist(px[i], px[j]));
        return best;
    }

    int mid = (lo + hi) / 2;
    double midX = px[mid].x;
    double dl = closest(px, lo, mid);
    double dr = closest(px, mid + 1, hi);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = lo; i <= hi; i++)
        if (fabs(px[i].x - midX) < d)
            strip.push_back(px[i]);

    sort(strip.begin(), strip.end(), byY);
    for (int i = 0; i < (int)strip.size(); i++)
        for (int j = i + 1; j < (int)strip.size() && strip[j].y - strip[i].y < d; j++)
            d = min(d, dist(strip[i], strip[j]));
    return d;
}

int main()
{
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    vector<Point> p(n);
    cout << "Enter " << n << " points as x y:\n";
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;

    sort(p.begin(), p.end(), byX);
    double d = closest(p, 0, n - 1);
    cout << "Closest pair distance = " << d << endl;
    return 0;
}
