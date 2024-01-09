# Droppers

> Small pieces of code for bridging software systems

Non Fully Undetectable (FUD) classic Dll Injector intended for educational purposes

## Build options

Toggle ON/OFF with `cmake -D<XXX>=[ON,OFF]`

| Option       | Default | Description                                        |
| ------------ | ------- | -------------------------------------------------- |
| CLANG_FORMAT | OFF     | Enable/disable clang-format code formatting        |
| CPPCHECK     | OFF     | Enable/disable static code analysis using cppcheck |
| EXAMPLES     | OFF     | Build/install example programs                     |
| TESTING      | OFF     | Build and run unit tests                           |
| VALGRIND     | OFF     | Run memory checker using Valgrind                  |

## Portable executable configuration

Specify portable executable options with `#pragma comment(linker, "<FLAGS>")`

| TYPE:INTERFACE              | Description          |
| --------------------------- | -------------------- |
| /SUBSYSTEM:CONSOLE          | CUI console window   |
| /SUBSYSTEM:WINDOWS          | GUI graphical window |
| /SUBSYSTEM:EFI_APPLICATION  | EFI environment      |
| /SUBSYSTEM:BOOT_APPLICATION | BOOT environment     |

## Container features

- Debugging
- Dynamic analysis
- Static analysis

Considering package management systems introduce idiosyncrasies and design decisions specific to each project maintainer, package management is not addressed here. Microsoft's VCPackage looks promising, but doesn't fit the use case for a simple C application starter in CMake

## Makefile targets

Additional *sensible* makefile targets

- Remove CMake artifacts

## Not included

- Package distribution
- Package management

## Useful CMake commands

```sh
# add debugger symbols
cmake . -DCMAKE_BUILD_TYPE=Debug

# remove debugger symbols and more
cmake . -DCMAKE_BUILD_TYPE=Release

# windows make generator
cmake . -G "Unix Makefiles"

# slim windows headers
cmake . -DWIN_32_LEAN_AND_MEAN
```
