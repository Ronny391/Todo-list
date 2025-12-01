#include "funzioni.h"
#include <stdio.h>
#include <stdlib.h>

void opzioni(int *scelta) {
  do {
    printf("\n1 - aggiungi task\n2 - task importante \n3 - modificatask \n4 - "
           "sovrascrivi task \n5 - elimina task \n6 - task cominciata \n7 - "
           "task completata \n8 - Visualizza tutto\n9 - esci\n");
    scanf("%d", scelta);
  } while (*scelta > 9 || *scelta < 0);
}

int main() {
  int state = 0, counter_task = 0;

  // Verifico il counter in counter.txt
  FILE *counter_file = fopen("counter.txt", "r");
  if (counter_file == NULL) {
    // File non esiste, crealo con valore 0
    counter_file = fopen("counter.txt", "w");
    if (counter_file != NULL) {
      fprintf(counter_file, "0");
      fclose(counter_file);
    }
    counter_task = 0;
  } else {
    fscanf(counter_file, "%d", &counter_task);
    fclose(counter_file);
  }

  while (1) {
    switch (state) {
    case 0:
      opzioni(&state);
      break;
    case 1:
      aggiungi_task(&counter_task);
      state = 0; // Torna al menu
      break;
    case 2:
      task_importante();
      state = 0; // Torna al menu
      break;
    case 3:
      modifica_task();
      state = 0; // Torna al menu
      break;
    case 4:
      sovrascrivi_task();
      state = 0; // Torna al menu
      break;
    case 5:
      elimina_task();
      state = 0; // Torna al menu
      break;
    case 6:
      task_cominciata();
      state = 0; // Torna al menu
      break;
    case 7:
      task_completata();
      state = 0; // Torna al menu
      break;
    case 8:
      visualizza_tutto();
      state = 0; // Torna al menu
      break;
    case 9:
      return 1;
      break;
    }
  }

  return 0;
}
