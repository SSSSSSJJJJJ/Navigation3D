#include "gtest/gtest.h"
GTEST_API_ int main(int argc,char **argv)
{
    //printf("Running main() from gtest_main.cc\n");
    //testing::AddGlobalTestEnvironment(new QtAppEnvironment(argc, argv));

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
