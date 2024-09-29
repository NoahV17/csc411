convert to normalized scientific
1111.1010 -> 1.1111010 * 2^3
0.0000010 -> 1.0 * 2^-6

convert a decimal to a fractional binary
.1 * 2 = 0.2
.2 * 2 = 0.4
.4 * 2 = 0.8
.8 * 2 = 1.6
.6 * 2 = 1.2     Cannot be represented in binary,
.2 * 2 = 0.4     the bits loop infinitely
.4 * 2 = 0.8
.8 * 2 = 1.6
.6 * 2 = 1.2

so
0.1 = 0.0001100110011....

IEEE 754 standard 32 bits
1 bit for sign           0 for positive, 1 for negative
8 bits for exponent      127 different exponent values
23 bits for fraction     aka mantissa used for fraction part

Double precision 64 bits
1 bit for sign
11 bits for exponent
52 bits for fraction/mantissa

Decimal -> Binary (IEEE 754) -> Decimal    (-1)^S * M * 2^E
Sign bit S, exponent E, mantissa M

Floating point categories
Denormalized numbers, very small, close to zero (exponent all 0s)
Special values, infinity, NaN, (exponenet all 1s)
Normalized numbers, the rest, larger values

E = e - bias
bias = 127 for 32 bit, 1023 for 64 bit

Practice
Assume a float F = 2024.0
Convert to fractional binary
11111101000.0000
Make it in form 1.xxx
1.1111101000 * 2^10
write M and frac
M =  1.111101000
frac = 11110100 0000000000000 (padding to hit 23 bits)
Write exp using E = exp - bias
E = 10 + 127 = 137 = 10001001
The final bit sequence
0 10001001 11110100000000000000000
sign exp   frac

Practice
Assume a float F = 0.5
Convert to fractional binary
0.1
Normalize
1.0 * 2^-1
M = 1.0
frac = 00000000000000000000000
E = -1 + 127 = 126 = 01111110
The final bit sequence
0 01111110 00000000000000000000000
0x3E000000





Practice for gradescope
#1 1.3125
.3125 * 2 = 0.625
.625 * 2 = 1.25
.25 * 2 = 0.5
.5 * 2 = 1.0
So 1.3125 = 1.0101
Then normalize
1.0101 * 2^0
M = 1.0101
frac = 01010000000000000000000
E = 0 + 127 = 127 = 01111111
The final bit sequence
0 01111111 01010000000000000000000
0x3F540000

#2 3.53125
3 -> 11
.53125 * 2 = 1.0625
.0625 * 2 = 0.125
.125 * 2 = 0.25
.25 * 2 = 0.5
.5 * 2 = 1.0
So 3.53125 = 11.1001
Normalize
1.11001 * 2^1
M = 1.11001
frac = 11001000000000000000000
E = 1 + 127 = 128 = 10000000
The final bit sequence
0 10000000 11001000000000000000000
0x40860000

