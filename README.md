# Cub3d

Cub3d is a graphical raycasting project written in C, designed as an educational exercise inspired by classic Wolfenstein 3D-like engines. The project demonstrates fundamental 3D rendering concepts using a 2D map, textures, and real-time user input to simulate a 3D environment with the help of my colleague [Luis Ribeiro](https://github.com/LuirR91).

---

## Features

- **Raycasting Engine**: Simulates a 3D environment from a 2D map grid.
- **Texture Mapping**: Supports wall and object textures for visual depth.
- **Player Movement**: Real-time control of player position and rotation.
- **Custom Map Support**: Load and explore different map layouts.
- **Educational Codebase**: Modular, readable C code ideal for learning about graphics programming.

---

## Directory Structure

- **includes/**  
  Contains header files for the project. These define the structures, constants, and function prototypes used throughout the codebase.

- **libft/**  
  A custom implementation of the C standard library functions and common utilities. Used to avoid relying on external libraries, ensuring portability and deeper understanding of C fundamentals.

- **maps/**  
  Houses map files defining the layout of the world. Each map is a grid where different characters represent walls, empty spaces, and player start positions.

- **sources/**  
  The main source code directory. Contains the raycasting engine, rendering logic, input handling, map parsing, initialization routines, and other core modules.

- **textures/**  
  Stores texture images used for walls and other surfaces in the rendered environment.

- **Makefile**  
  Automates the build process. Compiles the project, manages dependencies, and provides convenient targets like `clean`, `fclean`, and `re`.

---

## Build Instructions

1. **Clone the repository:**

   ```sh
   git clone https://github.com/dde-carv/Cub3d.git
   cd Cub3d
   ```

2. **Build the project:**

   ```sh
   make
   ```

   This will compile the project and its dependencies (`libft` and the graphics library).

3. **Run the program:**

   ```
   ./cub3D maps/example_map.cub
   ```

   Replace `example_map.cub` with any valid map file in the `maps/` directory.

---

## Controls

- **W/A/S/D**: Move forward/left/back/right
- **Arrow Keys**: Rotate player view
- **ESC**: Exit program

---

## Dependencies

- Standard C compiler (gcc/clang)
- minilibx graphics library (included or automatically built)
- On macOS: OpenGL and AppKit frameworks
- On Linux: X11 libraries and related dependencies

---

## Project Structure Overview

- **Raycasting** – `sources/render/raycasting.c`: Core logic for simulating the 3D environment.
- **Input Handling** – `sources/movement/input_handler.c`: Interprets keyboard input for player movement.
- **Initialization** – `sources/init/`: Initializes game state, graphics, and textures.
- **Map Parsing** – `sources/map_utils/parse_map.c`: Loads and validates map files.
- **Utilities** – `sources/cub_utils/`: Helper functions for error handling, array management, and memory.

---
