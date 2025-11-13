# Embedded Linux — Admin Exercises

## 📌 Overview

This repository contains a set of small Embedded / Admin Linux exercises and example programs used to practice low-level Linux programming (C) and common administration tasks (Shell). The work is organized as separate task folders and includes source code, scripts, screenshots and short READMEs for each task.

## 📌 Languages

* C — ~96.8% (low-level programs)
* Shell — ~3.2% (automation and admin scripts)

## 📌 Repository structure

* AdminLinux_Task1/ — Task 1 scripts and documentation (basic Linux commands & automation)
* AdminLinux_Task2/ — Task 2 materials, outputs and README
* AdminLinux_Task3/ — Task 3: files and README
* AdminLinux_Task4/ — Task 4: toggle CapsLock LED via software (C program using syscalls)
  * screenshots/ — demo images and diagrams
  * toggle_caps.c (or similar) — C source that writes to /sys/class/leds/.../brightness
* AdminLinux_Task5/ — Task 5: Inter-Process Communication via Shared Memory
* AdminLinux_Task6/ — Task 6: TCP-Based RPC Client-Server Calculator
* AdminLinux_Task7/ — Task 7: Build Cross Compiler using Crosstool-NG
* README.md — this file

## 📌 Quick start

1. Clone the repository:

   ```bash
   git clone https://github.com/Abdelfattah225/Embedded_Linux.git
   ```
2. Browse to the task folder you want to explore:

   ```bash
   cd Embedded_Linux/AdminLinux_Task3
   ```

## 📌 Task summaries

* **Task 1** — Shell scripts demonstrating common admin tasks (file ops, process inspection, package/upgrade examples). See AdminLinux_Task1/ for scripts and usage examples.

* **Task 2** — Enhanced admin tasks with command outputs and explanations. See AdminLinux_Task2/ for details and sample outputs.

* **Task 3** — Additional admin exercises and examples. See AdminLinux_Task3/ for files and instructions.

* **Task 4** — Toggle CapsLock LED via software:

  * A small C program demonstrates writing to a kernel sysfs LED brightness node using low-level system calls (open, write, close) rather than stdio.
  * Intended behavior: passing `1` turns the CapsLock LED on, passing `0` turns it off. Other inputs are ignored or produce an error message depending on the implementation.
  * Demo screenshot and an optional demo video are included/linked.

* **Task 5 — Inter-Process Communication (IPC) via Shared Memory:**

  * Two separate C programs:

    * `writer.c` — writes messages into a POSIX shared memory object
    * `reader.c` — reads messages from the shared memory object
  * Demonstrates simple IPC in Linux.
  * **Build and Run:**

    ```bash
    gcc writer.c -o writer
    gcc reader.c -o reader
    ```

    Open two terminals:

    * Terminal A: `./writer`
    * Terminal B: `./reader`
  * Screenshots in `AdminLinux_Task5/screenshots/` show the reader and writer running simultaneously.

* **Task 6 — TCP-Based RPC Client-Server Calculator:**

  * A TCP client-server project demonstrating Remote Procedure Calls using C:

    * `server.c` — receives numbers and an operation, performs calculation, returns the result
    * `client.c` — sends numbers and operation to server, receives result
  * **Build and Run on the same PC:**

    ```bash
    gcc server.c -o server
    ./server
    gcc client.c -o client
    ./client
    ```

    Use `127.0.0.1` as server IP. Start server first. Input two numbers and an operation (`+`, `-`, `*`, `/`).
  * Screenshots in `AdminLinux_Task6/Task6_output.png` demonstrate interaction.

* **Task 7 — Build Cross Compiler using Crosstool-NG:**

  * Install, configure, and build a cross-compiler toolchain.
  

