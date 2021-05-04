// Copyright 2021 Belik Julia

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/DepositCalc_app.h"

using std::string;
using std::vector;
using ::testing::internal::RE;

class DepositCalc_app_test : public ::testing::Test {
protected:
    void Act(vector<string> args_) {
        vector<const char*> options;
        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }
        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;
        output_ = app_(argc, argv);
    }
    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

private:
    DepositCalc_app app_;
    string output_;
};

TEST_F(DepositCalc_app_test, Test_Print_Help) {
    vector<string> args = {};
    Act(args);
    Assert("This is a deposit calc application\\..*");
}

TEST_F(DepositCalc_app_test, Test_Number_Of_Arguments) {
    vector<string> args = { "1", "2", "3", "4" };
    Act(args);
    Assert("Error: Should be 8 arguments\\..*");
}

TEST_F(DepositCalc_app_test, Test_Sum_Is_Negative) {
    vector<string> args = { "-1", "1", "1", "1", "1", "1", "0" };
    Act(args);
    Assert("Error: Sum must be positive\\..*");
}

TEST_F(DepositCalc_app_test, Test_Months_Is_Negative) {
    vector<string> args = { "1", "1", "-1", "1", "1", "1", "0" };
    Act(args);
    Assert("Error: Number of months must be positive\\..*");
}

TEST_F(DepositCalc_app_test, Test_Capitalization) {
    vector<string> args = { "1", "1", "1", "1", "1", "1", "9" };
    Act(args);
    Assert("Error: Wrong value\\..*");
}

TEST_F(DepositCalc_app_test, Test_Calculate_Deposit) {
    vector<string> args = { "700000", "12", "07", "2021", "8", "12", "0" };
    Act(args);
    Assert("Profitability= 756000\\..*");
}
