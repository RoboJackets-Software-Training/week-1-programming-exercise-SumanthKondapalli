#include <iostream>

int main()
{
    // Part 2: Palindrome Check

    // Input string from command-line
    std::string str;
    std::cout << "Enter String:" << std::endl;
    std::cin >> str;

    // Palindrome Check
    // WRITE YOUR PALINDROME CHECK HERE
    std::string reverseString;
    for (int i = str.size() - 1; i >= 0; i--)
    {
    	reverseString.push_back(str[i]);
    }

    if (str == reverseString)
    {
    	std::cout << str << " is a palindrome" << std::endl;
    }
    else
    {
    	std::cout << str << " is NOT a palindrome" << std::endl;
    }
}
