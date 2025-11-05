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
# Task 2 — Shell & Environment Exercises (Answers and Evidence)

This file documents my answers and evidence for Task 2 (shell & environment exercises). I performed each step in my VM and captured the commands and outputs below.

## 1) List the available shells on the system
Command(s) run:
- ls /bin | grep "ash"
- I also inspected typical shells present: dash and bash

Observed related files in /bin (examples from my session):
- bash
- bashbug
- c_rehash
- dash
- dh_bash-completion
- mksquashfs
- rbash
- unsquashfs

Conclusion:
- The primary interactive shells available on the system are dash and bash.

## 2) List environment variables in the current shell
Command run:
- printenv

Output (captured from my session):
SHELL=/bin/bash
SESSION_MANAGER=local/abdo-virtual-machine:@/tmp/.ICE-unix/5589,unix/abdo-virtual-machine:/tmp/.ICE-unix/5589
QT_ACCESSIBILITY=1
COLORTERM=truecolor
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
SSH_AGENT_LAUNCHER=gnome-keyring
XDG_MENU_PREFIX=gnome-
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
LANGUAGE=en_US:
LC_ADDRESS=ar_EG.UTF-8
GNOME_SHELL_SESSION_MODE=ubuntu
LC_NAME=ar_EG.UTF-8
SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
XMODIFIERS=@im=ibus
DESKTOP_SESSION=ubuntu
LC_MONETARY=ar_EG.UTF-8
GTK_MODULES=gail:atk-bridge
PWD=/home/abdo/Downloads/Embedded-Linux/AdminLinux_Task2
LOGNAME=abdo
XDG_SESSION_DESKTOP=ubuntu
XDG_SESSION_TYPE=wayland
SYSTEMD_EXEC_PID=6158
XAUTHORITY=/run/user/1000/.mutter-Xwaylandauth.3AR7E3
IM_CONFIG_CHECK_ENV=1
hello=abdlefattah
HOME=/home/abdo
USERNAME=abdo
IM_CONFIG_PHASE=1
LC_PAPER=ar_EG.UTF-8
LANG=en_US.UTF-8

Notes:
- I also have a custom variable `hello=abdlefattah` set in my environment during this session.
- `SHELL=/bin/bash` indicates the default login shell for the user.

## 3) Display the current shell name
Command run:
- echo $SHELL

Output:
- /bin/bash

Interpretation:
- The user is running Bash as the login shell.

## 4) Execute `echo \` then press Enter — what is the purpose of `\`?
Command typed and interaction:
- echo \
- (press Enter)
Shell prompt then shows continuation and I entered:
- hello
Result:
- hello

Explanation:
- The trailing backslash `\` at the end of a line in the shell is a line-continuation character. It tells the shell that the command continues on the next line.
- The shell prints the secondary prompt (PS2, default `>`) and waits for the rest of the command.
- In my example I typed `echo \` then pressed Enter, the shell showed a continuation prompt (`>`) where I typed `hello`. The completed command becomes `echo hello`, which prints `hello`.
- In short: `\` allows you to split a single command across multiple lines.

How to change the continuation prompt:
- Change PS2, for example:
  - export PS2=": "
- After that the prompt shown when waiting for continued input will be `: ` instead of `> `.

## 5) Create a Bash alias named `PrintPath` for `echo $PATH`
Command used to create the alias (interactive):
- alias printpath="echo $PATH"

Command output when executed:
- printpath
Output printed my PATH:
- /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin

To make this alias persistent:
- Add the following line to `~/.bashrc`:
  - alias PrintPath='echo $PATH'
- Then run:
  - source ~/.bashrc

---

Files / Evidence
- I captured these outputs during the session. If you want the screenshots embedded in this README, place the screenshot files into the repository and I will add inline image links.

Finished: these are my answers and outputs for Task 2. If you want, I can:
- Add the alias persistently to `~/.bashrc` and show the updated file.
- Embed screenshots directly in this README using relative links to the image files placed in the repo.
- Convert the presented outputs into separate proof files (e.g., txt files) and commit them.

```
