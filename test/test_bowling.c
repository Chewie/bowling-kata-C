#include "unity.h"
#include "bowling.h"

struct bowling *b = NULL;

void setUp(void)
{
  b = bowling_init();
}

void tearDown(void)
{
  bowling_free(b);
}

void roll_multiple(size_t num_rolls, int score)
{
  for (size_t i = 0; i < num_rolls; i++)
    bowling_roll(b, score);
}

void test_bowling_gutter_game(void)
{
  roll_multiple(20, 0);
  TEST_ASSERT_EQUAL(0, bowling_score(b));
}

void test_bowling_all_ones(void)
{
  roll_multiple(20, 1);
  TEST_ASSERT_EQUAL(20, bowling_score(b));
}

void roll_spare(void)
{
  bowling_roll(b, 5);
  bowling_roll(b, 5);
}

void test_bowling_one_spare(void)
{
  roll_spare();
  bowling_roll(b, 3);
  roll_multiple(17, 0);
  TEST_ASSERT_EQUAL(16, bowling_score(b));
}

void test_bowling_one_strike(void)
{
  bowling_roll(b, 10); // strike
  bowling_roll(b, 3);
  bowling_roll(b, 5);
  roll_multiple(17, 0);
  TEST_ASSERT_EQUAL(26, bowling_score(b));
}

void test_bowling_perfect_game(void)
{
  roll_multiple(12, 10);
  TEST_ASSERT_EQUAL(300, bowling_score(b));
}
