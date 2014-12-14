// Copyright 2014 Paul Eduard

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/merge-sort-application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class AppTest : public ::testing::Test {
 protected:
    virtual void SetUp() {
        args.clear();
    }
    // virtual void TearDown() {}

    void Act(vector<string> args_) {
        vector<const char*> starts;
        starts.push_back("appname");

        for (size_t i = 0; i < args_.size(); ++i) {
            starts.push_back(args_[i].c_str());
        }
        const char** argv = &starts.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    SortApplication app_;
    string output_;
    vector<string> args;
};

TEST_F(AppTest, Do_Print_Help_Without_Arguments) {
    Act(args);

    Assert("This is a sort application\\..*");
}

TEST_F(AppTest, Is_Checking_Number_Of_Arguments) {
    args = {"1"};

    Act(args);

    Assert("ERROR: Should be 2 or more arguments\\..*");
}

TEST_F(AppTest, Can_Detect_Wrong_Number_Format) {
    args = {"1.0", "1"};

    Act(args);

    Assert("Wrong number of elements format!.*");
}

TEST_F(AppTest, Can_Detect_Wrong_Number_Format2) {
    args = {"2", "1", "3.0"};

    Act(args);

    Assert("Wrong numbers format!.*");
}

TEST_F(AppTest, Can_Detect_Wrong_Number_Format3) {
    args = {"2", "1", "..."};

    Act(args);

    Assert("Wrong numbers format.*");
}

TEST_F(AppTest, Can_Detect_Wrong_Number_Of_Elements) {
    args = {"3", "1", "2"};

    Act(args);

    Assert("Wrong number of elements!.*");
}

TEST_F(AppTest, Can_Sort) {
    args = {"4", "3", "1", "2", "0"};

    Act(args);

    Assert("Result: 0 1 2 3 .*");
}
