/*
#include <stdio.h>

struct Ponto{
  int x;
  int y;
};

typedef struct Ponto Ponto;

int contemPonto(Ponto *p1, Ponto *p2, Ponto *p);

int main(void) {
  Ponto p1, p2, p;

  printf("Informe os pontos que formam o retangulo: \n");
  printf("Vertice inferior esquerdo (x y): \n");
  scanf("%d%d",&p1.x,&p1.y);
  printf("Vertice superior direito (x y): \n");
  scanf("%d%d",&p2.x,&p2.y);
  printf("Agora informe um ponto qualquer (x y): \n");
  scanf("%d%d",&p.x,&p.y);
  
  if (contemPonto(&p1,&p2,&p))
    printf("Ponto no interior do Retangulo.");
  else
    printf("Ponto fora do Retangulo.");
  
}

// vi = vertice inferior esquerdo
// vs = vertice superior direito
// Nao considerei como interior se estiver na linha imaginaria que forma o retangulo
int contemPonto(Ponto *vi, Ponto *vs, Ponto *p){
    if (p->x > vi->x && p->x < vs->x && p->y > vi->y && p->y <vs->y)
      return 1;
    return 0;  
}

*/