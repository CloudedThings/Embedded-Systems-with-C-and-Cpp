 <h3 align="center">Convert HEX Big Endian to Little Endian and extract middle 8 bits</h3>



  <p align="center">
  <br />
  <br />
 </p>

<details open="open">

 <summary><h2 style="display: inline-block">About the project</h2></summary>
   <ul>
<ol>
​    <li><a href="#steps">Steps</a></li>
​    <li><a href="#files">Files</a></li>
​	  <li><a href="#acknowledgements">Acknowledgements</a></li>
</ol>
</details>

**About The Project**



Program reads in a sample .dat file with some hardcoded numbers between 0 and 65535. First it represents the values as 16 bit binary,  Big Endian HEX's and it's decimal values. Then it converts the values to it's Little Endian representation and corresponding new 16 bit binary and decimal values. The values are stored into a file in the process using fstream.  In next step the middle 8 bits are extracted from the Little Endian and theirs representation are shown in the console and saved to a file.

 **Steps**

1. Program reads in values from sample file and stores those values as unsigned short.

2. [bin_str16(unsigned short n)]  - First it converts the unsigned short number to 16-bits binary representation of that value and returns string to the console

3. [to_hex(unsigned short x)] - that method takes the value and return its HEX Big Endian representation as string

4. [toLittleEndian(unsigned short big)] - that's where the Big Endian is converted to Little Endian, in order to do that the value of **big** is masked with HEX value **0xFF** (1111 1111) so when applied it gives the lowest 8 bits from **big** then bits are shifted 8 bits to left. On the other side of **OR** operator **big** value is masked with 0xFF00 (1111 1111 0000 0000) which also return the lowest bits from **big** and then shifts them 8 bits to right. Then **OR** operator performs operation on those two values and returns the difference (1 values) of the bites on the left and right side of the operator. Example:

   ```c++
   unsigned short value: 111
   
   0000 0000 0110 1111 - binary value of 111
   
   1111 1111                     - mask
   
   0110 1111 1111 1111 - after << 8 bit shift
   
   0000 0000 0110 1111 - binary value of 111
   
   1111 1111 0000 0000 - mask on the right side of **OR**
   
   0000 0000 1111 1111 - after >> 8
   
   0110 1111 1111 1111 **OR** 0000 0000 1111 1111 = 0110 1111 0000 0000
   ```

   

5. Program returns then the new 16 bit binary representation of the result of call to **toLittleEndian()** , then it represents that binary as HEX this time its Little Endian.

6. In next step **extractToChar(unsigned short value, int begin, int end)** takes the converted value of LittleEndian and masks it with the values that represents the beginning of the 5th bit and up to 13th bit (so the middle 8b bits). Result of the extraction is saved to **8bitExtract.dat** file that includes the size of that value, its decimal value and HEX representation for testing.



**Files**

* [test.dat](test.dat) - file used as source for the input values

* [littleEndian.dat](littleEndian.dat) - log file with the result of the conversion

* [8bitExtract.dat](8bitExtract.dat) - log file with the result of extraction of middle 8 bits

**Acknowledgements**



* School: [KYH](https://kyh.se/utbildningar/internet-of-things/)

* Teacher: [GitHub](https://github.com/KYH-Gothenburg)
