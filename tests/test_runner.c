#include <unity.h>
#include <stdlib.h>
#include "Nbody.h"

extern void test_NBody_creat();
extern void test_NBody_distance();

void setUp(void) {}
void tearDown(void) {}

int main(void){
    
    UNITY_BEGIN();
    RUN_TEST(test_NBody_creat);
    RUN_TEST(test_NBody_distance);

    return UNITY_END();
}