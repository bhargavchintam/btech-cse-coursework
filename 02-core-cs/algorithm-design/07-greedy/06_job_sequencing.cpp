// job sequencing with deadlines to maximise profit
#include<iostream>
#include<algorithm>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

int main()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[100];
    cout << "enter id, deadline and profit of each job:\n";
    for(int i = 0; i < n; i++)
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;

    sort(jobs, jobs + n, cmp);

    int maxd = 0;
    for(int i = 0; i < n; i++)
        if(jobs[i].deadline > maxd)
            maxd = jobs[i].deadline;

    char slot[100];
    for(int i = 1; i <= maxd; i++)
        slot[i] = '-';

    int profit = 0;
    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline; j >= 1; j--)
            if(slot[j] == '-') {
                slot[j] = jobs[i].id;
                profit += jobs[i].profit;
                break;
            }
    }

    cout << "schedule: ";
    for(int i = 1; i <= maxd; i++)
        cout << slot[i] << " ";
    cout << "\ntotal profit = " << profit << endl;
    return 0;
}
