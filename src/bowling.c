#include <stdlib.h>
#include "bowling.h"

#define MAX_ROLLS 21

struct bowling
{
  int rolls[MAX_ROLLS];
  int current_roll;
};

struct bowling *bowling_init(void)
{
  struct bowling *b = malloc(sizeof(*b));
  for (size_t i = 0; i < MAX_ROLLS; i++)
    b->rolls[i] = 0;
  b->current_roll = 0;
  return b;
}

void bowling_free(struct bowling *b)
{
  free(b);
}

void bowling_roll(struct bowling *b, int n)
{
  b->rolls[b->current_roll++] = n;
}

int bowling_score(struct bowling *b)
{
  int score = 0;
  int frame_index = 0;
  for (size_t frame = 0; frame < 10; frame++)
  {
    if (b->rolls[frame_index] == 10) // strike
    {
      score += 10 + b->rolls[frame_index + 1] + b->rolls[frame_index + 2];
      frame_index++;
    }
    else if (b->rolls[frame_index] + b->rolls[frame_index + 1] == 10) // spare
    {
      score += 10 + b->rolls[frame_index + 2];
      frame_index += 2;
    }
    else
    {
    score += b->rolls[frame_index] + b->rolls[frame_index + 1];
    frame_index += 2;
    }
  }

  return score;
}
