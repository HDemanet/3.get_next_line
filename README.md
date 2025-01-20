<p align="center">
  <img src="get_next_linem.png" alt="get_next_line Logo">
</p>

# get_next_line  

The 42 school's get_next_line project is where we learn to read from a file descriptor, as well as the use of static variables.
This function returns a single line from a given file descriptor. If called in a loop, get_next_line returns the entire contents of a file, line by line until it reaches the end of the file. It can be compiled specifying any buffer size.

---

## 📋 Mandatory Features  

The `get_next_line` function must:  
- Read a single line from a file descriptor (`fd`).  
- Return the line, including the newline (`\n`) character if present.  
- Return `NULL` if there is nothing more to read or in case of an error.  

---

## 🔗 Bonus Features 

- Single Static Variable: Optimize the function to use only one static variable. 
- Multiple File Descriptors: Support multiple `fd`s, maintaining the correct state for each file.
