# In-Memory Key–Value Store with LRU Eviction (C++)

## Overview

This project implements an **in-memory key–value cache** in **C++** with **O(1)** average time complexity for read and write operations.  
It simulates the internal behavior of real-world caching systems such as **Redis** or **Memcached**, using an **LRU (Least Recently Used)** eviction strategy and optional **TTL (Time-To-Live)** based expiration.

---

## Problem Statement

Design and implement an in-memory key–value caching system that:

- Supports fast read and write operations
- Automatically evicts the least recently used entries when capacity is reached
- Supports optional time-based expiration (TTL)
- Mimics real-world backend cache behavior

---

## Features

- O(1) average-time `get` and `put`
- LRU eviction policy
- Optional TTL (Time-To-Live) per key
- Automatic removal of expired entries
- Clean object-oriented design
- Implemented in modern C++

---

## Why LRU Cache?

LRU caching ensures that **recently accessed data remains in memory**, while **stale data is evicted first**.  
This strategy is widely used in:

- Databases
- Web servers
- Operating systems
- Distributed caching systems (Redis, Memcached)

---

## Design & Data Structures

| Component | Purpose |
|---------|--------|
| `unordered_map<int, Node*>` | O(1) access to cache entries |
| Doubly Linked List | Maintains access order for LRU eviction |
| Hash Map + DLL | Enables O(1) insert, delete, update |

### Cache Node Structure

Each node stores:
- `key`
- `value`
- `expiry timestamp` (TTL support)
- Pointer to `prev` node
- Pointer to `next` node

---

## Core Operations

### `get(key)`
- Returns the value if the key exists and is not expired
- Moves the accessed node to the front (most recently used)
- Returns `-1` if the key is missing or expired

### `put(key, value, ttl)`
- Inserts or updates a key-value pair
- Applies TTL if provided
- Evicts the least recently used entry when capacity is exceeded

---

## Time & Space Complexity

| Operation | Complexity |
|----------|------------|
| Get | O(1) average |
| Put | O(1) average |
| Space | O(capacity) |

---

## Example Usage

```cpp
LRUCache cache(2);

cache.put(1, 100);
cache.put(2, 200);

cache.get(1);      // returns 100
cache.put(3, 300); // evicts key 2
cache.get(2);      // returns -1

```

---

## Limitations & Improvements

- Not thread-safe (can be extended using mutex locks)
- No persistence to disk
- TTL cleanup is lazy (checked during access)
  
---

## Learning Outcomes

- Strong understanding of cache internals
- Practical use of hash maps and linked lists
- Exposure to system design trade-offs
- Interview-ready explanation of LRU caching
