// 有可能一直繞圈圈 => 20
// 2*2 + 0*0 = 4
// 4*4       = 16
// 1*1 + 6*6 = 37
// 3*3 + 7*7 = 58
// 5*5 + 8*8 = 89
// 8*8 + 9*9 = 145
// 1*1 + 4*4 + 5*5 = 42
// 4*4 + 2*2 = 20

// => cycle detection 怎麼知道你在繞圈圈

// 1 => 1 => 1 : true
// 20 => ... => 20 : false

// 怎麼把數字拆開 => 19 => 1, 9

// n = 12345
// 1, 2, 3, 4, 5 or 5, 4, 3, 2, 1 不在意順序
// int next_n = 1*1+2*2+3*3+4*4+5*5
// 不在意順序
// d1 = n % 10;           d1 = 5
// d2 = n / 10 % 10;      d2 = 4
// d3 = n / 100 % 10;     d3 = 3
// d4 = n / 1000 % 10;    d4 = 2
// d5 = n / 10000 % 10;   d5 = 1

// 怎麼知道 n 幾位數 ?
// int 其實有上界 INT_MAX 2147483647 <= 最多就十位數 測資給你最大就這麼大
// 過高的位數是零 但不重要 0*0 = 0
// 方法一 都當成十個數字在看 永遠都跑十次

/*
bool isHappy(int n){
    int r = 0;
    for(int m = 1; m <= 1000000000; m *= 10){
        int d = n / m % 10; //d
        r += d * d;
    }
}
*/ // run time error

/*

int r = 0;
int m = 1;
for(int m = 1000000000; m >= 1; m /= 10){
    int d = n / m % 10;
    r += d * d;
}
return false;

*/

/*

int n = 12345;

int r = 0;

int s = n;  // s: 12345

d = s % 10; // d: 5
s /= 10;    // s: 1234

d = s % 10; // d: 4
s /= 10;    // s: 123

d = s % 10; // d: 3
s /= 10;    // s: 12

d = s % 10; // d: 2
s /= 10;    // s: 1

d = s % 10; // d: 1
s /= 10;    // s: 0

r += d * d;

whlie(s ! = 0){
    d = s % 10;
    s /= 10;
    r += d * d;
}

s也可以拿掉了

whlie(n ! = 0){
    d = n % 10;
    n /= 10;
    r += d * d;
}

*/

/*

新能力 : 把各位數拆開 平方 加起來

int next_n(int n){
    int r = 0;
    while(n != 0){
        int d = n % 10;
        n /= 10;
        r += d * d;
    }
    return r;
}

*/

/*

bool isHappy(int n){
    n = next_n(n);
    return false;
}

新問題 n = next_n(n) 要跑幾次 ? 遇到 20 這種不會停的又該怎麼辦 ?

*/

/*

bool isHappy(int n){

    while(n 沒有出現過的時候){
        n = next_n(n);
    }
    return n == 1;
}

*/

/*

bool isHappy(int n){

    // history: []
    // size : 0

    while(!contains(history, size, n)){
        history[size] = n;
        size++;

        n = next_n(n);
    }
    return n == 1;
}

*/

/*

int next_n(int n){
    int r = 0;
    while(n != 0){
        int d = n % 10;
        n /= 10;
        r += d * d;
    }
    return r;
}

bool contains(int * history, int size, int n){
    for(int i = 0; i < size; i++){
        if(history[i] == n){    // 有出現過 回傳 true
            return true;
        }
    }
    return false;
}

bool isHappy(int n){

    int history[10000];
    int size = 0;

    while(!contains(history, size, n)){
        history[size] = n;
        size++;

        n = next_n(n);
    }
    return n == 1;
}

*/

// Floyd's Tortoise and Hare

#include <stdbool.h>
#include <stdio.h>

int next_n(int n){
    int r = 0;
    while(n != 0){
        int d = n % 10;
        n /= 10;
        r += d * d;
    }
    return r;
}

bool isHappy(int n){
    int slow = n;
    int fast = n;

    do {
        slow = next_n(slow);
        fast = next_n(next_n(fast));
    } while (slow != fast);

    return fast == 1;
}