# tread_pool

Simple tread pool on C for Unix-like systems, tested on ubuntu, macOS and FreeBSD. 

## Features

## Architecture

The library implements a hybrid Half-Sync/Half-Reactor model, 
one event-pool monitors file descriptors and timers, and the POSIX thread pool processes tasks from a thread-safe queue.

```mermaid
flowchart LR
    App[Application] -->|tp_submit| Q[Task Queue]
    Q -->|pop| W[Worker Threads]
    W -->|wakeup| EL[Event Loop]
    EL -->|fd events| CB[Callbacks]
    EL -->|timers| CB
```

## Quick Start

## API Reference

