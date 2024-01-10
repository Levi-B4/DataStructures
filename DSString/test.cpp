#include "catch.hpp"
#include "dsstring.h"

#include <cstring>
#include <type_traits>

using std::string;

TEST_CASE("DSString class", "[DSString]"){
    SECTION("Tests not implimented"){
        REQUIRE(false);
    }
/*
    DSString s[3];
    s[0] = DSString("some string");
    s[1] = DSString("string2");
    s[2] = DSString("ssssss");

    SECTION("Equality operators"){
        REQUIRE(s[0] == DSString("some string"));
        REQUIRE(!(s[0] == s[1]));
    }

    SECTION("Assignment Operator"){
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
