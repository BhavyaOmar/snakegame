#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int num)
{
    if (num <= 1)
        return 0; // Not prime
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return 0; // Divisible by a number other than 1 and itself
    }
    return 1; // Prime
}

// Function to check if a number is an Armstrong number
int isArmstrong(int num)
{
    int originalNum = num, sum = 0, digits = 0;

    // Count the number of digits
    while (originalNum != 0)
    {
        digits++;
        originalNum /= 10;
    }

    originalNum = num;

    // Calculate the sum of each digit raised to the power of 'digits'
    while (originalNum != 0)
    {
        int digit = originalNum % 10;
        sum += pow(digit, digits);
        originalNum /= 10;
    }

    return sum == num; // Armstrong if the sum matches the original number
}

int main()
{
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Prime Armstrong numbers between 1 and %d are:\n", n);

    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i) && isArmstrong(i))
        {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
