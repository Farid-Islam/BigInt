

/*
    ***Bismillahir Rahmanir Rahim***
    Date and Time: 15-12-2020 : 23:04:30

    BigInt
    ------
    A Big integer class for c++.

    Released on: 29 December 2020
    Author: Md. Farid Islam and Sujon hasan
    Project on Github: https://github.com/Farid-Islam/BigInt/tree/main

*/

/*
    ===========================================================================
    BigInt
    ===========================================================================
    Definition for the BigInt class.
*/

#include <iostream>
#include <algorithm>


class BigInt
{
private:
    std::string bigInteger;
    short sign;

public:
    // Constructors:
    BigInt();
    BigInt(const BigInt &);
    BigInt(const long long &);
    BigInt(const std::string &);

    // Assignment operators:
    BigInt& operator=(const BigInt &);
    BigInt& operator=(const long long &);
    BigInt& operator=(const std::string &);

    // Unary arithmetic operators:
    BigInt operator+() const; // unary +
    BigInt operator-() const; // unary -

    // Binary arithmetic operators:
    BigInt operator+(BigInt obj);
    BigInt operator-(BigInt obj);
    BigInt operator*(BigInt obj);
    BigInt operator/(BigInt obj);
    BigInt operator%(BigInt obj);
    BigInt operator+(const long long &);
    BigInt operator-(const long long &);
    BigInt operator*(const long long &);
    BigInt operator/(const long long &);
    BigInt operator%(const long long &);
    BigInt operator+(const std::string &);
    BigInt operator-(const std::string &);
    BigInt operator*(const std::string &);
    BigInt operator/(const std::string &);
    BigInt operator%(const std::string &);

    // Arithmetic-assignment operators:
    BigInt operator+=(BigInt &obj);
    BigInt operator-=(BigInt &obj);
    BigInt operator*=(BigInt &obj);
    BigInt operator/=(BigInt &obj);
    BigInt operator%=(BigInt &obj);
    BigInt &operator+=(const long long &);
    BigInt &operator-=(const long long &);
    BigInt &operator*=(const long long &);
    BigInt &operator/=(const long long &);
    BigInt &operator%=(const long long &);
    BigInt &operator+=(const std::string &);
    BigInt &operator-=(const std::string &);
    BigInt &operator*=(const std::string &);
    BigInt &operator/=(const std::string &);
    BigInt &operator%=(const std::string &);

    // Increment and decrement operators:
    BigInt operator++();    // Pre-increment
    BigInt operator++(int); // Post-increment
    BigInt operator--();    // Pre-decrement
    BigInt operator--(int); // Post-decrement

    // Relational operators:
    bool operator>(BigInt &obj);
    bool operator<(BigInt &obj);
    bool operator==(BigInt &obj);
    bool operator>=(BigInt &obj);
    bool operator<=(BigInt &obj);
    bool operator!=(BigInt &obj);
    bool operator<(const long long &);
    bool operator>(const long long &);
    bool operator<=(const long long &);
    bool operator>=(const long long &);
    bool operator==(const long long &);
    bool operator!=(const long long &);
    bool operator<(const std::string &);
    bool operator>(const std::string &);
    bool operator<=(const std::string &);
    bool operator>=(const std::string &);
    bool operator==(const std::string &);
    bool operator!=(const std::string &);

    // I/O stream operators:
    friend std::istream &operator>>(std::istream &, BigInt &);
    friend std::ostream &operator<<(std::ostream &, const BigInt &);

    // Conversion functions:
    std::string to_string() const;
    int to_int() const;
    long to_long() const;
    long long to_long_long() const;
    
    //Function
    int length();

    // Logical operators overload
    bool operator&&(BigInt &obj);
    bool operator||(BigInt &obj);
    bool operator!();

    // Array subscript operator overload
    BigInt operator[](int index);

    ~BigInt();
};


/*
    ===========================================================================
    Utility functions
    ===========================================================================
*/

/*
    Swaping
    -------
    swaping s1 with s2 and len1 with len2
*/

void swaping(std::string &s1, std::string &s2, int &len1, int &len2)
{
    std::string tempStr = s1;
    s1 = s2;
    s2 = tempStr;

    int tempInt = len1;
    len1 = len2;
    len2 = tempInt;
}

/*
    strip_leading_zeroes
    --------------------
    Strip the leading zeroes from a number represented as a string.
*/

void strip_leading_zeroes(std::string &num)
{
    size_t i;
    for (i = 0; i < num.size(); i++)
    {
        if(num[i] != '0')
            break;
    }

    if(i == num.size())
        num = "0";
    else
        num = num.substr(i);
    
}

/*
    Compare with two string
    -----------------------
    swaping s1 with s2
    Note: only compare with magnitude value not sign
*/

int string_compare(std::string &s1, std::string &s2)
{
    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 > len2)
        return 1;
    else if (len1 < len2)
        return -1;
    else
    {
        return s1.compare(s2);
    }
}

/*
    is_valid_number
    ---------------
    Checks whether the given string is a valid integer.
*/

bool is_valid_number(const std::string &num)
{
    for (char digit : num)
    {
        if(digit < '0' or digit > '9')
            return false;
    }
    return true;
}

/*
    Return size of bigint
    ---------------------
*/

int BigInt::length()
{
    return this->bigInteger.length();
}

/*
    ===========================================================================
    Conversion functions for BigInt
    ===========================================================================
*/

/*
    to_string
    ---------
    Converts a BigInt to a string.
*/

std::string BigInt::to_string() const
{
    // prefix with sign if negative
    return this->sign == '-' ? "-" + this->bigInteger : this->bigInteger;
}

/*
    to_int
    ------
    Converts a BigInt to an int.
    NOTE: If the BigInt is out of range of an int, stoi() will throw an
    out_of_range exception.
*/

int BigInt::to_int() const
{
    return std::stoi(this->to_string());
}

/*
    to_long
    -------
    Converts a BigInt to a long int.
    NOTE: If the BigInt is out of range of a long int, stol() will throw an
    out_of_range exception.
*/

long BigInt::to_long() const
{
    return std::stol(this->to_string());
}

/*
    to_long_long
    ------------
    Converts a BigInt to a long long int.
    NOTE: If the BigInt is out of range of a long long int, stoll() will throw
    an out_of_range exception.
*/

long long BigInt::to_long_long() const
{
    return std::stoll(this->to_string());
}

/*
    Addition
    --------
    string = string + string
*/

std::string addition(std::string s1, std::string s2)
{

    /**
     * Complexity of addition function
     * 
     * Time complexity : O(n)
     * Space complexity: O(n)
     * 
     * Algorithm of addition function
     *      1. Input two string
     *      2. Calculate length of two string
     *      3. Make sure length of s1 is larger
     *      4. First loop will circulate by s1 length which is smaller
     *      5. Second loop will circulate by s2 length which is larger(Add remaining digit)
     *      6. Reverse the resultant string
     *      7. return the resultant string
     */

    // Calculate length of both string
    int len1 = s1.length();
    int len2 = s2.length();

    // Before proceeding further, make sure length of s1 is larger.
    if (len1 < len2)
    {
        swaping(s1, s2, len1, len2);
    }

    int diff = len1 - len2;

    // Take an empty string for storing result
    std::string result;

    // Initially take carry zero
    int carry = 0;

    for (int i = len2 - 1; i >= 0; i--)
    {
        // Do school mathematics, compute sum of current digit and carry
        int sum = ((s1[i + diff] - '0') + (s2[i] - '0') + carry);
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining digits of s1
    for (int i = len1 - len2 - 1; i >= 0; i--)
    {
        int sum = (s1[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining carry
    if (carry)
    {
        result.push_back(carry + '0');
    }

    // reverse resultant string
    reverse(result.begin(), result.end());

    return result;
}

/*
    subtraction
    --------
    string = string - string
*/

std::string subtraction(std::string s1, std::string s2)
{
    /**
     * Complexity of addition function
     * 
     * Time complexity : O(n)
     * Space complexity: O(n)
     * 
     * Algorithm of addition function
     *      1. Input two string
     *      2. Calculate length of two string
     *      3. Make sure s1 is larger than s2
     *      4. Calculate the difference
     *      5. circulate the loop by s2.length() and do school mathematics
     *      6. Circulate the another loop by s1.length() substraction exiesting value with carry
     *      7. Reverse the resultant string
     *      8. If result string head is zero then remove it
     *      9. Return the result string
     */

    // Calculate length of both string
    int len1 = s1.length();
    int len2 = s2.length();
    // cout << "\n\n";

    // Before proceeding further, make sure s1 is larger than s2.
    if (len1 < len2)
    {
        swaping(s1, s2, len1, len2);
    }
    else if (len1 == len2)
    {
        int val = s1.compare(s2);
        if (val == -1)
        {
            swap(s1, s2);
        }
        else if (val == 0)
        {
            return "0";
        }
    }

    int diff = len1 - len2;

    // Take an empty string for storing result
    std::string result;

    // Initially take carry zero
    int carry = 0;

    for (int i = len2 - 1; i >= 0; i--)
    {
        // Do school mathematics, compute sum of current digit and carry
        int n1 = (s1[i + diff] - '0');
        int n2 = (s2[i] - '0') + carry;

        if (n1 < n2)
        {
            n1 += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        result.push_back((n1 - n2) + '0');
    }

    // Add remaining digits of s1
    for (int i = (len1 - len2 - 1); i >= 0; i--)
    {
        int n1 = (s1[i] - '0');
        // int n2 = (s2[i] - '0') + carry;

        if (n1 < carry)
        {
            n1 += 10;
            // carry = 1;
            result.push_back((n1 - carry) + '0');
        }
        else
        {
            if (carry)
            {
                result.push_back((n1 - carry) + '0');
                carry = 0;
            }
            else
            {
                result.push_back(n1 + '0');
            }
        }
    }

    // reverse resultant string
    reverse(result.begin(), result.end());

    strip_leading_zeroes(result);

    return result;
}

/*
    Multiplication
    --------------
    string = string * string
*/

std::string multiplication(std::string s1, std::string s2)
{
    /**
     * Complexity of addition function
     * 
     * Time complexity : O(n2)
     * Space complexity: O(n)
     * 
     * Algorithm of addition function
     *      1. Input two string
     *      2. Calculate length of two string
     *      3. Multiplication by s1 all element with s2 all element
     *      4. resultant string will be reverse
     *      5. Zero insert will be every line after multiplication by increasing 1, except first element multiplication
     *      6. Extra Zero remove from num2 head
     *      7. Addition function will be call with parameter num1 and num2
     *      8. Addition result will be store num1 and this processing will be continue until loop break
     *      9. Return the final result string
     */

    // Calculate length of both string
    int len1 = s1.length();
    int len2 = s2.length();

    // Take two empty string for storing result
    std::string num1 = "0";
    std::string num2;

    // Initially take carry zero
    int carry = 0;
    int n1, sum;
    // zeroAdd
    int zeroAdd = 0;

    for (int i = len1 - 1; i >= 0; i--)
    {
        n1 = (s1[i] - '0');
        if (n1 == 0)
        {
            zeroAdd++;
            continue;
        }
        for (int j = len2 - 1; j >= 0; j--)
        {
            sum = n1 * (s2[j] - '0') + carry;
            num2.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry)
        {
            num2.push_back(carry + '0');
            carry = 0;
        }

        reverse(num2.begin(), num2.end());

        if (1 <= zeroAdd)
        {
            for (int i = 1; i <= zeroAdd; i++) // Can be use library function for this operation?
            {
                num2.push_back('0');
            }
        }

        // zero remove from head
        strip_leading_zeroes(num2);

        num1 = addition(num1, num2);
        num2.clear();
        zeroAdd++;
    }

    return num1;
}

/*
    Division
    --------
    string = string / string
*/

std::string division(std::string s1, std::string s2)
{
    /**
     * Complexity of addition function
     * 
     * Time complexity : O(n2)
     * Space complexity: O(n)
     * 
     * Algorithm of addition function
     *      1. Input two string
     *      2. Calculate length of two string
     *      3. Multiplication by s1 all element with s2 all element
     *      4. resultant string will be reverse
     *      5. Zero insert will be every line after multiplication by increasing 1, except first element multiplication
     *      6. Extra Zero remove from num2 head
     *      7. Addition function will be call with parameter num1 and num2
     *      8. Addition result will be store num1 and this processing will be continue until loop break
     *      9. Return the final result string
     */

    if (s2 == "0")
    {
        std::cout << "Can't divided by zero" <<std:: endl;
        exit(1);
    }
    else if (s1 == "0")
    {
        return "0";
    }

    int val = string_compare(s1, s2);

    if (val == -1)
        return "0";
    else if (val == 0)
        return "1";

    std::string result;

    for (int i = 0; i < s1.length(); i++)
    {
        result += '0';
    }

    std::string divisible;

    for (int i = 0; i < s1.length(); i++)
    {
        divisible += s1[i];
        strip_leading_zeroes(divisible);

        val = string_compare(divisible, s2);
        while (val >= 0)
        {
            divisible = subtraction(divisible, s2);
            result[i]++;
            val = string_compare(divisible, s2);
        }
    }

    strip_leading_zeroes(result);

    return result;
}

/*
    Remainder
    --------
    string = string % string
*/

std::string remainder(std::string s1, std::string s2)
{
    /**
     * Complexity of addition function
     * 
     * Time complexity : O(n2)
     * Space complexity: O(n)
     * 
     * Algorithm of addition function
     *      1. Input two string
     *      2. Calculate length of two string
     *      3. Multiplication by s1 all element with s2 all element
     *      4. resultant string will be reverse
     *      5. Zero insert will be every line after multiplication by increasing 1, except first element multiplication
     *      6. Extra Zero remove from num2 head
     *      7. Addition function will be call with parameter num1 and num2
     *      8. Addition result will be store num1 and this processing will be continue until loop break
     *      9. Return the final result string
     */

    if (s2 == "0")
    {
        std::cout << "Can't divided by zero" << std::endl;
        exit(1);
    }
    else if (s1 == "0")
    {
        return "0";
    }

    int val = string_compare(s1, s2);

    if (val == -1)
        return s1;
    else if (val == 0)
        return "0";

    std::string modValue;

    for (int i = 0; i < s1.length(); i++)
    {
        modValue += s1[i];
        strip_leading_zeroes(modValue);

        val = string_compare(modValue, s2);
        while (val >= 0)
        {
            modValue = subtraction(modValue, s2);
            val = string_compare(modValue, s2);
        }
    }

    return modValue;
}

/*
    Access digit
    ---------------
    return specific digit by given index
*/

BigInt BigInt::operator[](int index)
{
    if (this->bigInteger.length() <= index)
    {
        std::cout << "Error: Index out of bounds" << std::endl;
        exit(1);
    }

    std::string s;
    s += bigInteger[index];
    return BigInt(s);
}

/*
    Logical and
    -----------
    BigInt && BigInt
*/

bool BigInt::operator&&(BigInt &obj)
{
    BigInt zero("0");
    return (zero != *this) && (zero != obj);
}

/*
    Logical or
    -----------
    BigInt || BigInt
*/

bool BigInt::operator||(BigInt &obj)
{
    BigInt zero("0");
    return (zero != *this) || (zero != obj);
}

/*
    Logical not
    -----------
    !BigInt
*/

bool BigInt::operator!()
{
    BigInt zero("0");
    return !(zero != *this);
}

// Pre-increment
BigInt BigInt::operator++()
{
    BigInt one("1");
    *this = *this + one;
    return *this;
}
// Post-increment
BigInt BigInt::operator++(int)
{
    BigInt temp = *this;
    ++*this;
    return temp;
}
// Pre-decrement
BigInt BigInt::operator--()
{
    BigInt one("1");
    *this = *this - one;
    return *this;
}
// Post-decrement
BigInt BigInt::operator--(int)
{
    BigInt temp = *this;
    --*this;
    return temp;
}


/*
    istream operator overlaod
    -------------------------
    example: cin >> bigInt
*/

std::istream &operator>>(std::istream &input, BigInt &obj)
{
    std::string inputNum;

    input >> inputNum;

    if (inputNum.empty())
    {
        obj.bigInteger = "0";
        obj.sign = 1;
        return input;
    }

    obj = inputNum;

    return input;
}

/*
    ostream operator overlaod
    -------------------------
    example: std::cout << bigInt
*/

std::ostream &operator<<(std::ostream &output, const BigInt &obj)
{
    if (obj.sign == -1)
        std::cout << "-";

    output << obj.bigInteger;

    return output;
}

/*
    ===========================================================================
    Constructors
    ===========================================================================
*/

/*
    Default constructor
    -------------------
*/

BigInt::BigInt()
{
    bigInteger = "0";
    sign = 1;
}

/*
    Copy constructor
    ----------------
*/

BigInt::BigInt(const BigInt &num)
{
    bigInteger = num.bigInteger;
    sign = num.sign;
}

/*
    String to BigInt
    ----------------
*/

BigInt::BigInt(const std::string &num)
{
    if(num[0] == '+' or num[0] == '-')// check for sign
    {   
        std::string magnitude = num.substr(1);
        if(is_valid_number(magnitude))
        {
            bigInteger = magnitude;
            sign = (num[0] == '+') ? 1 : -1;
        }
        else
        {
            throw std::invalid_argument("Expected an integer, got \'" + num + "\'");
        }        
    }
    else// if no sign is specified
    {
        if(is_valid_number(num))
        {
            bigInteger = num;
            sign = 1; // positive by default
        }
        else
        {
            throw std::invalid_argument("Expected an integer, got \'" + num + "\'");
        }
        
    }

    strip_leading_zeroes(bigInteger);

    if(sign == -1 && bigInteger == "0")
        sign = 1;
}

/*
    Integer to BigInt
    -----------------
*/
BigInt::BigInt(const long long &ll)
{
    bigInteger = std::to_string(ll);
    if(ll < 0)
    {
        sign = -1;
        bigInteger = bigInteger.substr(1);
    }
    else
        sign = 1;
}

/*
    ===========================================================================
    Assignment operators
    ===========================================================================
*/


/*
    BigInt = BigInt
    ---------------
*/

BigInt& BigInt::operator=(const BigInt &num)
{
    bigInteger = num.bigInteger;
    sign = num.sign;

    return *this;
}

/*
    BigInt = Integer
    ----------------
*/

BigInt& BigInt::operator=(const long long &num)
{
    BigInt temp(num);
    bigInteger = temp.bigInteger;
    sign = temp.sign;

    return *this;
}

/*
    BigInt = String
    ---------------
*/

BigInt& BigInt::operator=(const std::string &num)
{
    BigInt temp(num);
    bigInteger = temp.bigInteger;
    sign = temp.sign;

    return *this;
}


/*
    ===========================================================================
    Unary arithmetic operators
    ===========================================================================
*/

/*
    +BigInt
    -------
    Returns the value of a BigInt.
*/

BigInt BigInt::operator+() const
{
    return *this;
}

/*
    -BigInt
    -------
    Returns the negative of a BigInt.
*/

BigInt BigInt::operator-() const
{
    BigInt temp;

    temp.bigInteger = bigInteger;
    if(bigInteger != "0")
    {
        if(sign == 1)
            temp.sign = -1;
        else
            temp.sign = 1;
    }

    return temp;
}




/*
    ===========================================================================
    Binary arithmetic operators
    ===========================================================================
*/

/*
    BigInt + BigInt
    ---------------
*/

BigInt BigInt::operator+(BigInt obj)
{
    BigInt object;

    if (this->sign == obj.sign)
    {
        std::string result = addition(this->bigInteger, obj.bigInteger);
        // Create a new return type object by given result string
        object.bigInteger = result;
        if (sign == 1)
            object.sign = 1;
        else
            object.sign = -1;
    }
    else
    {
        std::string result = subtraction(this->bigInteger, obj.bigInteger);
        // Create a new return type object by given result string
        object.bigInteger = result;

        int val = string_compare(this->bigInteger, obj.bigInteger);

        if (val == 1)
        {
            object.sign = this->sign;
        }
        else if (val == -1)
        {
            object.sign = obj.sign;
        }
        else
        {
            object.sign = 1;
        }
    }

    if (object.bigInteger == "0")
        object.sign = 1;

    return object;
}

/*
    BigInt - BigInt
    ---------------
*/

BigInt BigInt::operator-(BigInt obj)
{
    // sign changed
    obj.sign *= -1;

    BigInt object;

    if (this->sign == obj.sign)
    {
        std::string result = addition(this->bigInteger, obj.bigInteger);
        // Create a new return type object by given result string
        object.bigInteger = result;
        if (sign == 1)
            object.sign = 1;
        else
            object.sign = -1;
    }
    else
    {
        std::string result = subtraction(this->bigInteger, obj.bigInteger);
        // Create a new return type object by given result string
        object.bigInteger = result;

        int val = string_compare(this->bigInteger, obj.bigInteger);

        if (val == 1)
        {
            object.sign = this->sign;
        }
        else if (val == -1)
        {
            object.sign = obj.sign;
        }
        else
        {
            object.sign = 1;
        }
    }

    if (object.bigInteger == "0")
        object.sign = 1;

    return object;
}

/*
    BigInt - BigInt
    ---------------
*/

BigInt BigInt::operator*(BigInt obj)
{
    std::string result = multiplication(this->bigInteger, obj.bigInteger);

    BigInt object;

    object.bigInteger = result;

    if (result == "0")
    {
        // object.bigInteger = "0";
        object.sign = 1;
    }
    else
    {
        object.sign = this->sign * obj.sign;
    }

    return object;
}

/*
    BigInt / BigInt
    ---------------
*/

BigInt BigInt::operator/(BigInt obj)
{
    std::string resultString = division(this->bigInteger, obj.bigInteger);
    BigInt resultObject;

    resultObject.bigInteger = resultString;

    if (resultString == "0")
        resultObject.sign = 1;
    else
        resultObject.sign = this->sign * obj.sign;

    return resultObject;
}

/*
    BigInt % BigInt
    ---------------
*/

BigInt BigInt::operator%(BigInt obj)
{
    std::string resultString = remainder(this->bigInteger, obj.bigInteger);
    BigInt resultObject;

    resultObject.bigInteger = resultString;

    if (resultString == "0")
        resultObject.sign = 1;
    else
        resultObject.sign = this->sign;

    return resultObject;
}


/*
    BigInt + Integer
    ----------------
*/

BigInt BigInt::operator+(const long long &num)
{
    return *this + BigInt(num);
}

/*
    Integer + BigInt
    ----------------
*/

BigInt operator+(const long long &lhs, const BigInt &rhs)
{
    return BigInt(lhs) + rhs;
}

/*
    BigInt - Integer
    ----------------
*/

BigInt BigInt::operator-(const long long &num)
{
    return *this - BigInt(num);
}

/*
    Integer - BigInt
    ----------------
*/

BigInt operator-(const long long &lhs, const BigInt &rhs)
{
    return BigInt(lhs) - rhs;
}

/*
    BigInt * Integer
    ----------------
*/

BigInt BigInt::operator*(const long long &num)
{
    return *this * BigInt(num);
}

/*
    Integer * BigInt
    ----------------
*/

BigInt operator*(const long long &lhs, const BigInt &rhs)
{
    return BigInt(lhs) * rhs;
}

/*
    BigInt / Integer
    ----------------
*/

BigInt BigInt::operator/(const long long &num)
{
    return *this / BigInt(num);
}

/*
    Integer / BigInt
    ----------------
*/

BigInt operator/(const long long &lhs, const BigInt &rhs)
{
    return BigInt(lhs) / rhs;
}

/*
    BigInt % Integer
    ----------------
*/

BigInt BigInt::operator%(const long long &num)
{
    return *this % BigInt(num);
}

/*
    Integer % BigInt
    ----------------
*/

BigInt operator%(const long long &lhs, const BigInt &rhs)
{
    return BigInt(lhs) % rhs;
}

/*
    BigInt + String
    ---------------
*/

BigInt BigInt::operator+(const std::string &num)
{
    return *this + BigInt(num);
}

/*
    String + BigInt
    ---------------
*/

BigInt operator+(const std::string &lhs, const BigInt &rhs)
{
    return BigInt(lhs) + rhs;
}

/*
    BigInt - String
    ---------------
*/

BigInt BigInt::operator-(const std::string &num)
{
    return *this - BigInt(num);
}

/*
    String - BigInt
    ---------------
*/

BigInt operator-(const std::string &lhs, const BigInt &rhs)
{
    return BigInt(lhs) - rhs;
}

/*
    BigInt * String
    ---------------
*/

BigInt BigInt::operator*(const std::string &num)
{
    return *this * BigInt(num);
}

/*
    String * BigInt
    ---------------
*/

BigInt operator*(const std::string &lhs, const BigInt &rhs)
{
    return BigInt(lhs) * rhs;
}

/*
    BigInt / String
    ---------------
*/

BigInt BigInt::operator/(const std::string &num)
{
    return *this / BigInt(num);
}

/*
    String / BigInt
    ---------------
*/

BigInt operator/(const std::string &lhs, const BigInt &rhs)
{
    return BigInt(lhs) / rhs;
}

/*
    BigInt % String
    ---------------
*/

BigInt BigInt::operator%(const std::string &num)
{
    return *this % BigInt(num);
}

/*
    String % BigInt
    ---------------
*/

BigInt operator%(const std::string &lhs, const BigInt &rhs)
{
    return BigInt(lhs) % rhs;
}


/*
    ===========================================================================
    Arithmetic-assignment operators
    ===========================================================================
*/

/*
    BigInt += BigInt
    -----------------
*/

BigInt BigInt::operator+=(BigInt &obj)
{
    *this = *this + obj;
    return *this;
}

/*
    BigInt -= BigInt
    -----------------
*/

BigInt BigInt::operator-=(BigInt &obj)
{
    *this = *this - obj;
    return *this;
}

/*
    BigInt *= BigInt
    -----------------
*/

BigInt BigInt::operator*=(BigInt &obj)
{
    *this = *this * obj;
    return *this;
}

/*
    BigInt /= BigInt
    -----------------
*/

BigInt BigInt::operator/=(BigInt &obj)
{
    *this = *this / obj;
    return *this;
}

/*
    BigInt %= BigInt
    -----------------
*/

BigInt BigInt::operator%=(BigInt &obj)
{
    *this = *this % obj;
    return *this;
}

/*
    BigInt += Integer
    -----------------
*/

BigInt &BigInt::operator+=(const long long &num)
{
    *this = *this + BigInt(num);

    return *this;
}

/*
    BigInt -= Integer
    -----------------
*/

BigInt &BigInt::operator-=(const long long &num)
{
    *this = *this - BigInt(num);

    return *this;
}

/*
    BigInt *= Integer
    -----------------
*/

BigInt &BigInt::operator*=(const long long &num)
{
    *this = *this * BigInt(num);

    return *this;
}

/*
    BigInt /= Integer
    -----------------
*/

BigInt &BigInt::operator/=(const long long &num)
{
    *this = *this / BigInt(num);

    return *this;
}

/*
    BigInt %= Integer
    -----------------
*/

BigInt &BigInt::operator%=(const long long &num)
{
    *this = *this % BigInt(num);

    return *this;
}

/*
    BigInt += String
    ----------------
*/

BigInt &BigInt::operator+=(const std::string &num)
{
    *this = *this + BigInt(num);

    return *this;
}

/*
    BigInt -= String
    ----------------
*/

BigInt &BigInt::operator-=(const std::string &num)
{
    *this = *this - BigInt(num);

    return *this;
}

/*
    BigInt *= String
    ----------------
*/

BigInt &BigInt::operator*=(const std::string &num)
{
    *this = *this * BigInt(num);

    return *this;
}

/*
    BigInt /= String
    ----------------
*/

BigInt &BigInt::operator/=(const std::string &num)
{
    *this = *this / BigInt(num);

    return *this;
}

/*
    BigInt %= String
    ----------------
*/

BigInt &BigInt::operator%=(const std::string &num)
{
    *this = *this % BigInt(num);

    return *this;
}


/*
    ===========================================================================
    Relational operators
    ===========================================================================
*/

/*
    BigInt > BigInt
    ----------------
*/

bool BigInt::operator>(BigInt &obj)
{
    if (sign != obj.sign)
    {
        return sign > obj.sign;
    }

    int val = string_compare(this->bigInteger, obj.bigInteger);

    if (val == 1)
    {
        if (sign == -1)
            return false;
        else
            return true;
    }
    else if (val == -1)
    {
        if (obj.sign == -1)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

/*
    BigInt < BigInt
    ----------------
*/

bool BigInt::operator<(BigInt &obj)
{
    if (sign != obj.sign)
    {
        return sign < obj.sign;
    }

    int val = string_compare(this->bigInteger, obj.bigInteger);

    if (val == 1)
    {
        if (sign == -1)
            return true;
        else
            return false;
    }
    else if (val == -1)
    {
        if (obj.sign == -1)
            return false;
        else
            return true;
    }
    else
    {
        return false;
    }
}

/*
    BigInt == BigInt
    ----------------
*/

bool BigInt::operator==(BigInt &obj)
{
    if (sign != obj.sign)
    {
        return false;
    }

    int val = string_compare(this->bigInteger, obj.bigInteger);

    if (val == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
    BigInt >= BigInt
    ----------------
*/

bool BigInt::operator>=(BigInt &obj)
{
    if (*this > obj)
        return true;
    else if (*this == obj)
        return true;
    else
        return false;
}

/*
    BigInt <= BigInt
    ----------------
*/

bool BigInt::operator<=(BigInt &obj)
{
    if (*this < obj)
        return true;
    else if (*this == obj)
        return true;
    else
        return false;
}

/*
    BigInt != BigInt
    ----------------
*/

bool BigInt::operator!=(BigInt &obj)
{
    if (*this == obj)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*
    BigInt == Integer
    -----------------
*/

bool BigInt::operator==(const long long &num)
{
    BigInt temp(num);
    return *this == temp;
}

/*
    Integer == BigInt
    -----------------
*/

bool operator==(const long long &lhs, const BigInt &rhs)
{
    BigInt temp1(lhs);
    BigInt temp2(rhs);
    return temp1 == temp2;
}

/*
    BigInt != Integer
    -----------------
*/

bool BigInt::operator!=(const long long &num)
{
    BigInt temp(num);
    return !(*this == temp);
}

/*
    Integer != BigInt
    -----------------
*/

bool operator!=(const long long &lhs, const BigInt &rhs)
{
    BigInt temp1(lhs);
    BigInt temp2(rhs);
    return temp1 != temp2;
}

/*
    BigInt < Integer
    ----------------
*/

bool BigInt::operator<(const long long &num)
{
    BigInt temp(num);
    return *this < temp;
}

/*
    Integer < BigInt
    ----------------
*/

bool operator<(const long long &lhs, const BigInt &rhs)
{
    BigInt temp1(lhs);
    BigInt temp2(rhs);
    return temp1 < temp2;
}

/*
    BigInt > Integer
    ----------------
*/

bool BigInt::operator>(const long long &num)
{
    BigInt temp(num);
    return *this > temp;
}

/*
    Integer > BigInt
    ----------------
*/

bool operator>(const long long &lhs, const BigInt &rhs)
{
    BigInt temp1(lhs);
    BigInt temp2(rhs);
    return temp1 > temp2;
}

/*
    BigInt <= Integer
    -----------------
*/

bool BigInt::operator<=(const long long &num)
{
    BigInt temp(num);
    return !(*this > temp);
}

/*
    Integer <= BigInt
    -----------------
*/

bool operator<=(const long long &lhs, const BigInt &rhs)
{
    BigInt temp1(lhs);
    BigInt temp2(rhs);
    return temp1 <= temp2;
}

/*
    BigInt >= Integer
    -----------------
*/

bool BigInt::operator>=(const long long &num)
{
    BigInt temp(num);
    return !(*this < temp);
}

/*
    Integer >= BigInt
    -----------------
*/

bool operator>=(const long long &lhs, const BigInt &rhs)
{
    BigInt temp1(lhs);
    BigInt temp2(rhs);
    return temp1 >= temp2;
}

/*
    BigInt == String
    ----------------
*/

bool BigInt::operator==(const std::string &num)
{
    BigInt temp(num);
    return *this == temp;
}

/*
    String == BigInt
    ----------------
*/

bool operator==(const std::string &lhs, const BigInt &rhs)
{
    BigInt temp1(lhs);
    BigInt temp2(rhs);
    return temp1 == temp2;
}

/*
    BigInt != String
    ----------------
*/

bool BigInt::operator!=(const std::string &num)
{
    BigInt temp(num);
    return !(*this == temp);
}

/*
    String != BigInt
    ----------------
*/

bool operator!=(const std::string &lhs, const BigInt &rhs)
{
    BigInt temp1(lhs);
    BigInt temp2(rhs);
    return temp1 != temp2;
}

/*
    BigInt < String
    ---------------
*/

bool BigInt::operator<(const std::string &num)
{
    BigInt temp(num);
    return *this < temp;
}

/*
    String < BigInt
    ---------------
*/

bool operator<(const std::string &lhs, const BigInt &rhs)
{
    BigInt temp1(lhs);
    BigInt temp2(rhs);
    return temp1 < temp2;
}

/*
    BigInt > String
    ---------------
*/

bool BigInt::operator>(const std::string &num)
{
    BigInt temp(num);
    return *this > temp;
}

/*
    String > BigInt
    ---------------
*/

bool operator>(const std::string &lhs, const BigInt &rhs)
{
    BigInt temp1(lhs);
    BigInt temp2(rhs);
    return temp1 > temp2;
}

/*
    BigInt <= String
    ----------------
*/

bool BigInt::operator<=(const std::string &num)
{
    BigInt temp(num);
    return !(*this > temp);
}

/*
    String <= BigInt
    ----------------
*/

bool operator<=(const std::string &lhs, const BigInt &rhs)
{
    BigInt temp1(lhs);
    BigInt temp2(rhs);
    return temp1 <= temp2;
}

/*
    BigInt >= String
    ----------------
*/

bool BigInt::operator>=(const std::string &num)
{
    BigInt temp(num);
    return !(*this < temp);
}

/*
    String >= BigInt
    ----------------
*/

bool operator>=(const std::string &lhs, const BigInt &rhs)
{
    BigInt temp1(lhs);
    BigInt temp2(rhs);
    return temp1 >= temp2;
}

BigInt::~BigInt()
{
}