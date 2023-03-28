
Mandatory
man 3 stdarg: https://linux.die.net/man/3/stdarg
    va_list ap;
    va_start(ap, last); 
        - initialise var arg list
    va_arg(ap, type); 
        - each call to va_arg() modifies ap so that the next call returns the next argument
    va_end(ap); 
        - clean up var arg list

Format tag prototypes: %[flags][width][.precision][length]specifier

Notes:
    - % indicates that the following characters specify a conversion specification
    - return value: number of characters printed (output error: return neg value)

Conversions / Specifiers: cspdiuxX%
    [x] c: char
    [x] s: string of char
    [ ] p: memory address
    [x] d: decimal int (same as %i for printf, but for scanf, %i auto detects the base)
    [x] i: dec / oct / hex int
    [x] u: unsigned int
    [x] x: hex int (lowercase: a-f)
    [x] X: hex int (lowercase: A-F)
    [ ] %

-----------------------------------------------------------------------------------------------
Bonus
Flags: 
    #: alternate forms of conversions (depends on conversion) (test with stdfunc?)
    0: zero filled
    -: left-justify int output (no sign: automatically right justified)
    +: forces a sign char ('+' or '-') to be displayed before the value
    space: if + int is passed, print: ' 42' | if - int is passed, print: '-42' (no change)

Minimum field-width
    - int
    - default padding: using spaces
    - if value > mfw: prints
    - pad with 0: place 0 before mfw specifier
        printf("%10f\n", item);  | output: 10.123040
        printf("%012f\n", item); | output: 00010.123040
