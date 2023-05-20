/*
 #include <stdio.h>
#include <stdlib.h>

int soma_imp(int n, int notas[n] ){
  int cont = 0;
  for(int i =0; i < n; i++){
    if (notas[i] %2 != 0){
      cont += notas[i];
    }
  } return cont; 
  
  
}
int soma_par(int n, int notas[n] ){
  int cont = 0;
  for(int i =0; i < n; i++){
    if (notas[i] %2 == 0){
      cont += notas[i];
    }
  } return cont; 
  
  
}

int main(void) {
  int n, i;
  scanf("%d", &n);
  int notas[n];
  for(i = 0;i <n;i++ ){
    scanf("%d", &notas[i]);
  }
  int imp = soma_imp( n, notas);
  int par = soma_par(n, notas);
  printf("%d\n %d\n", imp, par);
};


 
  
  
  
*/