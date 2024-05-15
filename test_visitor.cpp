#include "gtest/gtest.h"

// Тестирование ConcreteVisitor1
class ConcreteVisitor1Test : public ::testing::Test {
protected:
    ConcreteVisitor1 visitor;
    ConcreteElementA elementA;
};

TEST_F(ConcreteVisitor1Test, VisitElementA) {
    testing::internal::CaptureStdout();
    elementA.accept(visitor);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Concrete Visitor 1: Element A visited.\n");
}

// Тестирование ConcreteElementA
class ConcreteElementATest : public ::testing::Test {
protected:
    ConcreteElementA elementA;
    ConcreteVisitor1 visitor;
};

TEST_F(ConcreteElementATest, AcceptVisitor) {
    testing::internal::CaptureStdout();
    elementA.accept(visitor);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Concrete Visitor 1: Element A visited.\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

