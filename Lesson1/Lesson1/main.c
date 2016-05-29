//
//  main.c
//  Lesson1
//
//  Created by Apollonian on 16/5/25.
//  Copyright © 2016年 WWITDC. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define FINAL
#define testNumber 1

void question(int num){
    switch (num) {
        case 1:{
            int a,b,c;
            scanf("%d%d%d", &a, &b, &c);
            double ave = (a+b+c)/3.0;
            printf("%.3f\n", ave);
            break;
        }
        case 2:{
            double f,c;
            scanf("%lf", &f);
            c = 5*(32-f)/9.0;
            printf("%.3f\n", c);
            break;
        }
        case 3:{
            int total, result;
            scanf("%d", &total);
            if (total == 1){
                result = total;
            } else {
                result = (1 + total)*total/2;
            }
            printf("%d\n", result);
            break;
        }
        case 4:{
            // Need to be degree
            int n;
            double sinN, cosN;
            scanf("%d", &n);
            sinN = sin(n * M_PI / 180);
            cosN = cos(n * M_PI / 180);
            printf("%f\n%f\n", sinN, cosN);
            break;
        }
        case 5:{
            int total;
            scanf("%d", &total);
            double result = total * 95;
            if (result >= 300){
                result = result * 0.85;
            }
            printf("%.2f\n", result);
            break;
        }
        case 6:{
            int a,b,c;
            scanf("%d%d%d", &a, &b, &c);
            if (a > b) {a=a+b;b=a-b;a=a-b;}
            if (a > c) {a=a+c;c=a-c;a=a-c;}
            if (b > c) {b=b+c;c=b-c;b=b-c;}
            if (a + b > c){
                if (a*a + b*b == c*c){
                    printf("yes\n");
                } else {
                    printf("no\n");
                }
            } else {
                printf("not a triangle\n");
            }
            break;
        }
        case 7:{
            int n;
            scanf("%d", &n);
            if (n % 100 == 0){
                if (n % 400 == 0){
                    printf("yes\n");
                } else {
                    printf("no\n");
                }
            } else if (n % 4 == 0){
                printf("yes\n");
            } else {
                printf("no\n");
            }
            break;
        }
        default:
            break;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    #ifdef FINAL
        for (int i = 1; i<=7; i++){
            question(i);
        }
    #endif
    #ifdef TEST
        question(testNumber);
    #endif
    return 0;
}