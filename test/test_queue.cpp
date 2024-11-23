
#include "queue.h"
#include <gtest.h>

TEST(Stack, can_create_non_empty_stack) {
    ASSERT_NO_THROW(Stack<int> S(7));
}
TEST(Stack, cant_create_stack_with_negative_length) {
    ASSERT_ANY_THROW(Stack<int> S(-7));
}

TEST(Stack, cant_create_stack_with_null_length) {
    ASSERT_ANY_THROW(Stack<int> S(0));
}

TEST(Stack, can_push_and_pop_element) {
    Stack <int> S(3);
    S.push(2);
    S.push(7);
    S.push(5);

    Stack <int> S_exp(2);
    S_exp.push(2);
    S_exp.push(7);

    S.pop();
    ASSERT_EQ(S,S_exp);
}
///
TEST(Stack, pop_return_element_before_last_element) {
    Stack <int> S(3);
    S.push(2);
    S.push(7);
    S.push(5);

    ASSERT_EQ(S.pop(), 7);
}

TEST(Stack, cant_pop_in_empty_stack) {
    Stack <int> S(1);
    ASSERT_ANY_THROW(S.pop());
}

TEST(Stack, can_pop_only_element) {
    Stack <int> S(1);
    S.push(3);
    ASSERT_NO_THROW(S.pop());
}

TEST(Stack, cant_push_full_stack) {
    Stack <int> S(3);
    S.push(2);
    S.push(7);
    S.push(5);
    ASSERT_ANY_THROW(S.push(8));
}

TEST(Stack, can_get_last_element) {
    Stack <int> S(3);
    S.push(2);
    S.push(7);
    S.push(5);
    ASSERT_EQ(S.top(), 5);
}

TEST(Stack, cant_get_last_element_in_empty_stack) {
    Stack <int> S(3);
    ASSERT_ANY_THROW(S.top());
}

TEST(Stack, can_get_size) {
    Stack <int> S(3);
    S.push(2);
    S.push(8);
    ASSERT_EQ(2, S.size());
}

TEST(Stack, can_get_size_in_empty_stack) {
    Stack <int> S(3);
    ASSERT_EQ(0, S.size());
}

TEST(Stack, empty_stack_return_true) {
    Stack <int> S(3);
    ASSERT_EQ(S.empty(), true);
}
TEST(Stack, non_empty_stack_return_false) {
    Stack <int> S(3);
    S.push(6);
    ASSERT_EQ(S.empty(), false);
}