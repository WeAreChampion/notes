#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 110010 * 2;
char szIn[MAX];
char szOut[MAX];
int nRad[MAX];

int Proc(char* pszIn, char* pszOut)
{
    int nLen = 1;
   
    *pszOut++ = '$';
    while (*pszIn)
    {
        *pszOut++ = '#';
        nLen++;
        *pszOut++ = *pszIn++;
        nLen++;
    }
    *pszOut++ = '#';
    *pszOut = '\0';
   
    return nLen + 1;
}

void Manacher(int* pnRad, char* pszStr, int nN)
{
    int nId = 0, nMax = 0;
   
    //pnRad[0] = 1;
    for (int i = 0; i < nN; ++i)
    {
        if (nMax > i)
        {
            pnRad[i] = min(pnRad[2 * nId - i], nMax - i);
        }
        else pnRad[i] = 1;
       
        while (pszStr[i + pnRad[i]] == pszStr[i - pnRad[i]])
        {
            ++pnRad[i];
        }
        if (pnRad[i] + i > nMax)
        {
            nMax = pnRad[i] + i;
            nId = i;
        }
    }
}

int main()
{
    while (scanf("%s", szIn) == 1)
    {
        int nLen = Proc(szIn, szOut);
        Manacher(nRad, szOut, nLen);
        int nAns = 1;
        for (int i = 0; i < nLen; ++i)
        {
            nAns = max(nRad[i], nAns);
        }
        printf("%d\n", nAns - 1);
    }
   
    return 0;
}