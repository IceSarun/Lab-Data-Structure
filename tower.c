#include <stdio.h>

int nA;
int nB;
int nC;

int A[100];
int B[100];
int C[100];

void move(int n, char from, char to) {
  if (from == 'A') {
    nA--;
  }
  if (from == 'B') {
    nB--;
  }
  if (from == 'C') {
    nC--;
  }
  if (to == 'A') {
    A[nA] = n;
    nA++;
  }
  if (to == 'B') {
    B[nB] = n;
    nB++;
  }
  if (to == 'C') {
    C[nC] = n;
    nC++;
  }
}

void printTower() {
  printf("Tower A: ");
  for (int i = 0; i < nA; i++) 
    printf("%d ", A[i]);
  printf("\nTower B: ");
  for (int i = 0; i < nB; i++) 
    printf("%d ", B[i]);
  printf("\nTower C: ");
  for (int i = 0; i < nC; i++) 
    printf("%d ", C[i]);
  printf("\n");
  
}

void tower(int n, char from, char other, char to) {
  if (n == 0)
    return;

  tower(n - 1, from, to, other);
  printf("Move disk %d from %c to %c\n", n - 1, from, to);
  move(n - 1, from, to);
  printTower();
  tower(n - 1, other, from, to);
}

int main() {
  int n;
  printf("Input N = ");
  scanf("%d", &n);

  nA = n;

  for (int i = n - 1, j = 0; i >= 0; i--, j++) {
    A[j] = i;
  }

  printf("Output:\n");
  printf("Start\n");
  printTower();
  tower(n, 'A', 'B', 'C');

}