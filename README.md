# std::math

A modern, header-only C++26 mathematics library providing **vectors, matrices, quaternions, and angle utilities** with optional SIMD acceleration.  
Designed for graphics, physics, and high-performance numerical applications.

The goal is for this library to be simple, sketchy, easy to include and maintain.

"Hacking small tools and examples is a great way to drive innovation. We should not get lost into software engineering problems. Especially at the beginning, the goal is to prototype and not waste time in polishing products." ~ [ggerganov](https://github.com/ggml-org/llama.cpp/discussions/205)

## Features

- **Vectors (`vec.hpp`)**
  - Arbitrary-size, SIMD-friendly `vec<T, N>` type
  - Element-wise arithmetic, masks, and type traits
  - Works seamlessly with `std::experimental::simd` (or `<simd>` if available)

- **Matrices (`mat.hpp`)**
  - Generic, column-major `mat<T, X, Y>` type
  - Identity matrix generation
  - Optimized storage with alignment for SIMD

- **Quaternions (`quaternion.hpp`)**
  - `basic_quaternion<T>` built on `vec<T,4>`
  - Addition, subtraction, and conversion to/from vectors
  - Angle-based initialization and utilities

- **Angles (`angles.hpp`)**
  - Strongly-typed `basic_degree<T>` and `basic_radian<T>`
  - Conversion between radians and degrees
  - Predefined `PI` constant

- **Standard wrappers (`std.hpp`)**
  - Unified inclusion of `<simd>` or `<experimental/simd>`
  - `mdspan` support (falls back to bundled version if not available)

## Requirements

- **C++23** or later
- Compiler support for:
  - `<concepts>`
  - `<simd>` or `<experimental/simd>` (falls back to the reference implementation)
  - `<mdspan>` (falls back to the reference implementation)

## Getting Started

Since this is a **header-only** library, just add the headers to your include path:

```cpp
#include "math/vec.hpp"
#include "math/mat.hpp"
#include "math/quaternion.hpp"
#include "math/angles.hpp"
```

### Example: Vectors

```cpp
#include "math/namespace_alias.hpp"
#include <iostream>

int main() {
    std::math::vec<float, 3> a {1.0f, 2.0f, 3.0f};
    std::math::vec<float, 3> b {4.0f, 5.0f, 6.0f};

    auto c = a + b;
    std::cout << "c = (" << c[0] << ", " << c[1] << ", " << c[2] << ")\n";

    // OR

     std::cout << "c = (" << c.x << ", " << c.y << ", " << c.z << ")" << std::endl;
}
```

### Example: Vector Swizzling

```cpp
#include "math/namespace_alias.hpp"
#include <iostream>

int main() {
    std::math::vec<float, 3> a {1.0f, 2.0f, 3.0f};

    auto b = a.zyx().to_vec();
    std::cout << "a = (" << b.z << ", " << b.y << ", " << b.x << ")" << std::endl;
}
```

### Example: Matrices

```cpp
#include "math/namespace_alias.hpp"
#include <iostream>

int main() {
    auto I = std::math::mat<float, 4, 4>::identity();
    auto Iinverse = inverse(I);
}
```

### Example: Quaternions

```cpp
#include "math/namespace_alias.hpp"

int main() {
    std::math::quaternion q1 {0, 0, 0, 1};
    std::math::quaternion q2 {0, 1, 0, 0};

    auto q3 = q1 * q2;
}
```

### Example: Angles

```cpp
#include "math/namespace_alias.hpp"
#include <iostream>

int main() {
    std::math::radian radians = 1.5708; // ~90 degrees
    std::math::degree degrees = radians;

    std::cout << "90 degrees in radians = " << radians << std::endl;
    std::cout << "Radians converted back to degrees = " << degrees << std::endl;
}
```

## Installation

### Header-only (manual)
1. Copy the headers in `math` into your project (or add as a submodule).
2. Ensure your compiler supports **C++26**.
3. Include headers as needed.

### CMake (optional)
If you prefer using **CMake**, you can integrate `stdmath` as a target:

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
