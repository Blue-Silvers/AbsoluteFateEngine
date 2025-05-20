# AbsoluteFateEngine - DOOM
AbsoluteFateEngine is a 3D game engine developed in C++ using OpenGL, inspired by the classic DOOM gameplay. This DOOM branch focuses on building a prototype first-person shooter (FPS) in 3D.

## 📌 Demo Video

https://github.com/user-attachments/assets/c724594a-6b7e-4412-8e51-a658fac8b5d6

## 🎮 Key Features
- Real-time 3D rendering with OpenGL (immediate mode)

- 3D raycasting system with collision detection using Axis-Aligned Bounding Boxes (AABB)

- Basic player controls (movement, orientation)

- Minimalist HUD display

- Modular code structure for easy feature expansion

## 🧰 Dependencies
- GLFW for window management and keyboard/mouse input

- OpenGL for rendering

- GLM for 3D math (optional, depending on your needs)

## 🕹️ Input

| Key(s)        | Action                          |
|---------------|---------------------------------|
| `Z`           | Move forward                    |
| `S`           | Move backward                   |
| `Q` / `D`     | Strafe left / right             |
| Mouse         | Camera orientation              |
| `Enter`       | Take control of the player      |
| `Escape`      | Exit the game                   |

## 🛠️ Project Structure
- `AbsoluteFate/` : Contains the main source files of the engine

- `Dependencies/` : Third-party libraries required by the project

- `AbsoluteFate.sln` : Visual Studio solution file
