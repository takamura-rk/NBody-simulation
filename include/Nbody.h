#ifndef NBODY_H
#define NBODY_H

#include <stdio.h>
#include <stdlib.h>

#define G 6.67430 * 1e-11

typedef struct{
    double* x;
    double* y;
    double* vx;
    double* vy;
    double* mass;
    int N_part;
} NBody;

NBody* nbody_creat(int N);
void nbody_destroy(NBody* system);

double compute_distance(const NBody* system, int i, int j);
double compute_acceleration(
    const NBody* system,
    int i);

double compute_forces(const NBody* system, int i);

// void update_positions(NBody* system, double dt);
// void update_velocities(NBody* system, double dt);

double compute_kinetic_energy(const NBody* system);
double compute_potential_energy(const NBody* system);
double compute_total_energy(const NBody* system);

double compute_momentum_x(const NBody* system);
double compute_momentum_y(const NBody* system);







#endif