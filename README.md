# 🎮 AbsoluteFateEngine – AdvancedOpenGL
This branch of the AbsoluteFateEngine project focuses on exploring and demonstrating advanced OpenGL techniques through the development of custom shaders. It serves as a sandbox for experimenting with modern rendering features.

## ✨ Showcase
~~

## 🧪 Included Shaders
This branch includes several shader examples, such as :

- **Noise Deformation** : Applies a noise texture to dynamically distort the mesh.

- **Normal Mapping** : Simulates surface detail using a normal map texture.
  
- **Animated Waves** : Simulates real-time animated wave motion on plane.

- **Dynamic Tessellation** : Uses tessellation control and evaluation shaders to refine geometry on the fly.

## 🗂️ Project structure
`AbsoluteFate/Resources` : All textures.

`AbsoluteFate/Resources/Noise` : All noise textures.

`AbsoluteFate/Resources/Normal` : All normal textures.

`Dependencies/` : Third-party libraries necessary for the project

`AbsoluteFate.sln` : Solution file for Visual Studio.
 
- **Header/CPP** :

<img width="185" alt="image" src="https://github.com/user-attachments/assets/47ad79f6-687f-48ee-972b-9749bdd31615" /> <img width="190" alt="image" src="https://github.com/user-attachments/assets/9e270bbe-3a01-4a49-8eb3-4b1a0c5eb4f5" />


- **Shaders** :

<img width="197" alt="image" src="https://github.com/user-attachments/assets/c9e32660-2dd0-4c63-aa4b-5e4ff0aa5ed3" />



## 🕹️ Input

| Key(s)        | Action                          |
|---------------|---------------------------------|
| `Z`           | Move forward                    |
| `S`           | Move backward                   |
| `Q`           | Strafe left                     |
| `D`           | Strafe right                    |
| `Mouse`       | Camera orientation              |
| `TAB`         | Show vertices                   |
| `Enter`       | Take control of the player      |
| `Escape`      | Exit the game                   |

## 🧰 Dependencies
- **GLFW** for window management and keyboard/mouse input

- **OpenGL** for rendering
