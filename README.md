# Mooma
Open a shell and connects back to our server

## File functionality
### Victim side
1. Launcher.cpp: Write the actual virus into .reg for autorun.
2. main.cpp: The main body of the virus.
3. RandomMouse.cpp: Make the cursor of the victim move randomly.
4. StopAllThreads.cpp: Helper class to stop all threads in the victim side.
5. Func.cpp: Abstract class for all functionalities in the virus.
6. CommandListener.cpp: Listening incoming commands from the server side and exec them on victim side.
### Server side
1. server_GUI.py: A gui tool for the hacker to manage open connection and send cmds to victim easily.
