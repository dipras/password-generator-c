#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int min = 33;
int max = 125;
int salt = 1;
int generatePw(char* pw, int length) {
  for(int i = 0; i < length; i++) {
    redo:
    srand(time(NULL) + i * salt);
    int value = min + rand() % (max+1 - min);
    if(value == 34 || value == 39 || value == 96) {
      salt++;
      goto redo;
    } else {
      salt = 1;
    }
    pw[i] = value;
  }
  return 0;
}

int main() {
  char choice[2];
  printf("DP PASSWORD GENERATOR\n");
  printf("Select level \n 1.low \n 2.medium \n 3.strong\n");
  printf("Your choice: ");
  fgets(choice, sizeof(choice), stdin);
  int res = strcmp(choice, "0");
  
  char pw[32];
  switch (res) {
    case 1:
      printf("You choose low level scurity\n");
      generatePw(pw, 8);
      break;
    case 2:
      printf("You choose medium level scurity\n");
      generatePw(pw, 16);
      break;
    case 3:
      printf("You choose strong level scurity\n");
      generatePw(pw, 32);
      break;
    default: 
      printf("Invalid choice\n");
    
  }

  printf("%s\n", pw);
  return 0;
}

