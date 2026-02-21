#ifndef STATS_H
#define STATS_H

void stats_init(void);
void stats_on_tick(int tick_system, int prev_running_pid, int new_running_pid);
void stats_print(void);

#endif