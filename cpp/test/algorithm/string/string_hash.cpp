#define CATCH_CONFIG_MAIN
#include "third_party/catch.hpp"
#include "algorithm/string/string_hash.hpp"

#include <iostream>

TEST_CASE("Base cases", "[string][string_hash]") {
   REQUIRE(compute_hash("")== 0); 
   REQUIRE(compute_hash(" ")== 0); 
   REQUIRE(compute_hash("a")== 1l);
   REQUIRE(compute_hash("ab")== 107); 
   REQUIRE(compute_hash("hello world")== 131579636);
}

TEST_CASE("Lowercase Only", "[string][string_hash]") {
    REQUIRE(compute_hash("test string")==150099743);
    REQUIRE(compute_hash("repeating repeating repeating repeating repeating repeating repeating repeating")==296093176);
    REQUIRE(compute_hash("helloworldthisisalongstringwithrandomwordsandmorewordandmoreandmoreandrepeatingwordsgoingonforareallylongtime")==774447806);
}

TEST_CASE("Uppercase Only", "[string][string_hash]") {
    REQUIRE(compute_hash("TEST STRING")==-644093479);
    REQUIRE(compute_hash("REPEATING REPEATING REPEATING REPEATING REPEATING REPEATING REPEATING REPEATING")==-293901091);
    REQUIRE(compute_hash("HELLOWORLDTHISISALONGSTRINGWITHRANDOMWORDSANDMOREWORDANDMOREANDMOREANDREPEATINGWORDSGOINGONFORAREALLYLONGTIME")==-13826066);
}

TEST_CASE("Mixed", "[string][string_hash]") {
    REQUIRE(compute_hash("tEst StrIng")==692609635);
    REQUIRE(compute_hash("RepeatinG rePEATiNg rEPeaTing RepEaTing rEPeating REpeating repeating repeating")==935097315);
    REQUIRE(compute_hash("HelLowoRldThiSisaLongstrINGWITHRandomwordsandmorewordandmoreandmoreandrepeatingwordsgoingonforareallylongtime")==452752606);
}


