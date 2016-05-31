//
//  main.c
//  Lesson3
//
//  Created by Apollonian on 16/5/25.
//  Copyright © 2016年 WWITDC. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define maxLength 1000 + 10
int a[maxLength];
char s[maxLength];
double f[maxLength];
#define TEST

void lightsUp(){
    int n, k, first = 1;
    memset(a, 0, sizeof(a));
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
        for (int j = i; j <= n; j += i)
            // Originally `for (int j = 1; j <= n; j++)`
            a[j] = !a[j];
    for (int i = 1; i<=n; i++){
        if (a[i]){
            if (first == 1)
                first = 0;
            else {
                printf(" ");
            }
            printf("%d", i);
        }
    }
}

int less(const char* str, int newShift, int currentShift){
    int n = strlen(str);
    for (int i = 0; i<n; i++){
        // If any character is different
        if (str[(newShift+i)%n] != str[(currentShift+i)%n]){
            return str[(newShift+i)%n] < str[(currentShift+i)%n];
        }
    }
    // Indifferent
    return 0;
}

void circularSequence(){
    int totalStrings;
    char str[maxLength];
    scanf("%d", &totalStrings);
    while(totalStrings--){
        // Read current string
        scanf("%s", str);
        // Reinitialize
        // First character
        int shift = 0;
        // Length of string
        int n = strlen(str);
        //
        for (int i = 0; i < n; i++){
            if (less(str, i, shift)){
                shift = i;
            }
        }
        for (int i = 0; i < n; i++){
            putchar(str[(i+shift)%n]);
        }
        putchar('\n');
    }
}

void fixError(){
    char s[maxLength];
    scanf("%s", s);
    int tot = 0;
    for (int i = 0; i < strlen(s); i++){
        if (s[i] == '1') tot++;
    }
    printf("%d\n", tot);
}

void question(int num){
    switch (num) {
        case 1:
        {
            // UVa 1585
            int count = 0;
            scanf("%d", &count);
            memset(a, 0, sizeof(a));
            for (int i = 1; i <= count; i++){
                memset(s, 0, sizeof(s));
                scanf("%s", s);
                int n = strlen(s);
                int cur = 1;
                int tot = 0;
                for (int i = 0; i < n; i++){
                    if (s[i] == 'O'){
                        tot += cur++;
                    } else {
                        cur = 1;
                    }
                }
                a[i] = tot;
            }
            for (int i = 1; i<=count; i++){
                printf("%d\n", a[i]);
            }
            break;
            /*
             5
             OOXXOXXOOO
             OOXXOOXXOO
             OXOXOXOXOXOXOX
             OOOOOOOOOO 
             OOOOXOOOOXOOOOX
             ---
             10
             9
             7 
             55 
             30
             */
        }
        case 2:
        {
            // UVa1586
            int count;
            scanf("%d", &count);
            memset(f, 0, sizeof(f));
            char c;
            for (int i = 0; i <= count; i++){
                double multipler = 0.0;
                int base = 0;
                double total = 0.0;
                while ((c = getchar()) != '\n'){
                    if (isalpha(c)){
                        if (base){
                            total += multipler * base;
                        } else {
                            total += multipler;
                        }
                        base = 0;
                        switch (c) {
                            case 'C':
                            {
                                multipler = 12.01;
                                break;
                            }
                            case 'H':
                            {
                                multipler = 1.008;
                                break;
                            }
                            case 'O':
                            {
                                multipler = 16.00;
                                break;
                            }
                            case 'N':
                            {
                                multipler = 14.01;
                                break;
                            }
                            default:
                                break;
                        }
                    } else if (isdigit(c)){
                        base = base * 10 + c - '0';
                    }
                }
                if (!base){
                    total += multipler;
                } else {
                    total += multipler * base;
                }
                if (total){
                    f[i] = total;
                }
            }
            for (int i = 1; i<= count; i++){
                printf("%.3f\n", f[i]);
                // How about %.3fg/mol\n
            }
            break;
            /*
             4
             C
             C6H5OH
             NH2CH2COOH
             C12H22O11
             -----
             12.010
             94.108
             75.070
             342.296
             */
        }
        case 3:
        {
            // UVa1225
            int n;
            scanf("%d", &n);
            int s[10];
            memset(s, 0, sizeof(s));
            for (int i = 1; i<=n; i++){
                int tmp = i;
                while (tmp){
                    int digit = tmp % 10;
                    s[digit] += 1;
                    tmp /= 10;
                }
            }
            for (int i = 0; i < 9; i++){
                printf("%d ", s[i]);
            }
            printf("%d\n", s[9]);
            break;
        }
        case 4:
        {
            // UVa455
            printf("Progressing");
            break;
        }
        case 5:
        {
            //UVa227
            break;
        }
        case 6:
        {
            // UVa232
            break;
        }
        case 7:
        {
            // UVa1368
            break;
        }
        case 8:
        {
            //UVa202
            break;
        }
        case 9:
        {
            //UVa10340
            break;
        }
        case 10:
        {
            //UVa1587
            break;
        }
        case 11:
        {
            //UVa1588
            break;
        }
        case 12:
        {
            //UVa11809
            break;
        }
        default:
            break;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
#ifdef FINAL
    for (int i = 1; i <= 12; i++){
        question(i);
    }
#else
    question(2);
#endif
    return 0;
}
