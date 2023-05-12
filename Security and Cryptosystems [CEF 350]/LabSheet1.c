#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 // Maximum length of input string

// Function to perform columnar transposition encryption
void columnar_encrypt(char* plaintext, char* ciphertext, int key) {
  int len = strlen(plaintext);
  int rows = (len + key - 1) / key; // Number of rows in the transposition table

  // Allocate memory for the transposition table
  char** table = (char**) malloc(rows * sizeof(char*));
  for (int i = 0; i < rows; i++) {
    table[i] = (char*) malloc(key * sizeof(char));
  }

  // Fill the transposition table with the plaintext
  int index = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < key; j++) {
      if (index < len) {
        table[i][j] = plaintext[index++];
      } else {
        table[i][j] = ' ';
      }
    }
  }

  // Read the ciphertext from the transposition table column by column
  index = 0;
  for (int j = 0; j < key; j++) {
    for (int i = 0; i < rows; i++) {
      ciphertext[index++] = table[i][j];
    }
  }

  // Free the memory allocated for the transposition table
  for (int i = 0; i < rows; i++) {
    free(table[i]);
  }
  free(table);
}

// Function to perform columnar transposition decryption
void columnar_decrypt(char* ciphertext, char* plaintext, int key) {
  int len = strlen(ciphertext);
  int rows = (len + key - 1) / key; // Number of rows in the transposition table

  // Allocate memory for the transposition table
  char** table = (char**) malloc(rows * sizeof(char*));
  for (int i = 0; i < rows; i++) {
    table[i] = (char*) malloc(key * sizeof(char));
  }

  // Fill the transposition table with the ciphertext
  int index = 0;
  for (int j = 0; j < key; j++) {
    for (int i = 0; i < rows; i++) {
      if (index < len) {
        table[i][j] = ciphertext[index++];
      } else {
        table[i][j] = ' ';
      }
    }
  }

  // Read the plaintext from the transposition table row by row
  index = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < key; j++) {
      plaintext[index++] = table[i][j];
    }
  }

  // Free the memory allocated for the transposition table
  for (int i = 0; i < rows; i++) {
    free(table[i]);
  }
  free(table);
}

int main() {
  char plaintext[MAX_LEN];
  char ciphertext[MAX_LEN];
  int key = 5; // Change this to the desired key length

  // Read the plaintext from the user
  printf("Enter plaintext: ");
  fgets(plaintext, MAX_LEN, stdin);
  plaintext[strcspn(plaintext, "n")] = 0; // Remove trailing newline character

  // Encrypt the plaintext using columnar transposition
  columnar_encrypt(plaintext, ciphertext, key);
  printf("Ciphertext: %sn", ciphertext);

  // Decrypt the ciphertext using columnar transposition
  char decrypted_text[MAX_LEN];
  columnar_decrypt(ciphertext, decrypted_text, key);
  printf("Decrypted text: %sn", decrypted_text);

  return 0;
}
