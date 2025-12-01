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
  fclose(counter_file);
}

void task_importante() {}

void modifica_task() {
  FILE *counter_file = fopen("counter.txt", "r");
  int max_task = 0;

  FILE *originale = fopen("Todo.txt", "r");
  FILE *copia = fopen("Todo_temp.txt", "w");
  visualizza_tutto();

  if (originale == NULL || copia == NULL) {
    printf("nulla da modificare\n");
    return;
  }

  char riga[256];
  printf("numero task da modificare? = ");
  int num_temp = 0, numero_task_mod = 0;
  scanf("%d", &numero_task_mod);

  // controllo se la task n* esiste
  if (counter_file != NULL && fscanf(counter_file, "%d", &max_task) == 1) {
    fclose(counter_file);

    if (numero_task_mod > max_task) {
      printf("Errore: task %d non esiste (max: %d)\n", numero_task_mod,
             max_task);
      return;
    }
  } else {
    printf("Nessuna task esistente\n");
    if (counter_file != NULL)
      fclose(counter_file);
    return;
  }

  while (getchar() != '\n') // calcello ca cache dello scanf precedente
    ;

  while (fgets(riga, sizeof(riga), originale) != NULL) {
    num_temp++;
    if (num_temp == numero_task_mod) {

      printf("%s", riga);
      char riga_in_modifica[256];
      printf("MODIFICA = ");
      scanf(" %254[^\n]", riga_in_modifica);
      fprintf(copia, "%d - ( ) %s\n", numero_task_mod, riga_in_modifica);

    } else {
      fprintf(copia, "%s", riga);
    }
  }

  fclose(copia);
  fclose(originale);
  remove("Todo.txt");
  rename("Todo_temp.txt", "Todo.txt");
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
