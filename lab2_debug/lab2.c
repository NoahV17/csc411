int main() {
    // 8-bit 2's compliment numbers
    char a = 10;
    char b = -10;

    // 16-bit 2's compliment numbers
    short int sa = a;
    short int sb = b;

    // 32-bit 2's compliment numbers
    int ia = a;
    int ib = b;

    return 0;
}
// compile with: gcc -g -o prog lab2.c (-g gives debug info)
// to use dubugger lldb ./prog, add breakpoint "b main", run, then next to step through
// p/x (variable name) t print var in hex
// p &a prints the address of a
// x prints the value at that address
// info
// LOOKUP LLDB COMMANDS
// 