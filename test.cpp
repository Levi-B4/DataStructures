#include "catch.hpp"
#include <type_traits>

#include "DSString/dsstring.h"
#include "DSVector/dsvector.h"

TEST_CASE("Data_Structures_Test", "[Data_Structures_Test]"){

/*
 *  String
 */

    DSString* stringsArray[3];

    stringsArray[0] = new DSString("test1");
    stringsArray[1] = new DSString("yo");
    stringsArray[2] = new DSString();

    DSString testStr = "testStr";

    DSString nonPtrArray[1];
    nonPtrArray[0] = "nonPtr";




    SECTION("String concatination operators"){
        REQUIRE((*stringsArray[0] += "yo") == "test1yo");
        *stringsArray[0] = "test1";

        REQUIRE((*stringsArray[1] += testStr) == "yotestStr");
        *stringsArray[1] = "yo";

        REQUIRE((*stringsArray[1] += 'x') == "yox");
        *stringsArray[1] = "yo";
    }

    SECTION("String Comparison Operators"){
        REQUIRE(testStr == "testStr");
        REQUIRE(nonPtrArray[0] == "nonPtr");


        REQUIRE(*stringsArray[0] == "test1");
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

    SECTION("String Indexing"){
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

 /*
 *  Vector
 */
    int numArray1[3] = {0, 1, 2};

    DSVector<int> numVect1(8);
    for(int element : numArray1){
        numVect1.pushBack(element);
    }

    DSVector<int> numVect1Copy = numVect1;

    int numArray2[3] = {3, 4, 5};

    DSVector<int> numVect2(3);
    for(int element : numArray2){
        numVect2.pushBack(element);
    }


    int numArray3[6] = {0, 1, 2, 3, 4, 5};
    DSVector<int> numVect3;
    for(int element : numArray3){
        numVect3.pushBack(element);
    }


    SECTION("Vector getters and setters"){
        // getters
        REQUIRE(numVect1.getNumIndexes() == 3);
        REQUIRE(numVect1.getCapacity() == 8);
        REQUIRE(numVect1.getResizeIncrement() == 8);

        // setters
        numVect1.setCapacity(9);
        numVect1.setResizeIncrement(10);
        REQUIRE(numVect1.getCapacity() == 9);
        REQUIRE(numVect1.getResizeIncrement() == 10);

        numVect1.setCapacity(8);
        numVect1.setResizeIncrement(8);
    }

    SECTION("Vector indexing"){
        REQUIRE(numVect1[0] == 0);
        REQUIRE(numVect1[2] == 2);
    }

    SECTION("Vector Comparison Operators"){
        REQUIRE(numVect1 == numVect1Copy);
        REQUIRE(numVect1 != numVect2);
    }

    SECTION("Vector Concatination"){
        numVect1 += numVect2;
        REQUIRE(numVect1 == numVect3);

        numVect1 = numVect1Copy;

        REQUIRE(numVect3 == (numVect1 + numVect2));

        REQUIRE(numVect1 == numVect1Copy);
    }
}