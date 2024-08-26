# Philosophers
This project is an implementation of the classic Dining Philosophers problem, exploring concepts of concurrent programming, resource allocation, and deadlock prevention.
## Overview
The Dining Philosophers problem is a classic synchronization problem in computer science. It illustrates challenges in resource allocation and deadlock prevention in concurrent systems. In this project, we simulate philosophers sitting at a round table, alternating between eating, thinking, and sleeping.
Features

  - Simulation of multiple philosophers as threads
  - Resource management using forks (mutexes)
  - Configurable parameters for number of philosophers, eating time, sleeping time, and more
  - Detailed logging of philosopher actions and state changes

## Requirements

  - C compiler (gcc recommended)
  - POSIX threads library (pthread)

## Compilation
To compile the project, use the provided Makefile:

```bash
make
```

This will create the executable philo.
## Usage
Run the program with the following arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

  - number_of_philosophers: The number of philosophers and forks
  - time_to_die: Time in milliseconds after which a philosopher dies if they haven't eaten
  - time_to_eat: Time in milliseconds it takes for a philosopher to eat
  - time_to_sleep: Time in milliseconds a philosopher spends sleeping
  - number_of_times_each_philosopher_must_eat (optional): If specified, simulation stops when all philosophers have eaten this many times

## Example

```bash
./philo 5 800 200 200
```

This runs the simulation with 5 philosophers, where each philosopher dies if they don't eat for 800ms, takes 200ms to eat, and 200ms to sleep.

## Notes

   - The program adheres to the 42 Norm coding standard
   - All heap-allocated memory is properly freed to prevent memory leaks
   - The simulation aims to prevent philosopher deaths while accurately modeling the problem

