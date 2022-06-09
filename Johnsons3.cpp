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

    int m1[jobs], m2[jobs], m3[jobs];
    int finalM1[jobs], finalM2[jobs];

    printf("Enter jobs for Machine 1: ");
    for (int i = 0; i < jobs; i++)
    {
        scanf("%d", &m1[i]);
    }

    printf("Enter jobs for Machine 2: ");
    for (int i = 0; i < jobs; i++)
    {
        scanf("%d", &m2[i]);
    }

    printf("Enter jobs for Machine 3: ");
    for (int i = 0; i < jobs; i++)
    {
        scanf("%d", &m3[i]);
    }

    for (int i = 0; i < jobs; i++)
    {
        finalM1[i] = m1[i] + m2[i];
        finalM2[i] = m2[i] + m3[i];
    }

    rear = jobs;
    int i, j, minI1, minI2, machine, minM1, minM2;
    for (int k = 0; k < jobs; k++)
    {
        minM1 = minM2 = 99999;
        for (i = 0; i < jobs; i++)
        {
            if (minM1 > finalM1[i])
            {
                minM1 = finalM1[i];
                minI1 = i;
            }
        }
        for (i = 0; i < jobs; i++)
        {
            if (minM2 > finalM2[i])
            {
                minM2 = finalM2[i];
                minI2 = i;
            }
        }

        if (minM1 < minM2)
        {
            pushFront(minI1);
            finalM1[minI1] = finalM2[minI1] = 99999;
        }
        else
        {
            pushRear(minI2);
            finalM1[minI2] = finalM2[minI2] = 99999;
        }
    }
    printf("Solution: ");
    for (int i = 0; i < jobs; i++)
    {
        printf("Job%d \t", queueAns[i] + 1);
    }

    int timeM1 = 0;
    int timeM2 = m1[queueAns[0]];
    int ansM1[jobs][2], ansM2[jobs][2], ansM3[jobs][2];

    for (int i = 0; i < jobs; i++)
    {
        ansM1[queueAns[i]][0] = timeM1;
        timeM1 += m1[queueAns[i]];
        ansM1[queueAns[i]][1] = timeM1;
    }
    for (int i = 0; i < jobs; i++)
    {
        ansM2[queueAns[i]][0] = timeM2;
        timeM2 += m2[queueAns[i]];
        ansM2[queueAns[i]][1] = timeM2;
    }
    int timeM3 = ansM2[0][1];
    for (int i = 0; i < jobs; i++)
    {
        ansM3[queueAns[i]][0] = timeM3;
        timeM3 += m3[queueAns[i]];
        ansM3[queueAns[i]][1] = timeM3;
    }

    printf("\n\nMachine M1:");
    for (int i = 0; i < jobs; i++)
    {
        printf("\nJob %d: %d-%d", i + 1, ansM1[i][0], ansM1[i][1]);
    }

    printf("\n\nMachine M2:");
    for (int i = 0; i < jobs; i++)
    {
        printf("\nJob %d: %d-%d", i + 1, ansM2[i][0], ansM2[i][1]);
    }

    printf("\n\nMachine M3:");
    for (int i = 0; i < jobs; i++)
    {
        printf("\nJob %d: %d-%d", i + 1, ansM3[i][0], ansM3[i][1]);
    }

    return 0;
}