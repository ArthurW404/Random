#include <stdio.h>
#include <math.h>

void main(){
    int input;
    int power;
    int x;
    printf("Enter Instructions: ");
    while (scanf("%d", &input) != EOF) {
        if (input == 1) {
            scanf("%d", &x);
            power = 2;
        } else if (input == 2) {
            scanf("%d%d", &x, &power);
        } 
        printf("%d\n", (int)pow(x, power));
        printf("Enter Instructions: ");
    }
}