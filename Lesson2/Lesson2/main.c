//
//  main.c
//  Lesson2
//
//  Created by Apollonian on 16/5/25.
//  Copyright © 2016年 WWITDC. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define FINAL
#define testNumber 3

void question(int num){
    FILE *fin;
    switch (num) {
        case 1:
        {
            for (int i = 100; i<=999; i++){
                int a, b, c;
                a = i / 100;
                b = i/10%10;
                c = i % 10;
                if (a*a*a + b*b*b + c*c*c == i){
                    printf("%d\n", i);
                }
            }
            break;
        }
        case 2:
        {
            int currentItem = 1;
            int num;
            int n1 = 0;
            int n2 = 0;
            int n3 = 0;
#ifdef TEST
            freopen("2-2.in", "r", stdin);
            while (scanf("%d", &num) == 1) {
#else
            fin = fopen("2-2.in", "r");
            while (fscanf(fin, "%d", &num) == 1) {
#endif
                switch (currentItem) {
                    case 1:
                        n1 = num;
                        currentItem = 2;
                        break;
                    case 2:
                        n2 = num;
                        currentItem = 3;
                        break;
                    case 3:
                        n3 = num;
                        currentItem = 1;
                        int notFound = 1;
                        int i = 10;
                        while (notFound == 1 && i <= 100) {
                            if (((i - n1)%3 == 0) && ((i - n2)%5 == 0) && ((i - n3)%7 == 0)){
                                printf("%d\n", i);
                                notFound = 0;
                            }
                            i += 1;
                        }
                        if (notFound == 1){
                            printf("No answer\n");
                        }
                        n1 = 0;
                        n2 = 0;
                        n3 = 0;
                        break;
                    default:
                        break;
                }
            }
#ifndef TEST
            fclose(fin);
#endif
            break;
        }
        case 3:
        {
            int n;
            scanf("%d", &n);
            for (int i = n; i > 0; i--){
                for (int j = 0; j < n - i; j++){
                    printf(" ");
                }
                for (int j = 0; j < i - 1; j++){
                    printf("#");
                }
                printf("#");
                for (int j = 0; j < i - 1; j++){
                    printf("#");
                }
                for (int j = 0; j < n - i; j++){
                    printf(" ");
                }
                printf("\n");
            }
            break;
        }
        case 4:
        {
            int a, b;
            long double partialResult;
#ifdef TEST
            freopen("2-4.in", "r", stdin);
            while ((scanf("%d%d", &a, &b) == 2) && (!(a==0 && b==0))){
#else
            fin = fopen("2-4.in", "r");
            while ((fscanf(fin,"%d%d", &a, &b) == 2) && (!(a==0 && b==0))){
#endif
                partialResult = 0.0;
                for (long long i = a; i <= b; i++) {
                    partialResult = partialResult + 1.00000/(i*i);
                }
                printf("%.5Lf\n", partialResult);
            }
#ifndef TEST
            fclose(fin);
#endif
            break;
        }
        case 5:
        {
            int a,b,c;
            long double result;
#ifdef TEST
            freopen("2-5.in", "r", stdin);
            while ((scanf("%d%d%d", &a, &b, &c) == 3) && (!(a==0 && b==0 && c==0))){
#else
            fin = fopen("2-5.in", "r");
            while ((fscanf(fin, "%d%d%d", &a, &b, &c) == 3) && (!(a==0 && b==0 && c==0))){
#endif
                result = 1.0 * a / b;
                // Thanks to http://blog.sina.com.cn/s/blog_7b9cc0870100s1en.html
                // I'm thinking about why the author did this kind of thing to us...
                // The book should provide a list about what these kind of strange symbols stand for
                printf("%.*Lf\n",c,result);
            }
#ifndef TEST
            fclose(fin);
#endif
            break;
        }
        case 6:
        {
            for (int a = 1; a<=4; a++) {
                for (int b = 1; b<=9; b++){
                    for (int c = 1; c<=9; c++){
                        for (int d = 1; d<=9; d++){
                            for (int e = 1; e<=9; e++){
                                for (int f = 1; f<=9; f++){
                                    for (int g = 1; g<=9; g++){
                                        for (int h = 1; h<=9; h++){
                                            for (int i = 1; i<=9; i++){
                                                if (a*b*c*d*e*f*g*h*i == 362880){
                                                    if (((100*a+10*b+c)*6 == (100*d+10*e+f)*3) && ((100*d+10*e+f)*3 == (100*g+10*h+i)*2)){
                                                        printf("%d%d%d %d%d%d %d%d%d\n",a,b,c,d,e,f,g,h,i);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
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
    for (int i=1; i<=6; i++) {
        printf("\n");
        printf("%d ----\n", i);
        question(i);
    }
    printf("\n");
#endif
#ifdef TEST
    question(testNumber);
#endif
    return 0;
}
