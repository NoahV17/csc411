// DISCLOSURE: This code was written by myself with the assistance 
//             of github copilot for help with value calculations
//             and printing in the format the autograder was asking for

// <exp>     Number of bits for the exponent
// <frac>    Number of bits for the fraction
// <output>  Options for displaying the output
//           - 's' for special numbers
//           - 'd' for denormalized values
//           - 'n' for normalized values
//           - 'a' for all values

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Functions for parsing
void generateFloatingPointValues(int expBits, int fracBits, char outputOption);
void printBinaryRepresentation(unsigned int value, int bits);
void printFloatingPointValue(unsigned int sign, unsigned int exponent, unsigned int fraction, int expBits, int fracBits, char outputOption);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <exp> <frac> <output>\n", argv[0]);
        return 1;
    }

    int expBits = atoi(argv[1]);
    int fracBits = atoi(argv[2]);
    char outputOption = argv[3][0];

    // Calls the function that runs through the input values
    generateFloatingPointValues(expBits, fracBits, outputOption);

    return 0;
}

void generateFloatingPointValues(int expBits, int fracBits, char outputOption) {
    unsigned int maxExponent = (1 << expBits) - 1;
    // Finds both the max exponent and fraction by shifting bits to essentially fill that many bits
    // ex 1 << 3 = 1000 = 8, 8 - 1 = 7 = 111
    unsigned int maxFraction = (1 << fracBits) - 1;
    
    // Runs the loop once with the first bit 0 and then 1 (positive then negative)
    for (unsigned int sign = 0; sign <= 1; sign++) {
        // Runs through all of the possible values for the exponent
        for (unsigned int exponent = 0; exponent <= maxExponent; exponent++) {
            // Runs through all of the possible values for the fraction
            for (unsigned int fraction = 0; fraction <= maxFraction; fraction++) {
                // Goes through and if the output option gets matched it will print the value
                if (outputOption == 'a') {
                    // If a it prints no matter what (all values)
                    printFloatingPointValue(sign, exponent, fraction, expBits, fracBits, outputOption);
                } 
                // If the option is s it prints only if the exponent is the max (all 1's)
                else if (outputOption == 's' && exponent == maxExponent) {
                    printFloatingPointValue(sign, exponent, fraction, expBits, fracBits, outputOption);
                } 
                // If the option is d it prints only if the exponent is 0's
                else if (outputOption == 'd' && exponent == 0) {
                    printFloatingPointValue(sign, exponent, fraction, expBits, fracBits, outputOption);
                } 
                // If the option is n it prints only if the exponent is not special or denormalized
                else if (outputOption == 'n' && exponent != 0 && exponent != maxExponent) {
                    printFloatingPointValue(sign, exponent, fraction, expBits, fracBits, outputOption);
                }
            }
        }
    }
}

void printBinaryRepresentation(unsigned int value, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
}

void printFloatingPointValue(unsigned int sign, unsigned int exponent, unsigned int fraction, int expBits, int fracBits, char outputOption) {
    // no new lines prints the whole binary representation
    printf("%d", sign);
    printBinaryRepresentation(exponent, expBits);
    printBinaryRepresentation(fraction, fracBits);
    
    // determine if number is special, if not, it is normalized
    if (exponent == (1 << expBits) - 1) { // max exponent
        if (fraction == 0) {
            // If the fraaction is 0 then this is a type of inf
            if (sign == 1) {
                printf(" -inf\n");
            } else {
                printf(" inf\n");
            }
        } else {
            printf(" nan\n");
        }
    }
    // Denormalized values
    else if (exponent == 0) {
        if (fraction == 0) {
            if (sign == 1) {
                printf(" -0.0\n");
            } else {
                printf(" 0.0\n");
            }
        } else {
            // Calculate the bias and the decimal value
            int bias = (1 << (expBits - 1)) - 1;
            double decimalValue = (double)fraction / (1 << fracBits) * pow(2, 1 - bias);
            if (sign) {
                decimalValue = -decimalValue;
            }
            printf(" %g\n", decimalValue);
        }
    } 
    // Normalized
    else {
        // Calculate and print the decimal representation for normalized values
        int bias = (1 << (expBits - 1)) - 1;
        double decimalValue = (1 + (double)fraction / (1 << fracBits)) * pow(2, (int)exponent - bias);
        if (sign) {
            decimalValue = -decimalValue;
        }
        printf(" %.10f\n", decimalValue);
    }
}
// If the exponent is the max, aka all 1's we know it is special
