# Admin Linux - Task2
This readme file shows my work for the programming and shell administration tasks. Below is a short, clear overview of what I implemented, how I tested it, and where to find the evidence (screenshots) inside the repository.

## Task 1 — Print "Hello, World!" (edit using vi as requested)
- Implemented: a simple C program that prints "Hello, World!" to stdout.
- Requirements met:
  - The program prints the exact text `Hello, World!` using `printf`.
  - The source was edited using `vi` as requested.
  - The `main()` function prints the message and returns 0.
- How I tested:
  - Compiled with `gcc -o hello_world hello_world.c`
  - Ran `./hello_world` and verified the printed output is `Hello, World!`

---

## Task 2 — Install binary to /usr/local/bin and explain execution behavior
- Implemented:
  - Moved the compiled binary to `/usr/local/bin` using sudo (demonstrated in the screenshot).
- Reasoning / Explanation:
  - Placing an executable into `/usr/local/bin` allows it to be executed from any working directory because `/usr/local/bin` is included in the `PATH` environment variable.
  - When you run `hello_world` from any directory, the shell searches directories listed in `PATH` and finds `/usr/local/bin/hello_world`, so the program executes without specifying a path.
- Evidence:
  - Screenshot: `2.png` (shows installation commands and execution from another directory).

---

## Task 3 (Shell & Environment tasks)
- Items completed and commands used:
  1. List available shells on the system:
     - `cat /etc/shells` or `chsh -l`
  2. List environment variables in the current shell:
     - `env` or `printenv`
  3. Display current shell name:
     - `echo $SHELL` or `ps -p $$ -o comm=`
  4. Execute `echo \` then press Enter — explain:
     - The trailing backslash is a line-continuation character; the shell displays the secondary prompt (`PS2`, default `>`) and waits for continuation. Change PS2 with: `export PS2=": "`.
  5. Create a Bash alias named `PrintPath` for `echo $PATH`:
     - Add to `~/.bashrc`: `alias PrintPath='echo $PATH'` then `source ~/.bashrc`
- How I tested:
  - Ran each command and captured outputs in screenshots.
- Evidence:
  - See screenshot `2.png` (and other relevant screenshots in the repository as applicable).

---

## Files included
- Source: `hello_world.c` (simple C program printing "Hello, World!")
- Compiled binary (optional): `hello_world`
- README (this file)
- Screenshot(s): `2.png` — shows editing in `vi`, compilation, moving to `/usr/local/bin`, and running from another directory.

---

If you'd like, I can:
- Embed the screenshot(s) inline in this README using relative links so everyone who views the README sees them.
- Paste the full `hello_world.c` source into this README for immediate review.

```
