#include "catch.hpp"
#include "dsstring.h"

#include <type_traits>

TEST_CASE("DSString class", "[DSString]"){

    DSString* stringsArray[3];

    stringsArray[0] = new DSString("test1");
    stringsArray[1] = new DSString("yo");
    stringsArray[2] = new DSString();

    DSString testStr = "testStr";
    DSString nonPtrArray[1];
    nonPtrArray[0] = "nonPtr";

    SECTION("concatination operators"){
        REQUIRE((*stringsArray[0] += "yo") == "test1yo");
        *stringsArray[0] = "test1";

        REQUIRE((*stringsArray[1] += testStr) == "yotestStr");
        *stringsArray[1] = "yo";

        REQUIRE((*stringsArray[1] += 'x') == "yox");
        *stringsArray[1] = "yo";
    }

    SECTION("Comparison Operators"){
        REQUIRE(testStr == "testStr");
        REQUIRE(nonPtrArray[0] == "nonPtr");


        REQUIRE(*stringsArray[0] == "test1");
        //TODO: ERROR: may need to make comparison operators free functions rather than member functions
        //REQUIRE("yo" == *stringsArray[1]);
        REQUIRE(!(*stringsArray[0] == *stringsArray[1]));

        REQUIRE(!(*stringsArray[0] < "test1"));
        REQUIRE(*stringsArray[1] < *stringsArray[0]);

        REQUIRE(!(*stringsArray[0] > "test1"));
        REQUIRE(*stringsArray[0] > *stringsArray[1]);

        REQUIRE(*stringsArray[0] <= "test1");
        REQUIRE(*stringsArray[1] <= *stringsArray[0]);

        REQUIRE(*stringsArray[0] >= "test1");
        REQUIRE(*stringsArray[0] >= *stringsArray[1]);

        REQUIRE(*stringsArray[2] == "");
    }

    SECTION("Indexing"){
        REQUIRE((*stringsArray[0])[0] == 't');
        REQUIRE((*stringsArray[1])[1] == 'o');
        REQUIRE((*stringsArray[2])[0] == '\0');
    }

    SECTION("Substrings"){
        REQUIRE(stringsArray[0]->substring(1, 3) == "est");
        REQUIRE(stringsArray[1]->substring(0, 1) == "y");

        REQUIRE(stringsArray[0]->substring(3,0) == "");
        REQUIRE(stringsArray[0]->substring(stringsArray[0]->size() - 1, 3) == "");
        REQUIRE(stringsArray[0]->substring(0, 0) == "");


        REQUIRE(stringsArray[0]->substring(2, -5) == "tes");
        REQUIRE(stringsArray[0]->substring(2, -2) == "es");
        REQUIRE(stringsArray[0]->substring(0, -3) == "t");
        REQUIRE(stringsArray[0]->substring(stringsArray[0]->size() - 1, -2) == "t1");
    }

    SECTION("c_string"){
        REQUIRE(*stringsArray[0] == stringsArray[0]->c_str());
        REQUIRE(*stringsArray[0] == stringsArray[0]->c_str());
    }


    for(int i = 0; i < 3; i++){
        delete stringsArray[i];
    }
}
