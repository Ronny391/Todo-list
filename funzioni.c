#include "funzioni.h"
#include <stdio.h>
#include <stdlib.h>

void aggiungi_task(int *task_counter) {
  FILE *file = fopen("Todo.txt", "a");
  printf("\naggiungi task = ");
  char task[264];
  scanf(" %263[^\n]", task);
  (*task_counter)++;
  FILE *counter_file = fopen("counter.txt", "w");
  fprintf(counter_file, "%d", *task_counter);
  fprintf(file, "%d - ( ) %s\n", *task_counter, task);
  fclose(file);
}

void task_importante() {}

void modifica_task() {
  FILE *file = fopen("Todo.txt", "r+");
  visualizza_tutto();
  printf("Quale task vuoi modificare? = ");
  int task_da_modificare = 0;
  scanf("%d", task_da_modificare);

  FILE *copia_file;

  fclose(file);
}

void sovrascrivi_task() {}
void elimina_task() {}
void task_cominciata() {}
void task_completata() {}

void visualizza_tutto() {
  FILE *file = fopen("Todo.txt", "r");
  if (file == NULL)
    return;

  char riga[256];
  while (fgets(riga, sizeof(riga), file) != NULL) {
    printf("%s", riga);
  }

  fclose(file);
}
