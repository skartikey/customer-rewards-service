cmake_minimum_required(VERSION 3.10)
project(CustomerRewardsService)

set(CMAKE_CXX_STANDARD 17)

# Use FetchContent to download and build GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Add the source files for the main application and the test
add_executable(CustomerRewardsService RewardsService.cpp EligibilityService.cpp)
add_executable(RewardsServiceTest RewardsServiceTest.cpp RewardsService.cpp EligibilityService.cpp)

# Link the main application against GoogleTest and GoogleMock libraries
target_link_libraries(CustomerRewardsService 
                      gtest
                      gtest_main
                      gmock
                      gmock_main)

# Link the test executable against GoogleTest and GoogleMock libraries
target_link_libraries(RewardsServiceTest 
                      gtest
                      gtest_main
                      gmock
                      gmock_main)

# Add a custom target 'test' to run the tests
add_custom_target(test COMMAND RewardsServiceTest)
