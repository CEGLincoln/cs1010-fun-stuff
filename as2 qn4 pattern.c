/**
 * CS1010 Semester 1 AY18/19
 * Assignment 2: Pattern
 *
 * @file: pattern.c
 * @author: Lincoln Lim (Group C1A)
 */

#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

/*========== FUNCTIONS ==========*/
void start(long n, long h);
void space(long h, long row);
void everything(long row, long n);
long number(long n, long row, long term);
long coeff(long row);
long k(long row, long term);
bool prime_in_array(long array[], long n);
bool is_prime(long n);

/*========== MAIN FUNCTION ==========*/
int main() {
    /*inputs*/
    long n = cs1010_read_long();
    long h = cs1010_read_long();

    /*outputs*/
    start(n,h);
    return 0;
}

/*for each and every single row*/
void start(long n, long h) {
	for (long row = 1; row <= h; row += 1) {
		space(h, row);      //empty space		
		everything(row, n); //everything else		
		space(h, row);      //empty space
		printf("\n");       //end of line
	}
}

/*prints the amount of spacing that I need*/
void space(long h, long row) {
	for (long i = h-row; i > 0; i -= 1) {
		printf(" ");
	}
}

/*everything else*/
void everything(long row, long n) {
	//declaration
    long array[n];
	
	//fill all numbers of array
	for (long term = 0; term < n; term += 1) {
		array[term] = number(n,row,term);
	}

	//complete the whole row
	//for every single cell
	for (long cell = 0; cell < (2*row-1); cell += 1) {
		if (prime_in_array(array,n)) {
			printf("#");
		} else {
			printf(" ");
		}

		//add 1 to every element
		for (long term = 0; term < n; term += 1) {
			array[term] += 1;
		}
	}
}

/*gives me the number*/
long number(long n, long row, long term){
    return coeff(row)*n + k(row,term);
}

/*find the coefficient of n*/
long coeff(long row){
	long coeff = 0;
	for (long i=0; i<row; i+=1) {
		coeff += i;
	}
	return coeff;
}

/*find the constant term*/
long k(long row, long term) {
	return term*row+1;
}

/*checks for prime in an array*/
bool prime_in_array(long array[], long n) {
	for (long term=0; term<n; term+=1) {
		if (is_prime(array[term])) {
			return true;
		}
	}
	return false;
}

/*is this prime*/
bool is_prime(long n) {
    if (n<4) {
        return true;
    } else {
        for (long i=2; i <= n/2; i += 1) {
            if (n%i == 0) {
				return false;
			}
        }
        return true;
    }
}
