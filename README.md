# std::math

A modern, header-only C++26 mathematics library providing **vectors, matrices, quaternions, and angle utilities** with SIMD acceleration.  
Designed for graphics, physics, and high-performance numerical applications.

The goal is for this library to be simple, sketchy, easy to include and maintain.

"Hacking small tools and examples is a great way to drive innovation. We should not get lost into software engineering problems. Especially at the beginning, the goal is to prototype and not waste time in polishing products." ~ [ggerganov](https://github.com/ggml-org/llama.cpp/discussions/205)

## Features

- **Vectors (`stdmath.vector`)**
  - Arbitrary-size, SIMD-friendly `vector<T, N>` type
  - Element-wise arithmetic, masks, and type traits
  - Works seamlessly with `<simd>` (if available)

- **Matrices (`stdmath.matrix`)**
  - Generic, column-major `matrix<T, X, Y>` type
  - Identity matrix generation
  - Optimized storage with alignment for SIMD

- **Quaternions (`stdmath.quaternion`)**
  - `basic_quaternion<T>` built on `vector<T,4>`
  - Addition, subtraction, and conversion to/from vectors
  - Angle-based initialization and utilities

- **Angles (`stdmath.angle`)**
  - Strongly-typed `basic_degree<T>` and `basic_radian<T>`
  - Conversion between radians and degrees
  - Predefined `PI` constant

## Requirements

- **C++26** or later
- Compiler support for:
  - `<concepts>`
  - optional `<simd>` (falls back to software emulation)
  - optional `<mdspan>` (falls back to the reference implementation)
  - optional `<linalg>` (falls back to software emulation)

## Getting Started

First install the library (any normal cmake method should due [see below for details]). Then import stdmath:

```cpp
import stdmath;
```

### Example: Vectors

```cpp
import std;
import stdmath;

int main() {
    stdmath::vector<float, 3> a {1.0f, 2.0f, 3.0f};
    stdmath::vector<float, 3> b {4.0f, 5.0f, 6.0f};

    auto c = a + b;
    std::cout << "c = (" << c[0] << ", " << c[1] << ", " << c[2] << ")\n";

    // OR

     std::cout << "c = (" << c.x << ", " << c.y << ", " << c.z << ")" << std::endl;
}
```

### Example: Vector Swizzling

```cpp
#include "math/namespace_alias.hpp" // Include to get the std::math namespace

import std;
import stdmath;

int main() {
    std::math::vector<float, 3> a {1.0f, 2.0f, 3.0f};

    auto b = a.zyx().to_vector();
    std::cout << "a = (" << b.z << ", " << b.y << ", " << b.x << ")" << std::endl;
}
```

### Example: Matrices

```cpp
#include "math/namespace_alias.hpp" // Include to get the std::math namespace

import std;
import stdmath;

int main() {
    auto I = std::math::matrix<float, 4, 4>::identity();
    auto Iinverse = inverse(I);
}
```

### Example: Quaternions

```cpp
#include "math/namespace_alias.hpp" // Include to get the std::math namespace

import std;
import stdmath;

int main() {
    std::math::quaternion q1 {0, 0, 0, 1};
    std::math::quaternion q2 {0, 1, 0, 0};

    auto q3 = q1 * q2;
}
```

### Example: Angles

```cpp
#include "math/namespace_alias.hpp" // Include to get the std::math namespace

import std;
import stdmath;

int main() {
    std::math::radian radians = 1.5708; // ~90 degrees
    std::math::degree degrees = radians;

    std::cout << "90 degrees in radians = " << radians << std::endl;
    std::cout << "Radians converted back to degrees = " << degrees << std::endl;
}
```

## Installation

Right now we only support cmake...

#### Option 1: FetchContent
```cmake
include(FetchContent)
FetchContent_Declare(
    stdmath
    GIT_REPOSITORY https://github.com/doxy-ai/stdmath.git
    GIT_TAG main
)
FetchContent_MakeAvailable(stdmath)

target_link_libraries(my_app PRIVATE stdmath)
```

#### Option 2: As a Subdirectory
If you’ve added this repo as a submodule:
```cmake
add_subdirectory(thirdparty/stdmath)
target_link_libraries(my_app PRIVATE stdmath)
```

## License

MIT License. See [LICENSE](LICENSE) for details.
