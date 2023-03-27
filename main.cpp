#include "functions.h"

int main()
{
    setlocale(LC_ALL, "");

    string str1 = "hhhppphhhppphhhppp";

    int K1 = 11;
    IsKPeriodic(str1, K1);

    int K2 = -1;
    IsKPeriodic(str1, K2);

    string str2 = "fontfontfontfontfont";

    int K3 = 4;
    IsKPeriodic(str2, K3);

    int K4 = 5;
    IsKPeriodic(str2, K4);

    int K5 = 100;
    IsKPeriodic(str2, K5);

    int K6 = 4;
    IsKPeriodic(str2, K6);

    return 0;
}