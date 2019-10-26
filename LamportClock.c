#include<stdio.h>

int main() {
    int p1[10], p2[10], p3[10];

    int e, i, m1, m2, m3, m4, d;

    printf("Enter the no. of events in p1, p2 and p3: ");
    scanf("%d", &e);

    printf("Enter the event of p1 which will send message to p2: ");
    scanf("%d", &m1);

    printf("Enter the event of p2 which will receive the message from p1: ");
    scanf("%d", &m2);

    printf("Enter the event of p2 which will send the message to p3: ");
    scanf("%d", &m3);

    printf("Enter the event of p3 which will receive the message from p2: ");
    scanf("%d", &m4);

    p1[0]=4;
    p2[0]=4;
    p3[0]=4;
    d=3;

    for (i = 1; i <= e; i++) {
        if (i != m2 && i != m4) {
            p1[i] = p1[i-1] + 1;
            p2[i] = p2[i-1] + 1;
            p3[i] = p3[i-1] + 1;
        } else {
            if (i == m2) {
                if (p1[m1] > p2[i-1]) {
                    p2[i] = p1[m1] + d;
                } else {
                    p2[i] = p2[i-1] + d;
                }
                p1[i] = p1[i-1] + 1;
                p3[i] = p3[i-1] + 1;
            }
            if (i == m4) {
                if (p2[m3] > p3[i-1]) {
                    p3[i] = p2[m3] + d;
                } else {
                    p3[i] = p3[i-1] + d;
                }
                p1[i] = p1[i-1] + 1;
                p2[i] = p2[i-1] + 1;
            }
        }
    }

    printf("\n\nTime stamp for \tP1 ---> ");
    for (i = 1; i <= e; i++) {
        printf("%d ", p1[i]);
    }

    printf("\nTime stamp for \tP2 ---> ");
    for (i = 1; i <= e; i++) {
        printf("%d ", p2[i]);
    }

    printf("\nTime stamp for \tP3 ---> ");
    for (i = 1; i <= e; i++) {
        printf("%d ", p3[i]);
    }

    printf("\n\n");
    return 0;
}
