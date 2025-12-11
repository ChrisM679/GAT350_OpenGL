# GAT350 OpenGL Engine

## Overview
The GAT350 OpenGL Engine is a lightweight and modular C++ game engine designed for 2D and 3D applications. It leverages modern C++20 features and integrates with OpenGL for rendering, SDL for window management, and RapidJSON for serialization. The engine is structured to provide flexibility and efficiency for game development and other graphical applications.

## Features
- **Math Utilities**: Includes mathematical constants, angle conversions, vector operations, and utility functions for 2D/3D transformations.
- **File System Utilities**: Provides functions for file I/O, directory management, and path manipulation.
- **Serialization**: Supports JSON-based serialization using RapidJSON for saving and loading game data.
- **Vector2 Class**: A robust 2D vector implementation with support for mathematical operations, normalization, rotation, and more.
- **Cross-Platform**: Utilizes SDL for platform-independent window and input handling.
- **OpenGL Integration**: Designed to work seamlessly with OpenGL for rendering.

## Getting Started

### Prerequisites
- **C++ Compiler**: A compiler with C++20 support (e.g., MSVC, GCC, Clang).
- **Libraries**:
  - [SDL3](https://github.com/libsdl-org/SDL) for window and input handling.
  - [RapidJSON](https://github.com/Tencent/rapidjson) for JSON parsing.
  - [GLM](https://github.com/g-truc/glm) for mathematical operations.
- **CMake**: For building the project.

### Installation
1. Clone the repository:
2. Install dependencies:
- Ensure SDL3, RapidJSON, and GLM are available in your include paths.
3. Build the project:
- Use CMake to generate build files and compile the project.

### Usage
1. Create or modify scenes using JSON files in the `Assets/Scenes` directory.
2. Implement game logic in the `Source\Application\Main.cpp` file.
3. Run the application to see your changes.

## Project Structure
- **Source/**: Contains the engine's source code.
- **Engine/**: Core engine modules, including math utilities, file handling, and serialization.
- **Application/**: Entry point and application-specific logic.
- **Assets/**: Stores assets like textures, models, and scenes.
- **Build/**: Contains build artifacts and generated files.
- **readme.md**: Project documentation.

## Key Modules
### Math Utilities
- Constants like `pi`, `twoPi`, and `halfPi`.
- Functions for angle conversions (`RadToDeg`, `DegToRad`).
- Wrapping functions for integers and floats.
- Vector2 class for 2D vector operations.

### File Utilities
- Functions for reading and writing text/binary files.
- Directory management utilities.
- Path manipulation functions.

### Serialization
- JSON-based serialization using RapidJSON.
- Macros for simplifying serialization (`SERIAL_READ`, `SERIAL_CONTAINS`).

## Contributing
Contributions are welcome! Feel free to fork the repository, submit issues, or create pull requests.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments
- [SDL](https://github.com/libsdl-org/SDL)
- [RapidJSON](https://github.com/Tencent/rapidjson)
- [GLM](https://github.com/g-truc/glm)