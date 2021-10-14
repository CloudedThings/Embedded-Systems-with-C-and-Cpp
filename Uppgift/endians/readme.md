Program reads in a sample .dat file with some hardcoded numbers between 0 and 65535.

1. [bin_str16(unsigned short n)]  - First it converts the unsigned short number to 16-bits representation as a string
2. [to_hex(unsigned short x)] - that method takes the value and return its HEX Big Endian representation as string
3. [toLittleEndian(unsigned short big)] - that's where the Big Endian is converted to Little Endian, in order to do that the value of **big** is masked with HEX value **0xFF** (1111 1111) so when applied it gives the lowest 8 bits from **big** then bits are shifted 8 bits to left. On the other side of **OR** operator **big** value is masked with 0xFF00 (1111 1111 0000 0000) which also return the lowest bits from **big** and then shifts them 8 bits to right. Then **OR** operator performs operation on those two values and returns the difference of the left bites.
4. Program returns then the new 16 bit representation of result of call to **toLittleEndian()** and as HEX.
5. In next step **extractToChar(unsigned short value, int begin, int end)** takes the converted value of LittleEndian and masks it with the values that represents the beginning of the 5th bit and up to 13th bit (so the middle 8b bits). Result of the extraction is saved to **8bitExtract.dat** file that includes the size of that value, its decimal value and HEX representation for testing.

