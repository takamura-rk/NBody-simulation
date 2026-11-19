#include<unity.h>
#include<stdio.h>
#include<stdlib.h>
#include"Nbody.h"

void test_NBody_creat() {
    NBody* system = nbody_creat(3);

    TEST_ASSERT_NOT_NULL(system);

    TEST_ASSERT_EQUAL(3, system->N_part);

    TEST_ASSERT_NOT_NULL(system->x);
    TEST_ASSERT_NOT_NULL(system->y);
    TEST_ASSERT_NOT_NULL(system->vx);
    TEST_ASSERT_NOT_NULL(system->vy);
    TEST_ASSERT_NOT_NULL(system->mass);

    for (int i = 0; i < system->N_part; i++) {
        TEST_ASSERT_TRUE(system->x[i]==0);
        TEST_ASSERT_TRUE(system->y[i]==0);
        TEST_ASSERT_TRUE(system->vx[i]==0);
        TEST_ASSERT_TRUE(system->vy[i]==0);
        TEST_ASSERT_TRUE(system->mass[i]==0);
    }

    nbody_destroy(system);
}


void test_NBody_distance() {
    NBody* system = nbody_creat(2);
    TEST_ASSERT_NOT_NULL(system);

    system->x[0] = 2.0;
    system->x[1] = 4.0;
    system->y[0] = 1.0;
    system->y[1] = 1.0;
    
    double dist = compute_distance(system, 0, 1);
    TEST_ASSERT_EQUAL_DOUBLE(3.0, dist); 
    nbody_destroy(system);
}