#include "catch.hpp"
#include "dsstring.h"

#include <cstring>
#include <type_traits>

#include <iostream>

#include <string>
using namespace std;

TEST_CASE("DSString class", "[DSString]"){


    SECTION("Equality operators"){
        DSString testString("some string");
        REQUIRE(testString == "some string");
    }
/*
    SECTION("Assignment Operator"){?
        DSString str;
        str = "stirng2";
        REQUIRE(str == s[1]);
    }

    SECTION("Substring function"){
        REQUIRE(s[0].substr(11) == "");
        REQUIRE(s[0].substr(0, 99) == s[0]);
        REQUIRE(s[0].substr(2,2) == "me");
    }

    SECTION("c_str function"){
        REQUIRE(s[0].c_str()[-1] == '\0');
        //REQUIRE(is_same_v<decltype(s[0].c_str()), const char*>);
    }

    SECTION("addition operator"){
    }
*/
}
