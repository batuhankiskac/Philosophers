# Philosophers

Philosophers is a project developed in C that simulates the classic Dining Philosophers problem. This problem is a well-known example used in concurrent algorithm design to illustrate synchronization issues and techniques for managing shared resources.

## Features

- **Concurrency Simulation**: Simulates multiple philosophers (threads) dining and thinking concurrently.
- **Mutexes and Semaphores**: Utilizes mutexes and semaphores to manage access to shared resources (forks).
- **Deadlock Prevention**: Implements strategies to prevent deadlock and ensure all philosophers get a chance to eat.
- **Resource Management**: Efficiently manages shared resources to avoid race conditions and starvation.

## Requirements

- **C Compiler**: Ensure you have a C compiler like `gcc` installed.
- **Make**: The project uses a Makefile for building and managing the compilation process.

## Installation

Clone the repository and navigate to the project directory:
```sh
git clone https://github.com/batuhankiskac/Philosophers.git
cd Philosophers
```

Build the project using Make:
```sh
make
```

## Usage

Run the program with the following command:
```sh
./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```
- `number_of_philosophers`: The number of philosophers and forks.
- `time_to_die`: Time in milliseconds before a philosopher dies if they haven't started eating.
- `time_to_eat`: Time in milliseconds it takes for a philosopher to eat.
- `time_to_sleep`: Time in milliseconds a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): Number of times each philosopher must eat before the simulation ends. If not specified, the simulation runs indefinitely.

Example:
```sh
./philosophers 5 800 200 200 7
```

This example runs the simulation with 5 philosophers, where each philosopher must eat 7 times, and specific times for dying, eating, and sleeping.

---

Feel free to modify this description to better fit your project's specifics!
