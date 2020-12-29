<p align="center">
  <img alt="BigInt" src="image1.jpg">
</p>
<h3 align="center">A Big Integer Class for C++</h3>

---

This is a Big Integer Class, implemented in C++, for handling very large numbers, or numbers greater than **unsigned long long int** in a **64 bit** implementation. So, it can easily operate on numbers **greater than 10^18**.


## Usage

Just include the file as a preprocessor directive, like : #include "name"
where name denotes your filename, the name you saved for this Big Int file. Also, ensure that you keep it in the same directory as your working file, else you have to write the complete path in that place.

1. Download the BigInt.cpp source file. Then `#include` it in your code:
    ```c++
    #include "BigInt.cpp"   // the actual path may vary
    ```

1. Create objects of the `BigInt` class, and do what you got to do!
    ```c++
    BigInt big1 = 1234567890, big2;
    big2 = "9876543210123456789098765432101234567890";

    std::cout << big1 * big2 * 123456 << "\n";
    // Output: 1505331490682966620443288524512589666204282352096057600
    ```

## Features

### Operators

* #### Assignment: `=`
  The second operand can either be a `BigInt`, an integer (up to `long long`)
  or a string (`std::string` or a string literal).
  ```c++
  big1 = 1234567890;
  big1 = "123456789012345678901234567890";
  big1 = big2;
  ```

* #### Unary arithmetic: `+`, `-`
  ```c++
  big1 = +big2;   // doesn't return the absolute value
  big1 = -big2;
  ```

* #### Binary arithmetic: `+`, `-`, `*`, `/`, `%`
  One of the operands has to be a `BigInt` and the other can be a `BigInt`, an
  integer (up to `long long`) or a string (`std::string` or a string literal).
  ```c++
  big1 = big2 + 1234567890;
  big1 = big2 - "123456789012345678901234567890";
  big1 = big2 * big3;
  big1 = 1234567890 / big2;
  big1 = "123456789012345678901234567890" % big2;
  ```

* #### Arithmetic-assignment: `+=`, `-=`, `*=`, `/=`, `%=`
  The second operand can either be a `BigInt`, an integer (up to `long long`)
  or a string (`std::string` or a string literal).
  ```c++
  big1 += big2;
  big1 -= 1234567890;
  big1 *= "123456789012345678901234567890";
  big1 /= big2;
  big1 %= 1234567890;
  ```

* #### Increment and decrement: `++`, `--`
  ```c++
  big1 = ++big2;   // pre-increment
  big1 = --big2;   // pre-decrement

  big1 = big2++;   // post-increment
  big1 = big2--;   // post-decrement
  ```

* #### Relational: `<`, `>`, `<=`, `>=`, `==`, `!=`
  One of the operands has to be a `BigInt` and the other can be a `BigInt`, an
  integer (up to `long long`) or a string (`std::string` or a string literal).
  ```c++
  if (big1 < 1234567890
      or big1 > "123456789012345678901234567890"
      or big1 <= big2
      or 1234567890 >= big1
      or "123456789012345678901234567890" == big1
      or big1 != big3) {
      ...
  }
  ```

* #### I/O stream: `<<`, `>>`
  ```c++
  std::cout << big1 << ", " << big2 << "\n";
  output_file << big1 << ", " << big2 << "\n";

  std::cin >> big1 >> big2;
  input_file >> big1 >> big2;
  ```

### Functions

* #### Conversion: `to_string`, `to_int`, `to_long`, `to_long_long`
  Convert a `BigInt` to either a `string`, `int`, `long`, or `long long`.

  **Note**: If the `BigInt` is beyond the range of the target type, an
  [out_of_range exception][out_of_range-exception] is thrown.

  ```c++
  std::string str = big1.to_string();

  int var = big1.to_int();

  long var = big1.to_long();

  long long var = big1.to_long_long();
  ```
---

## Credit
This Big Integer class was created by [Farid Islam](https://www.facebook.com/farid.0point) and [Sujon Hasan](https://www.facebook.com/profile.php?id=100058892555448&_rdc=1&_rdr)