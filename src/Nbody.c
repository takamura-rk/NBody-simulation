#include<stdio.h>
#include<stdlib.h>
#include "Nbody.h"
#include <math.h>

NBody* nbody_creat(int N){
    NBody* system=malloc(sizeof(NBody));
    if(system==NULL){
        perror("Allocation failled\n");
        exit(EXIT_FAILURE);
    }
    system->N_part=N;
    //component allocation
    system->x=malloc(sizeof(double)*N);
    if(system->x==NULL){
        perror("Allocation failled of x\n");
        free(system);
        exit(EXIT_FAILURE);
    }
    system->y=malloc(sizeof(double)*N);
    if(system->y==NULL){
        perror("Allocation failled of y\n");
        free(system);
        exit(EXIT_FAILURE);
    }
    system->vx=malloc(sizeof(double)*N);
    if(system->vx==NULL){
        perror("Allocation failled of vx\n");
        free(system);
        exit(EXIT_FAILURE);
    }
    system->vy=malloc(sizeof(double)*N);
    if(system->vy==NULL){
        perror("Allocation failled of vy\n");
        free(system);
        exit(EXIT_FAILURE);
    }
    system->mass=malloc(sizeof(double)*N);
    if(system->mass==NULL){
        perror("Allocation failled of mass\n");
        free(system);
        exit(EXIT_FAILURE);
    }

    return system;
}

void nbody_destroy(NBody* system){
    if(system != NULL){
        free(system->x);
        free(system->y);
        free(system->vx);
        free(system->vy);
        free(system->mass);

        free(system);
    }
}

double compute_distance(const NBody* system, int i, int j){
    double dist=system->x[i]*system->x[j]+system->y[i]*system->y[j];
    return dist;
}

void compute_acceleration(
    const NBody* system,
    int i){
        
        double ax=0;
        double ay=0;
        for(int j=0; j<=system->N_part; j++){
            if(i==j) continue;
            
            double r=compute_distance(system,i,j);
            if(r==0) continue;

            double dx=system->x[i]-system->x[j];
            double dy=system->y[i]-system->y[j];

            double facteur=G*system->mass[j]/(r*r*r);

            ax+=dx*facteur;
            ay+=dy*facteur;

        }
        return sqrt(ax*ax+ay*ay);
}

double compute_forces(const NBody system, int i){

}






