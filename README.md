# CarRentalSystem

OOP Project for 5th Sem

**Steps to run the Application**

1. Click on the Link Button to download the **sqlite3 Library**. [Link](https://www.sqlite.org/2022/sqlite-amalgamation-3370200.zip)
2. Extract the Libaray and Place it in the Project Folder named as sqlite.
3. **sqlite Folder** should contain the following files
   1. shell.c
   2. sqlite3.c
   3. sqlite3.h
   4. sqlite3ext.h
4. Navigate to the Project Directory and run the following Command to **Compile sqlite3**

   `gcc ./sqlite/sqlite3.c ./sqlite/shell.c -o ./sqlite/sqlite3`

5. Now run the following Command in the Project Directory to **Compile sqlite3.c file**

   `gcc ./sqlite/sqlite3.c -c -o ./sqlite/sqlite3.o`

6. Now run the following Command in the Project Directory to **Compile main.cpp**

   `g++ main.cpp ./sqlite/sqlite3.o`

7. Now run the following Command in the Project Directory to **Run the Application**

   `./a.exe`
