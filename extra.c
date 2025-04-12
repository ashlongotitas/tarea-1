#include "extra.h"


#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 300

char **leer_linea_csv(FILE *archivo, char separador) {
  static char linea[MAX_LINE_LENGTH];
  static char *campos[MAX_FIELDS];
  char *ptr, *start;
  int idx = 0;

  if (fgets(linea, MAX_LINE_LENGTH, archivo) == NULL) {
    return NULL; 
  }


  linea[strcspn(linea, "\n")] = '\0';

  ptr = start = linea;
  while (*ptr) {
    if (idx >= MAX_FIELDS - 1)
      break;

    if (*ptr == '\"') {
      start = ++ptr;    
      while (*ptr && !(*ptr == '\"' && *(ptr + 1) == separador))
        ptr++;
    } else { 
      start = ptr;
      while (*ptr && *ptr != separador)
        ptr++;
    }

    if (*ptr) {
      *ptr = '\0'; 
      ptr++;
      if (*ptr == separador)
        ptr++;
    }

    if (*(ptr - 2) == '\"') {
      *(ptr - 2) = '\0';
    }

    campos[idx++] = start;
  }

  campos[idx] = NULL;
  return campos;
}

List *split_string(const char *str, const char *delim) {
  List *result = list_create();
  char *token = strtok((char *)str, delim);

  while (token != NULL) {
    while (*token == ' ') {
      token++;
    }

    char *end = token + strlen(token) - 1;
    while (*end == ' ' && end > token) {
      *end = '\0';
      end--;
    }

    char *new_token = strdup(token);

    list_pushBack(result, new_token);

    token = strtok(NULL, delim);
  }

  return result;
}

void limpiarPantalla() { system("clear"); }

void presioneTeclaParaContinuar() {
  puts("Presione una tecla para continuar...");
  getchar();
  getchar(); 
}
