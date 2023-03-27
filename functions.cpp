#include"functions.h"


void badCharHeuristic(const string& str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void IsKPeriodic(const string& str, int K)
{
    if (K <= 0)
    {
        cout << "K must be greater than 0" << '\n';
        return;
    }

    int l = 0;
    int counter = 0;
    int n = str.size();

    if (K >= n)
    {
        cout << "K is greater than or equal to the lenght of string" << '\n';
        return;
    }

    if (n % K)
    {
        cout << "A string of lenght " << n << " can't be multiple of " << K << '\n';
        return;
    }

    string substr;
    substr.assign(str, 0, K);
    int m = substr.size();
    int badchar[NO_OF_CHARS];

    badCharHeuristic(substr, m, badchar);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && substr[j] == str[s + j])
            j--;

        if (j < 0)
        {
            counter++;
            if (s != 0 && s - l == K)
                l = s;
            if (!s)
                l = s;
            s += (s + m < n) ? m - badchar[str[s + m]] : 1;
        }
        else
        {
            int bc = badchar[str[s + j]];
            s += max(1, j - bc);
        }
    }
    if (counter && str.size() - l == K)
        cout << "string " << str << " multiple of " << K << '\n';
    else
    {
        if (counter)
            cout << "string " << str << " not multiple of " << K << '\n';
    }
}