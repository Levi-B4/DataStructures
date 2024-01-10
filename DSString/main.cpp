#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_NO_POSIX_SIGNALS

#include <iostream>
#include "catch.hpp"

using namespace std;

// Test flag
#define TEST false


int runCatchTests(int argc, char* argv[]){
    // runs test.cpp using Catch2 lib
    return Catch::Session().run(argc, argv);
}

int main(int argc, char* argv[])
{
    // if testing run CATCH2 tests
    if(TEST){
        return runCatchTests(argc, argv);
    }

    cout << "Hello World!" << endl;
    return 0;
}
