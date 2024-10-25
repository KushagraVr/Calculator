#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float valueOne, valueTwo, result;
    char operator;

    printf("Welcome to the Calculator!\n");
    printf("Enter calculation (e.g., 3 + 4) or use 'r' for square root (e.g., r 16):\n");

    // Read the input
    while (1) {
        int inputCount = scanf(" %c", &operator);

        // Check for square root operation
        if (operator == 'r') {
            inputCount += scanf("%f", &valueTwo);
            if (inputCount != 2) {
                printf("Invalid input. Please try again.\n");
                continue;
            }
            result = sqrt(valueTwo);
            printf("sqrt(%.9g) = %.6g\n", valueTwo, result);
        }
        else {
            ungetc(operator, stdin); // Put back the operator to read values
            inputCount = scanf("%f %c %f", &valueOne, &operator, &valueTwo);
            if (inputCount != 3) {
                printf("Invalid input. Please try again.\n");
                continue;
            }

            switch (operator) {
                case '+':
                    result = valueOne + valueTwo;
                    break;
                case '-':
                    result = valueOne - valueTwo;
                    break;
                case '*':
                    result = valueOne * valueTwo;
                    break;
                case '/':
                    if (valueTwo == 0) {
                        printf("Error: Division by zero.\n");
                        continue;
                    }
                    result = valueOne / valueTwo;
                    break;
                case '^':
                    result = pow(valueOne, valueTwo);
                    break;
                default:
                    printf("Invalid operator. Please try again.\n");
                    continue;
            }
            printf("%.9g %c %.9g = %.6g\n", valueOne, operator, valueTwo, result);
        }

        // Prompt for another calculation
        printf("\nEnter another calculation (or Ctrl+C to exit):\n");
    }

    return 0;
}
  
