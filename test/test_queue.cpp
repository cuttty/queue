
#include "queue.h"
#include <gtest.h>

TEST(Queue, can_create_non_empty_queue) {
    ASSERT_NO_THROW(Queue<int> Q(7));
}
TEST(Queue, cant_create_queue_with_negative_length) {
    ASSERT_ANY_THROW(Queue<int> Q(-7));
}

TEST(Queue, cant_create_stack_with_null_length) {
    ASSERT_ANY_THROW(Queue<int> Q(0));
}

TEST(Queue, can_push_and_pop_element) {
    Queue <int> Q(3);
    Q.push(2);
    Q.push(7);
    Q.push(5);

    Queue <int> Q_exp(2);
    Q_exp.push(7);
    Q_exp.push(5);

    Q.pop();
    ASSERT_EQ(Q,Q_exp);
}
///
TEST(Queue, pop_return_element) {
    Queue <int> Q(3);
    Q.push(2);
    Q.push(7);
    Q.push(5);

    ASSERT_EQ(Q.pop(), 2);
}

TEST(Queue, cant_pop_in_empty_queue) {
    Queue <int> Q(1);
    ASSERT_ANY_THROW(Q.pop());
}

TEST(Queue, can_pop_only_element) {
    Queue <int> Q(1);
    Q.push(3);
    ASSERT_NO_THROW(Q.pop());
}

TEST(Queue, cant_push_full_queue) {
    Queue <int> Q(3);
    Q.push(2);
    Q.push(7);
    Q.push(5);
    ASSERT_ANY_THROW(Q.push(8));
}

TEST(Queue, can_get_last_element) {
    Queue <int> Q(3);
    Q.push(2);
    Q.push(7);
    Q.push(5);
    ASSERT_EQ(Q.top(), 5);
}

TEST(Queue, cant_get_last_element_in_empty_queue) {
    Queue <int> Q(3);
    ASSERT_ANY_THROW(Q.top());
}

TEST(Queue, can_get_size) {
    Queue <int> Q(3);
    Q.push(2);
    Q.push(8);
    ASSERT_EQ(2, Q.size());
}

TEST(Queue, can_get_size_in_empty_queue) {
    Queue <int> Q(3);
    ASSERT_EQ(0, Q.size());
}

TEST(Queue, empty_queue_return_true) {
    Queue <int> Q(3);
    ASSERT_EQ(Q.empty(), true);
}
TEST(Queue, non_empty_queue_return_false) {
    Queue <int> Q(3);
    Q.push(6);
    ASSERT_EQ(Q.empty(), false);
}