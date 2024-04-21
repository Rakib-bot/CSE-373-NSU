
#include <bits/stdc++.h>
using namespace std;
int algo1(int n)
{
    int q = 0;
    for (int i = 1; i < n; i++)
    {

        int p = 0;
        for (int j = n - 1; j >= 1; j /= 2)
        {
            p++;
        }
        for (int k = 1; k < p; k *= 2)
        {
            q++;
        }
    }
    return q;
}
void algo2(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j += i)
        {
            cout << i << " " << j << endl;
        }
    }
}
int algo3(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i *= 2)
    {
        for (int j = 1; i <= n; j++)
            sum++;
    }
    return sum;
}
int algo4(int N)
{
    int a = 0, i = N;
    while (i > 0)
    {
        a += i;
        i /= 2;
    }
    return a;
}
void algo5(int n)
{
    int k = rand();
    for (int i = 0; i < n; i++)
        i *= k;
}
void algo6(int n)
{

    int value = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            value += 1;
}
int algo7(int n)
{
    int q = 0, p = 0;
    for (int i = 1; i < n; i++)
    {
        p++;
        for (int j = n - 1; j >= 1; j /= 2)
        {
            for (int k = 1; k < p; k *= 2)
            {
                q++;
            }
        }
    }
    return q;
}
void algo8(int n)
{
    if (n == 1)
        return;
    for (int i = 1; i <= n; i++)
    {
        // Inner loop executes only one
        // time due to break statement.
        for (int j = 1; j <= n; j++)
        {
            printf("*");
            break;
        }
    }
}
void algo9(int n)
{
    int count = 0;
    for (int i = n / 2; i <= n; i++)
        for (int j = 1; j <= n; j = 2 * j)
            for (int k = 1; k <= n; k = k * 2)
                count++;
}
void algo10(int n)
{
    int count = 0;

    // outer loop executes n/2 times
    for (int i = n / 2; i <= n; i++)

        // middle loop executes  n/2 times
        for (int j = 1; j + n / 2 <= n; j = j++)

            // inner loop executes logn times
            for (int k = 1; k <= n; k = k * 2)
                count++;
}
void algo11(int n)
{
    int i = 1, s = 1;
    while (s <= n)
    {
        i++;
        s += i;
        printf("*");
    }
}
/*

Algorithm A and B have a worst-case running time of O(n) and O(logn), respectively. Therefore, algorithm B always runs faster than algorithm A?


ans:
No, it is not always true. It depends on the value of n. For small values of n, algorithm A may run faster than algorithm B. For large values of n, algorithm B will run faster than algorithm A.

It's not accurate to conclude that Algorithm B always runs faster than Algorithm A solely based on their worst-case running times being \( O(\log n) \) and \( O(n) \) respectively.

The worst-case time complexity gives an upper bound on the running time of an algorithm, but it doesn't necessarily guarantee the actual performance of the algorithm in all cases. Here are some points to consider:

1. **Average and Best Case Performance**: While Algorithm B has a worst-case time complexity of \( O(\log n) \), its average and best-case performance might be different. Similarly, while Algorithm A has a worst-case time complexity of \( O(n) \), it might perform better in average or best-case scenarios.

2. **Input Size**: The performance of an algorithm can vary based on the size and nature of the input. For small input sizes, Algorithm A might still outperform Algorithm B despite having a higher worst-case time complexity.

3. **Constant Factors**: The big O notation doesn't consider constant factors or lower-order terms. Even if Algorithm A has a higher worst-case time complexity, it might have a smaller constant factor hidden within the \( O(n) \) notation compared to Algorithm B's \( O(\log n) \).

4. **Nature of the Problem**: Different algorithms might be better suited for different types of problems. For some problems, the overhead of Algorithm B's logarithmic time complexity might outweigh its benefits compared to the linear time complexity of Algorithm A.

Therefore, without considering other factors such as constant factors, average or best-case performance, and the nature of the problem being solved, it's not accurate to conclude that Algorithm B always runs faster than Algorithm A based solely on their worst-case time complexities.

*/