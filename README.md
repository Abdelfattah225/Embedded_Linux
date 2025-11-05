# Embedded Linux — Admin Exercises

Overview
--------
This repository contains a set of small Embedded / Admin Linux exercises and example programs used to practice low-level Linux programming (C) and common administration tasks (Shell). The work is organized as separate task folders and includes source code, scripts, screenshots and short READMEs for each task.

Languages
---------
- C — ~71.4% (low-level programs)
- Shell — ~28.6% (automation and admin scripts)

Repository structure
--------------------
- AdminLinux_Task1/ — Task 1 scripts and documentation (basic Linux commands & automation)
- AdminLinux_Task2/ — Task 2 materials, outputs and README
- AdminLinux_Task3/ — Task 3: files and README
- AdminLinux_Task4/ — Task 4  toggle CapsLock LED via software (C program using syscalls)
  - screenshots/ — demo images and diagrams
  - toggle_caps.c (or similar) — C source that writes to /sys/class/leds/.../brightness
- README.md — this file

Quick start
-----------
1. Clone the repository:
   git clone https://github.com/Abdelfattah225/Embedded_Linux.git
2. Browse to the task folder you want to explore:
   cd Embedded_Linux/AdminLinux_Task3

Task summaries
--------------
- Task 1 — Shell scripts demonstrating common admin tasks (file ops, process inspection, package/upgrade examples). See AdminLinux_Task1/ for scripts and usage examples.
- Task 2 — Enhanced admin tasks with command outputs and explanations. See AdminLinux_Task2/ for details and sample outputs.
- Task 3 —  Additional admin exercises and examples. See AdminLinux_Task3/ for files and instructions.
- Task 4 — Toggle CapsLock LED via software:
  - A small C program demonstrates writing to a kernel sysfs LED brightness node using low-level system calls (open, write, close) rather than stdio.
  - Intended behavior: passing `1` turns the CapsLock LED on, passing `0` turns it off. Other inputs are ignored or produce an error message depending on the implementation.
  - Demo screenshot and an optional demo video are included/linked.

