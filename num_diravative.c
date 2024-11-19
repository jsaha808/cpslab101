#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <sys/time.h>

#include <unistd.h>

#include <math.h>

/*
  void diff(double* u, int N, double dx, double* du)

  Computes a finite difference approximation for du/dx

  Inputs: 
  u: pointer for input array
  N: length of the array
  dx: the space step size
  du: pointer to output array

  Outputs: 
  du: contains the forward finite difference approximation
*/
void diff(double * u, int N, double dx, double * du) {

  int i;
  //Forward
  du[0] = (u[1] - u[0]) / dx;
  //Cetntral
  for (i = 1; i < N ; ++i) {
    du[i] = (u[i+1] - u[i - 1]) / (2.0*dx);
  }
  //backward
  du[N ] = (u[N] - u[N - 1]) / dx;

}

/*
  void init(double* u, int N, double dx)

  Initializes the data array with the sin function

  Inputs: 
  u: pointer to array will values will be stored
  N: length of the array
  dx: the space step size

  Outputs: 
  u: contains data for a sin function
*/
void init(double * u, int N, double dx) {
  int i;
  for (i = 0; i <= N; ++i){
        u[i] = sin(i * dx);
       // printf("%lf ",i*dx);
  }


}

/*
  int main(int argc, char* argv[])

  Function tests the timing accuracy of 4 different methods

  Inputs: argc should be 2
  argv[1] is the integer length of the data array
  
  Outputs: ???
*/
int main(int argc, char * argv[]) {
  int N = atoi(argv[1]);

  double * u = (double * ) malloc((N+1) * sizeof(double));
  double * du = (double * ) malloc((N+1) * sizeof(double));
  double dx = M_PI / N;

  init(u, N, dx);
  diff(u, N, dx, du);
  for (int i = 0; i <=N; ++i)
    printf("diff = %f - %f = %f \n", cos(i*dx), du[i], cos(i*dx) - du[i]);
  free(u);
  free(du);

  return 0;
}