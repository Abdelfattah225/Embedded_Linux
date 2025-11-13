# Admin Linux-Task 6: TCP-Based RPC Client-Server Calculator (C)

## Description
This project demonstrates a simple **TCP-based Remote Procedure Call (RPC) Calculator** using **C programming**.  
TCP (Transmission Control Protocol) ensures a **reliable connection** between two hosts. In this project:

- The **client** takes two numbers and an operation from the user.
- Sends this data to the **server** over a TCP connection.
- The **server** performs the calculation and sends the result back to the client.

This simulates a basic RPC mechanism using TCP sockets in C.

---

## Requirements
- GCC or any C compiler
- Linux or Windows environment with network support
- Two C source files: `server.c` and `client.c`

---

## Files
1. **server.c** – TCP server that receives numbers and operation, performs calculation, and returns the result.  
2. **client.c** – TCP client that sends numbers and operation to the server and receives the result.  
3. **Task6_output.png/** – Screenshots of the scripts running:
   - On the same PC (localhost)

---

## How to Compile and Run

### On the Server Machine
```bash
gcc server.c -o server
./server
```

### On the Client Machine
```bash
gcc client.c -o client
./client
```

### Running on the Same PC
- Use `127.0.0.1` (localhost) as the server IP in the client code.
- Start the server first, then run the client.
- Input two numbers and an operation (+, -, *, /).
- Client displays the result received from the server.

## Example Interaction

**Client Input:**
```
Enter first number: 15
Enter second number: 3
Enter operation (+, -, *, /): /
```

**Client Output:**
```
Result from server: 5.00
```

---

## Notes
- TCP ensures reliable communication between client and server.
- The server must be running before the client connects.
- This project demonstrates basic socket programming in C and client-server communication.

---

## Screenshots
Include screenshots showing:
- Client and server running on the same machine.
  ![OUTPUT](task6_output.png)
