#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "gtest/gtest.h"
#include "bottyworld.h"

namespace {
 
    using namespace elma;
    using namespace bottyworld;

    TEST(BottyWorld,Construction) { 
        BottyWorld sw; 
        ASSERT_EQ("off", sw.current().name());
    }

    // More tests go here. You should aim to test every
    // method of every object, either directly or indirectly,
    // although testing user interfaces is notoriously 
    // difficult.

}