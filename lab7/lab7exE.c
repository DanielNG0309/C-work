// ENCM 335 Fall 2021
// Lab 7 Exercise E
//
// Goals of this exercise
//   1. Practice understanding uses of nested structure objects
//      and pointers to structure objects.
//   2. Seeing that using structure types for date/time combinations
//      causes code for comparison to be awkward and slow.

struct Date {
  int y;     // year
  int mon;   // 1 for Jan, 2 for Feb, etc.
  int d_o_m; // >= 1, <= 31
};
typedef struct Date date_t;

struct TimeOfDay {
  int h;   // >= 0, <= 23
  int min; // >= 0, <= 59
  int s;   // >= 0, <= 59
};
typedef struct TimeOfDay t_o_d;

struct DayDateTime {
  char day_of_week[4]; // One of "Sun", "Mon", etc.
  date_t date;
  t_o_d time;
};
typedef struct DayDateTime day_date_time;

int earlier_tod(const t_o_d *left, const t_o_d *right)
{
  if (left->h < right->h)
    return 1;
  if (left->h > right->h)
    return 0;

  // hours were equal, so check minutes
  if (left->min < right->min)
    return 1;
  if (left->min > right->min)
    return 0;
 
  // point one

  // minutes were equal, so check seconds
  return left->s < right->s;
}

int earlier_date(const date_t *left, const date_t *right)
{
  if (left->y < right->y)
    return 1;
  if (left->y > right->y)
    return 0;

  // years were equal, so check months
  if (left->mon < right->mon)
    return 1;
  if (left->mon > right->mon)
    return 0;
 
  // months were equal, so check day
  return left->d_o_m < right->d_o_m;
}

int earlier_ddt(const day_date_time *left, day_date_time *right)
{
  if (earlier_date(&left->date, &right->date))
    return 1;

  if (earlier_date(&right->date, &left->date))
    return 0;
  
  // dates were identical, need to check time of day
  return earlier_tod(&left->time, &right->time);
}


int main(void)
{
  day_date_time ddt1 = {"Tue", {2019, 10, 22}, {14, 15, 37}};
  day_date_time ddt2 = {"Tue", {2019, 10, 22}, {14, 15, 39}};
  int rv;
  rv = earlier_ddt(&ddt1, &ddt2);
  return 0;
}
