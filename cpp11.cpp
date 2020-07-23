// Lambdas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include "Sample.h"
#include <cmath>
#include <regex>
#include <fstream>
#include <array>
#include <unordered_map>
#include <string>


void print() {
    std::cout << std::endl;
}
template<typename T, typename... Ts>
void print(T value, Ts... values) {
    std::cout << value << " ";
    print(values...);
}

template <class T>
void swap(T& a, T& b) {
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

int main()
{
    

    //Part 1: Lamba Expressions
    //declare data
    const auto width = 10;
    const auto height = 6;

    int area;

    //create lambda expression
    auto calculateArea = [&]() {
        area = width * height;
    };

    //invoke lambda
    calculateArea();
    std::cout << "Area: " << area << "\n";
    
    //Part 2: Containers and iterators

    std::vector<int> sequence = { 4, 3, 7, 2 , 8 };
    //Iterators are available by default with the language 
    for (std::vector<int>::iterator iter = sequence.begin(); iter != sequence.end(); iter++) {
        std::cout << *iter;
    }

    std::cout << "\n";

    //Just like the native implementation of fixed arrays, the length of a std::array must be known at compile time.
    std::array<int, 5> myArray = { 1, 2, 3, 4, 5 };

    std::unordered_map<std::string, int> dates;
    dates["Jan"] = 1;
    dates["Feb"] = 2;
    dates["Mar"] = 3;
    dates["Apr"] = 4;
    dates["May"] = 5;
    dates["Jun"] = 6;
    dates["Jul"] = 7;
    dates["Aug"] = 8;
    dates["Sep"] = 9;
    dates["Oct"] = 10;
    dates["Nov"] = 11;
    dates["Dec"] = 12;

    std::cout << "August: " << dates["Aug"];


    //Part 3: Smart Pointers

    std::shared_ptr<Sample> sp(new Sample);
    //Destructor automatically called after function invocation due to automatic garbage collection
    sp->foo();

    //Use shared pointer when allows for multiple pointers to point at a given resource. When the very last shared_ptr to a resource is destroyed, the resource will be deallocated. 
    //Use unique_ptr when you want a single pointer to an object that will be reclaimed when that single pointer is destroyed.
    std::unique_ptr<Sample> up(new Sample);
    up->foo();

    //Part 4: nullptr

    int* nil = nullptr;

    //Part 5: MultiThreading

    const int exponent = 4;
    const int base = 3;

  

    std::promise<int> promise;
    std::future<int> expResult = promise.get_future();



    std::thread([&]{
        int result = std::pow(base, exponent);
        promise.set_value_at_thread_exit(result);
    }).detach();

    std::cout << "Result from thread: " << expResult.get() << "\n";
    
    //Part 6 Regular Expressions

    const std::string fileRegexData = "regexdata.txt";
    std::regex pattern("s[a-z]+");

    std::ifstream infile;    
    infile.open("regexdata.txt");

    std::string fileStr((std::istreambuf_iterator<char>(infile)),
        std::istreambuf_iterator<char>());


    //std::find
    std::size_t found = fileStr.find("regex");
    if (found != std::string::npos)
        std::cout << "'regex' found at: " << found << '\n';

    std::smatch m;
    //Search
    if (std::regex_search(fileStr, m,pattern))
        std::cout << "Pattern found";

    std::cout << "pattern search result: ";
    for (auto x : m)
        std::cout << x << " ";



    // Part 7: Variadic Templates
    //Reference: https://lhcb.github.io/developkit-lessons/first-development-steps/05a-cpp11.html
    //Implementation of Python style print function

    print("\nPython style print");
    
    // Part 7: Move Semantics

    Sample a;
    Sample b;

    swap(a, b);

    a.foo();

    if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";

    std::cout << "C++ langauge supported = " << __cplusplus << "\n";


   
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
