#ifndef _BOWLING_H
#define _BOWLING_H

struct bowling;

struct bowling *bowling_init(void);

void bowling_free(struct bowling *b);

void bowling_roll(struct bowling *b, int n);

int bowling_score(struct bowling *b);


#endif // _BOWLING_H
