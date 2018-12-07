#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#define PI 3.14159265358979323846264338327


double * randomNumbers(int N){
    double * r;
    r =malloc(sizeof(double)*N);
    int i;

    srand48(N);

    for ( i = 0; i < N; i++) {
      r[i] = drand48()*2-1;
    }

    int sigma_delta = 4.0;

    return r;
}

int main(int argc, char **argv){
  int N = 1000;
  double mu = 0.0;
  double sigma = 1.0;

  double Distribucion(double x,double sigma,double mu)
  {
  double y=1/(sigma * sqrt(2 * PI)) * exp( - pow ( (x-mu)/ (sqrt(2)*sigma),2));
  return y;
  }

  double min(double a, double b)
  {
    if(a<b)
    {return a;}
    else
    {return b;}
  }

  double * metropolis(double *lista, double *propuestas, double *alphas, int N)
  {
      srand48(N);
      lista[0] = randomNumbers(N)[0];
      int i;
      double sig=4.0;
      for (i=1; i<N; i++)
      {
          double propuesta=lista[i-1]+(drand48()*sig-(sig/2));
          double k=min(1.0, Distribucion(propuesta, mu, sigma)/Distribucion(lista[i-1], mu, sigma));
          double alpha=drand48();
          alphas[i]=alpha;
          propuestas[i]=propuesta;
          if(alpha<k)
          {
              lista[i]=propuesta;
          }
          else{
              lista[i]=lista[i-1];
          }
      }
      return lista;
  }
  int j;
  for (j=0;j<8;j++){
    FILE *out;
    char filename[128];
    double * lista;
    double *alphas=malloc(sizeof(double)*N);
    double *propuestas=malloc(sizeof(double)*N);
    lista = metropolis(randomNumbers(N), propuestas, alphas, N);
    sprintf(filename, "numeros_%d.dat", j);
    if(!(out = fopen(filename, "w"))){
      fprintf(stderr, "Problema abriendo el archivo\n");
      exit(1);
    }
    int i;
    for(i=0;i<N;i++){
      fprintf(out, "%f\n",lista[i]);
    }
      fclose(out);
  }
  return 0;
}
