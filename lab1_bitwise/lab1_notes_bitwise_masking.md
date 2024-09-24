# Noah Vario
## Practice
### 1
~0x102
0x102 -> 0001 0000 0010 -> ~ ->  1110 1111 1101 -> 0xEFD

### 2
0xABC & 0x411
1010 1011 1100 &
0100 0001 0001
______________
0000 0001 0000

0x010

### 3
0xABC | 0x411

1010 1011 1100 |
0100 0001 0001
______________
1110 1011 1101

### 4
0x102030 & 0x00FF00         simplify by avoiding binary conversion

102030
00FF00 mask
______
002000 -> 0x002000

# Shifting

## Shifts bits to the lef "<<"

10111001 << 2
111001 00 (deletes 2 leftmost and pads the right with 00)

shift by 1 with no overflow multiplies the num by 2

## Right shift x >> y
shifts each bit in x to the right by y, discards y bits on the right

Padding with 0's is logical shift, arithmetic shift fills blank spaces by the MSB 
1010101 is 1
0101010 is 0

## Practice 2
### 1
0xF3 << 2
1111 0011 << 2
1100 1100
0xCC

### 2
0x9A >> 3
1001 1010 >> 3
0001 0011
0x13

### 3
0x9A >> 3
1001 1010 >> 3
1111 0011
0xF3

## Bit masking
unisgned j stores the value 0x1A35B127

define a mask to extract the most significant byte, first 8 bits

0x1A35B127
0xFF000000

### 1
write C code to store the extracted value in another variable (unsigned int)

unsigned int var1 = 0x1A35B127
unsigned int mask = 0xFF000000
unsigned int var2 = (var1 & mask)>>24

Mask takes away the first byte by using the & operator and then shifting to the right to get rid of extra 0's

### 2
assume an integer j that stores the value 0x1A35B127

set the least significant byte of j to all 1s and leaving other bits unchanged

int j = 0x1A35B127
int k = j | 0x000000FF
