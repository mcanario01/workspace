#include <stdio.h>

int main(){
    int x[4];
    for (int i = 0; i < 4; i++){
        x[i] = i*i;
    }
    int* y = x;
    int* z;
    z = y + 3;
    *y = x[2] - *z;
}