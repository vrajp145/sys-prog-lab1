/* Author: Vraj Patel
   Date: 2/5/24
    */

/***
 *      ______ .___  ___. .______     _______.  ______        ____    __   __  
 *     /      ||   \/   | |   _  \   /       | /      |      |___ \  /_ | /_ | 
 *    |  ,----'|  \  /  | |  |_)  | |   (----`|  ,----'        __) |  | |  | | 
 *    |  |     |  |\/|  | |   ___/   \   \    |  |            |__ <   | |  | | 
 *    |  `----.|  |  |  | |  |   .----)   |   |  `----.       ___) |  | |  | | 
 *     \______||__|  |__| | _|   |_______/     \______|      |____/   |_|  |_| 
 *                                                                                   
 */


#include "student.h"

// Takes an array of integers and the length of the array as input, and returns
// the smallest integer in the array
int smallest(int *array, int length) {
  /* YOUR CODE */
  int min = array[0]; // Assume first element is the smallest
    for (int i = 1; i < length; i++) {
        if (array[i] < min) { // If find smaller, update min
            min = array[i];
        }
    }
  return min;
}

// Takes an array of integers and the length of the array as input, and returns
// the product of the integers in the array.
int product(int *array, int length) {
  /* YOUR CODE */
  int prod = 1; // Start with product as 1
    for (int i = 0; i < length; i++) {
        prod *= array[i]; // Multiply current element to product
    }
  return prod;
}

// Takes pointers to two integers and swaps the values of integers
void swap(int *a, int *b) {
  /* YOUR CODE */
  int temp = *a; 
    *a = *b; // Swap values
    *b = temp; // Complete swap using temp
}

// Rotate values of integers
void rotate(int *a, int *b, int *c) {
  /* YOUR CODE */
  int temp = *a; 
    *a = *c; 
    *c = *b; 
    *b = temp; // Move initial value of a to b, completing the rotation
}

// Sorts an array in descending order
void sort(int *array, int length) {
  /* YOUR CODE */
  for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j] < array[j + 1]) { // Descending order check
                swap(&array[j], &array[j + 1]); // Swap if the next element is larger
            }
        }
    }
}

// Takes an array of integers and the length of the array as input and halves
// every prime element of the array

// Helper function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; // Factor found, not prime
    }
    return 1; // No factors found, is prime
}

void halve_primes(int *array, int length) {
  /* YOUR CODE */
  for (int i = 0; i < length; i++) {
        if (is_prime(array[i])) { // Check if current element is prime
            array[i] /= 2; // Halve it if it is prime
        }
    }
}  

// Takes an array of integers and the length of the array as input and square
// every positive element of the array that is an Armstrong number.
int power(int base, int exp) {
    int result = 1;
    while (exp != 0) {
        result *= base;
        exp--;
    }
    return result;
}

int is_armstrong(int num) {
    if (num < 0) return 0; // Armstrong numbers are positive

    int original = num;
    int sum = 0;
    int n = 0;
    int temp = num;

    // Calculate the number of digits in num
    while (temp > 0) {
        n++;
        temp /= 10;
    }

    temp = num; // Reset temp to original num
    // Calculate the sum of the digits raised to the power of n
    while (temp > 0) {
        int digit = temp % 10;
        sum += power(digit, n);
        temp /= 10;
    }

    // Check if the sum is equal to the original number
    return sum == original;
}

void square_armstrongs(int *array, int length) {
  /* YOUR CODE */
  for (int i = 0; i < length; i++) {
        if (is_armstrong(array[i]) && array[i] > 0) { // Check for positive Armstrong number
            array[i] = array[i] * array[i]; // Square it
        }
    }
}

// Take an array of integers and length of the arrays as input and triple every
// happy number of that array
int sum_of_squares(int num) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum = sum + (digit * digit);
        num /= 10;
    }
    return sum;
}

int is_happy(int num) {
    for (int i = 0; i < 1000; i++) { // Limit iterations to prevent infinite loops
        num = sum_of_squares(num);
        if (num == 1) {
            return 1; // The number is happy
        }
    }
    return 0; // Assume the number is not happy after 1000 iterations
}


void triple_happy(int *array, int length) {
  /* YOUR CODE */
  for (int i = 0; i < length; i++) {
        if (is_happy(array[i])) { // Check if current element is a happy number
            array[i] *= 3; // Triple it
        }
    }
}
/*CWD /home/cmpsc311/.ssh/sp24-lab1-vrajp145 */
/*CWD /home/cmpsc311/.ssh/sp24-lab1-vrajp145 */
