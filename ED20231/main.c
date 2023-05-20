#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
  char autor[20];
  char titulo[30];
  float valor;
} Livro;

Livro *cadastrarLivro(Livro *livros, int *tamanho) {
 (*tamanho)++;
  system("clear");

  if (*tamanho == 1)
    livros = (Livro *)malloc(sizeof(Livro));
  else {
    livros = (Livro *)realloc(livros, (*tamanho) * sizeof(Livro));
  }

  printf("CADASTRAR NOVO LIVRO:\n\n");
  printf("Insira o autor do livro:\t");
  scanf("%s", livros[(*tamanho) - 1].autor);

  printf("\nInsira o titulo do livro:\t");
  scanf("%s", livros[(*tamanho) - 1].titulo);

  printf("\nInsira o valor do livro:\t");
  scanf("%f", &livros[(*tamanho) - 1].valor);

  system("clear");

  return livros;
}

void mediaLivros(Livro *livros, int *tamanho, float *ptMedia) {
  (*ptMedia) = 0;

  for (int i = 0; i < *tamanho; i++) {
    (*ptMedia) += livros[i].valor;
  }
  (*ptMedia) = (float)(*ptMedia) / *tamanho;
}

int acimaMedia(Livro *livros, int tamanho, float media) {
  int cont = 0;

  for (int i = 0; i < tamanho; i++) {
    if (livros[i].valor > media)
      cont++;
  }

  return cont;
}

int buscaLivro(Livro *livros, int tamanho, char busca[]) {
  for (int i = 0; i < tamanho; i++) {
    if ((strcmp(livros[i].autor, busca) == 0) ||
        (strcmp(livros[i].titulo, busca) == 0))
      return i + 1;
  }
  return 0;
}

int main(void) {
  int resposta, tamanho = 0, novo_tamanho, cont, *ptTamanho;
  float media_valor, *ptMedia;
  char esp, busca[20];
  Livro *livros;

  ptTamanho = &tamanho;
  ptMedia = &media_valor;

  system("clear");
  while (1) {
    printf("Selecione uma das opções abaixo:\n\n");
    printf("1\tCadastrar um livro;\n");
    printf("2\tCalcular media de preços;\n");
    printf("3\tCalcular quantos livros estão acima da media;\n");
    printf("4\tLocalizar um livro;\n");
    printf("5\tSair do programa.\n\n");

    scanf("%d", &resposta);

    if (resposta == 1) {
      livros = cadastrarLivro(livros, ptTamanho);
    }

    if (resposta == 2) {
      system("clear");
      if (tamanho == 0)
        printf("Nenhum livro foi cadastrado!\n");
      else {
        mediaLivros(livros, ptTamanho, ptMedia);
        printf("A media de livros:\t%.2f", media_valor);
      }
    }

    if (resposta == 3) {
      system("clear");
      if (tamanho == 0)
        printf("Nenhum livro foi cadastrado!\n");
      else {
        mediaLivros(livros, ptTamanho, ptMedia);
        printf("\nLivros acima da media:\t%d",
               acimaMedia(livros, tamanho, media_valor));
      }
    }

    if (resposta == 4) {
      system("clear");

      if (tamanho == 0)
        printf("Nenhum livro foi cadastrado!\n");
      else {
        printf("Insira o autor ou o titulo do livro a ser buscado:\t");
        scanf("%s", busca);

        if (buscaLivro(livros, tamanho, busca) == 0)
          printf("Não foi encontrado!\n\n\n");
        else {
          printf("É o livro Nº%d", buscaLivro(livros, tamanho, busca));
        }
      }
    }

    if (resposta == 5)
      break;

    if (tamanho > 0) {
      printf("LIVRO %d\n", tamanho);
      printf("\nAutor:\t%s", livros[tamanho - 1].autor);
      printf("\nTitulo:\t%s", livros[tamanho - 1].titulo);
      printf("\nValor:\t%.2f\n\n\n", livros[tamanho - 1].valor);
    }
  }

  return 0;
}
