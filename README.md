# CppUTest Hello World

A simple CMake-based C++ project template demonstrating basic CppUTest usage, including unit tests and mocking examples.

## Features

- Basic unit testing with CppUTest
- Mocking examples (function mocking and dependency injection)
- Automatic test execution during build
- CMake-based build system
- CppUTest automatically downloaded via FetchContent if not found

## Prerequisites

- **CMake** 3.28 or higher
- **C++ compiler** supporting C++23 (or adjust `CMAKE_CXX_STANDARD` in `CMakeLists.txt`)
- **Git** (for FetchContent to download CppUTest)

### Installing CMake

#### Windows

1. **Download CMake:**
   - Visit https://cmake.org/download/
   - Download the Windows installer (`.msi` file)
   - Choose the "Add CMake to system PATH" option during installation

2. **Verify installation:**
   ```powershell
   cmake --version
   ```

3. **Alternative: Using package managers:**
   - **Chocolatey:** `choco install cmake`
   - **Scoop:** `scoop install cmake`
   - **vcpkg:** `vcpkg install cmake`

#### Linux

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install cmake
```

**Fedora/RHEL:**
```bash
sudo dnf install cmake
```

**Arch Linux:**
```bash
sudo pacman -S cmake
```

**Verify installation:**
```bash
cmake --version
```

## Building the Project

### Windows

#### Using Visual Studio (Recommended)

1. **Create build directory:**
   ```powershell
   mkdir build
   cd build
   ```

2. **Configure with CMake:**
   ```powershell
   cmake .. -G "Visual Studio 17 2022" -A x64
   ```
   (Adjust the generator version if needed: `Visual Studio 16 2019`, `Visual Studio 15 2017`, etc.)

3. **Build:**
   ```powershell
   cmake --build . --config Debug
   ```
   Or open `cpputest_hello_world.sln` in Visual Studio and build from there.

4. **Run tests:**
   Tests run automatically after building. To run manually:
   ```powershell
   .\cpputest_hello_world_tests.exe
   ```

#### Using MinGW/MSYS2

1. **Create build directory:**
   ```powershell
   mkdir build
   cd build
   ```

2. **Configure:**
   ```powershell
   cmake .. -G "MinGW Makefiles"
   ```

3. **Build:**
   ```powershell
   cmake --build .
   ```

4. **Run tests:**
   ```powershell
   .\cpputest_hello_world_tests.exe
   ```

### Linux

1. **Create build directory:**
   ```bash
   mkdir build
   cd build
   ```

2. **Configure:**
   ```bash
   cmake ..
   ```

3. **Build:**
   ```bash
   cmake --build .
   ```
   Or use `make`:
   ```bash
   make
   ```

4. **Run tests:**
   Tests run automatically after building. To run manually:
   ```bash
   ./cpputest_hello_world_tests
   ```

## Running Tests

### Automatic Test Execution

Tests run automatically after building the test executable (via POST_BUILD command). If any test fails, the build will fail.

### Manual Test Execution

**Windows:**
```powershell
cd build
.\cpputest_hello_world_tests.exe
```

**Linux:**
```bash
cd build
./cpputest_hello_world_tests
```

### Using CTest

You can also use CMake's CTest:

```bash
cd build
ctest --output-on-failure
```

## Project Structure

```
cpputest_hello_world/
├── CMakeLists.txt              # Root CMake configuration
├── code/
│   ├── CMakeLists.txt          # Main executable configuration
│   ├── main.cpp                # Main entry point
│   ├── add.h / add.cpp         # Simple add function example
│   ├── mock_example.h / mock_example.cpp  # Mocking example
│   ├── discount_provider.h     # Dependency injection interface
│   ├── external_discount.h / external_discount.cpp  # Production implementation
│   └── tests/
│       ├── CMakeLists.txt      # Test executable configuration
│       ├── test_add.cpp        # Basic unit test example
│       └── test_mock.cpp       # Mocking test examples
└── build/                      # Build output directory (gitignored)
```

## Examples Included

### 1. Basic Unit Test (`test_add.cpp`)
Simple test demonstrating basic CppUTest usage:
- Tests the `add()` function
- Uses `CHECK_EQUAL` assertion

### 2. Function Mocking (`test_mock.cpp`)
Demonstrates mocking a function dependency:
- Production code calls `fetch_remote_discount_percentage()`
- Test provides a mock implementation using CppUTest's `mock()`

### 3. Dependency Injection (`test_mock.cpp`)
Shows dependency injection pattern:
- Code depends on `IDiscountProvider` interface
- Test injects a mock/fake implementation

## Notes

- **CppUTest**: If CppUTest is not found via `find_package`, it will be automatically downloaded using CMake's FetchContent (from GitHub).
- **Build directory**: The `build/` directory is gitignored. You can safely delete it and recreate it.
- **C++ Standard**: The project uses C++23. If your compiler doesn't support it, modify `CMAKE_CXX_STANDARD` in the root `CMakeLists.txt`.

## Troubleshooting

### CMake not found
- Ensure CMake is installed and in your PATH
- On Windows, restart your terminal after installing CMake

### CppUTest download fails
- Check your internet connection
- Ensure Git is installed and accessible

### Compiler errors
- Verify your compiler supports C++23 (or adjust the standard in `CMakeLists.txt`)
- On Windows, ensure you have Visual Studio Build Tools or a compatible compiler installed

### Tests not running
- Check that the test executable was built successfully
- Verify the executable exists in the `build/` directory
