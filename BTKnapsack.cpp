#include <bits/stdc++.h>
using namespace std;

struct knaps
{
    int n, m;
    int *w, *p, *soln;
    vector<string> s;
    vector<int> fp;
};

void knapsack(struct knaps *k, int i, int tw, int tp)
{
    if (tw + k->w[i] <= k->m || tw == k->m)
    {
        if (i == k->n)
        {
            string str = "";
            for (int j = 0; j < k->n; j++)
                str = str + to_string(k->soln[j]) + " ";

            k->s.push_back(str);
            // cout << str << " " << tp << endl;
            k->fp.push_back(tp);
        }
        else
        {
            k->soln[i] = 1;
            knapsack(k, i + 1, tw + k->w[i], tp + k->p[i]);
            k->soln[i] = 0;
            knapsack(k, i + 1, tw, tp);
        }
    }
}

int main()
{
    struct knaps k;
    int n, m;
    cout << "Enter number of items: ";
    cin >> n;
    int *w = new int[n];
    int *p = new int[n];
    int *soln = new int[n];
    cout << "Enter weights and profirs in ascending order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        cin >> p[i];
        soln[i] = 0;
    }
    k.n = n;
    k.w = w;
    k.p = p;
    k.soln = soln;
    cout << "Enter max weight: ";
    cin >> m;
    k.m = m;
    knapsack(&k, 0, 0, 0);
    int i = distance(k.fp.begin(), max_element(k.fp.begin(), k.fp.end()));
    cout << k.s.at(i);
    cout << k.fp.at(i);
    return 0;
}