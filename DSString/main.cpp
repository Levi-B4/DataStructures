#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_NO_POSIX_SIGNALS

#include "catch.hpp"

#include "dsstring.h"

using namespace std;

// Test flag
#define TEST true

// function for running tests
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

    return 0;
}
