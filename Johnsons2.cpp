#include <stdio.h>

int queueAns[100];
int front = 0;
int rear;
void pushFront(int i)
{
    queueAns[front] = i;
    front++;
}

void pushRear(int i)
{
    rear--;
    queueAns[rear] = i;
}

int main()
{
    int jobs;
    printf("Enter total jobs: ");
    scanf("%d", &jobs);

    int m1[jobs], m2[jobs], tempM1[jobs], tempM2[jobs];

    printf("Enter jobs for Machine 1: ");
    for (int i = 0; i < jobs; i++)
    {
        scanf("%d", &m1[i]);
        tempM1[i] = m1[i];
    }

    printf("Enter jobs for Machine 2: ");
    for (int i = 0; i < jobs; i++)
    {
        scanf("%d", &m2[i]);
        tempM2[i] = m2[i];
    }

    rear = jobs;
    int i, j, minI1, minI2, machine, minM1, minM2;
    for (int k = 0; k < jobs; k++)
    {
        minM1 = minM2 = 99999;
        for (i = 0; i < jobs; i++)
        {
            if (minM1 > m1[i])
            {
                minM1 = m1[i];
                minI1 = i;
            }
        }
        for (i = 0; i < jobs; i++)
        {
            if (minM2 > m2[i])
            {
                minM2 = m2[i];
                minI2 = i;
            }
        }

        if (minM1 < minM2)
        {
            pushFront(minI1);
            m1[minI1] = m2[minI1] = 99999;
        }
        else
        {
            pushRear(minI2);
            m1[minI2] = m2[minI2] = 99999;
        }
    }
    printf("Solution: ");
    for (int i = 0; i < jobs; i++)
    {
        printf("Job%d \t", queueAns[i] + 1);
    }

    int timeM1 = 0;
    int timeM2 = tempM1[queueAns[0]];
    int ansM1[jobs][2], ansM2[jobs][2];

    for (int i = 0; i < jobs; i++)
    {
        ansM1[queueAns[i]][0] = timeM1;
        timeM1 += tempM1[queueAns[i]];
        ansM1[queueAns[i]][1] = timeM1;
    }
    for (int i = 0; i < jobs; i++)
    {
        ansM2[queueAns[i]][0] = timeM2;
        timeM2 += tempM2[queueAns[i]];
        ansM2[queueAns[i]][1] = timeM2;
    }

    printf("\nMachine M1:");
    for (int i = 0; i < jobs; i++)
    {
        printf("\nJob %d: %d-%d", i + 1, ansM1[i][0], ansM1[i][1]);
    }

    printf("\nMachine M2:");
    for (int i = 0; i < jobs; i++)
    {
        printf("\nJob %d: %d-%d", i + 1, ansM2[i][0], ansM2[i][1]);
    }

    return 0;
}