# Movie-Playlist-System-in-C
# 🎬 Movie Streaming Platform – Playlist & Movie Management System  
A C-based project that manages a collection of movies and user-created playlists using  
Arrays, Binary Search Tree (BST), and Skip List as the primary data structures.

This project demonstrates file handling, searching, sorting, deletion, and playlist creation  
with clean modular code organized into multiple `.c` and `.h` files.
to compile the code: Use GCC:

```bash
gcc main.c movie.c bst.c skiplist.c playlist.c -o movie_app
./movie_app
```
Features:

### 1. Display All Movies  
Loads movies from **movies.txt** and prints them in a clean table format.

### 2. Search Movies by Genre  
✔ Skip List–based search (fast searching)  
✔ Also supports simple linear search if needed  

### 3. Search Movies Above a Rating  
Uses a **Binary Search Tree (BST)** for efficient rating-based searching.

### 4. Create Playlist  
Allows users to create custom playlists using linked lists.

### 5. Delete Movies  
Delete by:
- Title  
- Director  
- Genre  
- Rating  

Updates **movies.txt** after deletion.

### 6. Sort Movies Alphabetically  
Uses Bubble Sort.  
Saves output to **sorted_movies.txt**.

### 7. File Handling  
- movies.txt → Loaded at program start  
- sorted_movies.txt → After sorting  
- playlist files (optional)

## File Structure:
MovieStreamingProject
├── main.c
├── movie.c
├── movie.h
├── skiplist.c
├── skiplist.h
├── bst.c
├── bst.h
├── playlist.c
├── playlist.h
├── movies.txt
├── sorted_movies.txt (will be generated after sorting)
