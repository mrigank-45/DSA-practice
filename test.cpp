#include <iostream>
#include <unordered_map>

using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

int countTripletsWithEvenSetBits(int A[], int sizeA, int B[], int sizeB, int C[], int sizeC)
{
    unordered_map<int, int> xorCount;

    for (int i = 0; i < sizeA; ++i)
    {
        for (int j = 0; j < sizeB; ++j)
        {
            int xorResult = A[i] ^ B[j];
            xorCount[xorResult]++;
        }
    }

    int count = 0;

    for (int k = 0; k < sizeC; ++k)
    {
        for (const auto &pair : xorCount)
        {
            int finalXor = pair.first ^ C[k];
            if (__builtin_popcount(finalXor) % 2 == 0)
            {
                count += pair.second;
            }
        }
    }

    return count;
}

int main()
{
    int A[] = {1, 2};
    int sizeA = sizeof(A) / sizeof(A[0]);

    int B[] = {2};
    int sizeB = sizeof(B) / sizeof(B[0]);

    int C[] = {2, 3};
    int sizeC = sizeof(C) / sizeof(C[0]);

    int result = countTripletsWithEvenSetBits(A, sizeA, B, sizeB, C, sizeC);
    cout << "Number of triplets with an even number of set bits: " << result << endl;


    return 0;
}
