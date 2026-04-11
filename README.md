# Somali Flag Wave Simulation

## Overview

This project presents a real-time simulation of a waving Somali flag using OpenGL. It demonstrates fundamental computer graphics concepts, including mesh generation, vertex manipulation for animation, and basic 2D rendering. The simulation aims to provide a visually appealing and dynamic representation of the Somali flag, complete with its iconic star, reacting to an implicit wind force.

## Features

| Feature                              | Description                                                                        | Implementation Details                                                                            |
| :----------------------------------- | :--------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------ |
| **Dynamic Wave Effect**              | The flag exhibits a continuous, smooth waving motion, simulating wind.             | Achieved by applying a sine wave function to vertex Y-coordinates based on column index and time. |
| **Somali Flag Design**               | Accurate representation of the Somali flag's blue field and white Star of Unity.   | Uses `glColor3f` for the distinct blue and white colors.                                          |
| **Star of Unity**                    | A perfectly aligned, five-pointed white star is rendered on the flag.              | Custom `drawStar` function calculates vertices for a regular pentagram.                           |
| **Flagpole**                         | A simple flagpole is rendered to anchor the flag.                                  | Basic `GL_QUADS` drawing for a static pole.                                                       |
| **Frame-rate Independent Animation** | The wave animation speed is consistent across different system performance levels. | Utilizes `glfwGetTime()` to ensure time-based, rather than frame-based, animation.                |
| **Basic 2D Rendering**               | All elements are rendered using immediate mode OpenGL for simplicity.              | Employs `glBegin`/`glEnd` with `GL_QUADS` and `GL_TRIANGLES`.                                     |

## Technologies Used

- **C++17:** The core programming language for the application.
- **OpenGL (Legacy/Immediate Mode):** Used for rendering graphics.
- **GLFW:** A multi-platform library for creating windows with OpenGL contexts and handling input.
- **GLEW:** The OpenGL Extension Wrangler Library, used to manage OpenGL extensions.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

Before you begin, ensure you have the following installed:

- A C++ compiler (e.g., GCC, Clang) that supports C++17.
- GLFW library (development files).
- GLEW library (development files).
- OpenGL development libraries (usually comes with your graphics drivers or system development packages).

**On Debian/Ubuntu-based systems, you can typically install these with:**

```bash
sudo apt-get update
sudo apt-get install build-essential libglfw3-dev libglew-dev
```

### Compilation

Navigate to the directory containing `flag.cpp` in your terminal and execute the following command:

```bash
g++ "/home/adn1sk/Downloads/programming career/c++/flag.cpp" -o flag -lGL -lGLEW -lglfw -std=c++17
```

### Execution

After successful compilation, run the executable:

```bash
./flag
```

## Code Structure

The project is contained within a single `flag.cpp` file, structured as follows:

- **`main()` function:** Initializes GLFW and GLEW, sets up the rendering loop, and handles window events.
- **`drawPole(float x, float y, float h)`:** Renders the static flagpole.
- **`drawStar(float cx, float cy, float radius)`:** Renders the five-pointed Star of Unity.
- **Wave Logic:** Implemented directly within the main loop, calculating vertex offsets using a sine function based on `glfwGetTime()`.

## Screenshots


https://github.com/user-attachments/assets/b6834a48-1fb9-4d46-a2c0-3467126b7b40




## Future Enhancements

- Transition to modern OpenGL (VAOs, VBOs, Shaders) for improved performance and flexibility.
- Implement user controls for wave parameters (e.g., amplitude, frequency, wind speed).
- Add lighting and shading to give the flag a more 3D appearance.
- Introduce texture mapping for more detailed flag designs.
- Improve the flagpole rendering with more detail or 3D elements.

## License

This project is open-source and available under the MIT License.

## Author

- **adn1sk**

- ##CONTACT ME:
- GMAIL: adammoha0987@gmail.com
- X: @ADN1SK
- ## 
