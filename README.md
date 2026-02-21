### MiniOS – CPU Scheduling & Process Management Simulator (C)

MiniOS is a modular Operating System simulator written in C that models CPU scheduling policies, process lifecycle management, and performance metrics analysis.

This project was designed to explore how low-level scheduling decisions impact system performance and resource utilization.

---

### Overview

MiniOS simulates a simplified single-core CPU environment where:

- Processes are dynamically created with custom burst times
- The scheduler selects which process runs at each CPU tick
- Process states transition between READY, RUNNING, and TERMINATED
- Performance metrics are calculated and analyzed

The system operates using a **tick-based simulation model**, mimicking how real operating systems manage execution cycles.

---

### Implemented Scheduling Algorithms

## FIFO (First-In First-Out)
- Non-preemptive
- Oldest READY process is executed first
- Simple but can cause convoy effect

## Round Robin (Preemptive)
- Configurable time quantum
- Fair CPU time distribution
- Uses a dynamically resized circular queue
- Tracks context switches

## Shortest Job First (SJF)
- Non-preemptive
- Selects process with smallest remaining time
- Optimizes average waiting time
- Demonstrates scheduling optimality trade-offs

---

### Performance Metrics

MiniOS computes per-process and global system metrics:

- Waiting Time (WT)
- Response Time (RT)
- Turnaround Time (TAT)
- Throughput
- Context Switch Count
- Total CPU Ticks

These metrics allow direct comparison between scheduling strategies.

---

### System Architecture

The project follows a clean modular design:

MiniOS
│
├── main.c → System initialization & CLI loop
├── command.c/h → Command parsing & tick execution
├── process.c/h → Process table & lifecycle management
├── scheduler.c/h → FIFO / RR / SJF implementations
├── stats.c/h → Performance tracking & reporting


### Architectural Principles

- Separation of concerns
- Dynamic memory allocation (`malloc`, `realloc`)
- Explicit state transitions
- Deterministic tick-based execution

---

### Simulation Model

Each command execution triggers:

1. System tick increment
2. CPU execution cycle
3. Remaining time decrement
4. Scheduler decision step
5. State transition updates
6. Statistics tracking

This design simulates how real kernels update scheduling decisions at runtime.

### CLI Commands:

run <name> <burst>     Create process with burst time
kill <pid|name>        Terminate process
ps                     Display process table
stats                  Display performance metrics
help                   Show command list
exit                   Exit simulator

### What This Project Demonstrates

- Understanding of OS-level scheduling mechanisms
- Queue implementation with dynamic resizing
- Preemptive vs non-preemptive scheduling trade-offs
- Process lifecycle modeling
- Performance measurement and analysis
- Systems programming in C