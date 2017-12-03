#include "woo.h"

/*int main(void) {*/
    /*woo(1, 2);*/
    /*return 0;*/
/*}*/

#ifdef WOO_FUNC
int woo(int a, int b) {
    int c;
    /*for (int i = 0; i < 5; i++)*/
        /*c += a + b + LIFE + i;*/
    c = a + b + LIFE;
    return c;
}
#endif

#ifndef WOO_FUNC
int woo(int a, int b) {
    int c;
    c = a * b * LIFE;
    return c;
}
#endif
