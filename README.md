# Droppers

> Small pieces of code for bridging software systems

Non Fully Undetectable (FUD) classic Dll Injector intended for educational purposes

![Cover Art](.img/cover-art.jpeg)

- [Droppers](#droppers)
	- [Build options](#build-options)
	- [Portable executable configuration](#portable-executable-configuration)
	- [Container features](#container-features)
	- [Makefile targets](#makefile-targets)
	- [Not included](#not-included)
	- [Not covered](#not-covered)
	- [Useful CMake commands](#useful-cmake-commands)
	- [Source](#source)
		- [Pe.c](#pec)
		- [Dll.c](#dllc)
	- [Headers](#headers)
		- [Dropper](#dropper)
	- [Tests](#tests)
		- [Dropper](#dropper-1)
		- [Test Headers](#test-headers)
	- [Examples](#examples)
		- [Portable Executables](#portable-executables)
		- [Dynamic Linked Libraries](#dynamic-linked-libraries)
		- [Resource Files](#resource-files)
	- [References](#references)
	- [Interesting ideas](#interesting-ideas)
		- [Shorten Endpoint Detection Response (EDR) cycle](#shorten-endpoint-detection-response-edr-cycle)
			- [Useful EDR integration testing links](#useful-edr-integration-testing-links)
		- [Libsodium crypter/unpacker](#libsodium-crypterunpacker)
			- [Useful links](#useful-links)
	- [See also](#see-also)

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

## Makefile targets

Additional *sensible* makefile targets

- Remove CMake artifacts

## Not included

- Package distribution
- Package management

Considering package management systems introduce idiosyncrasies and design decisions specific to each project maintainer, package management is not addressed here. Microsoft's VCPackage looks promising, but doesn't fit the use case for a simple C application starter in CMake

## Not covered

- Binary patching
- Stenography
- Two is One, One is None (TOON) Rule

## Useful CMake commands

When building all targets prepare for Windows Defender alerts. Consider disabling Defender for binary analysis

```sh
# add debugger symbols
cmake . -DCMAKE_BUILD_TYPE=Debug

# remove debugger symbols and more
cmake . -DCMAKE_BUILD_TYPE=Release

# windows make generator
cmake . -G "Unix Makefiles"

# slim windows headers
cmake . -DWIN_32_LEAN_AND_MEAN

# build specific example (after cmake . -DEXAMPLES=ON)
cmake --build ./examples --target PeDropperEx0
```

Cross compiling on a shared virtual filesystem can lead to an indeterminate build state. If your build stops working, the first consideration should be to delete `CMakeCache.txt` and rerun your cmake build command

## Source

### [Pe.c](src/pe.c)

Skeleton source code for a portable executable. Includes notes to

- Generate preprocessed source
- Generate assembly
- Compiler explorer
- Compiler flag explorer
- Generating binary source
- Discover Windows API macro definitions
- Discover Windows API typedef definitions

### [Dll.c](src/dll.c)

Skeleton source code for a Dynamic Linked Library. Includes simple message box

## Headers

### Dropper

- [include/dropper/assert.h](./include/dropper/assert.h): Assertion and debugging
- [include/dropper/enc.h](./include/dropper/enc.h): Symmetric encoding of data
- [include/dropper/proc.h](./include/dropper/proc.h): Inspecting and handling processes

## Tests

### Dropper

- [test/src/TestDropperEnc.c](./test/src/TestDropperEnc.c): Unit tests for symmetric encoding of data

### Test Headers

- [test/include/test/acutest.h](./test/include/test/acutest.h): "Another C/C++ Unit Test facility"

## Examples

### Portable Executables

- [PeDropperEx0](./examples/pe/ex0.c): WinAPI MessageBox
- [PeDropperEx1](./examples/pe/ex1.c): Debugger shellcode
- [PeDropperEx2](./examples/pe/ex2.c): WinAPI MessageBox shellcode
- [PeDropperEx3](./examples/pe/ex3.c): Encrypted WinAPI MessageBox shellcode
- [PeDropperEx4](./examples/pe/ex4.c): Encrypted WinAPI Windows Subsystem MessageBox shellcode
- [PeDropperEx5](./examples/pe/ex5.c): Encrypted WinAPI Windows Subsystem MessageBox shellcode Process Injection (PI)
- [PeDropperEx6](./examples/pe/ex6.c): Classic DLL injection

### Dynamic Linked Libraries

- [DllDropperEx0](./examples/dll/ex0.c): WinAPI MessageBox
- [DllDropperEx1](./examples/dll/ex1.c): Encrypted WinAPI Windows Subsystem MessageBox shellcode

### Resource Files

- [PeDropperRsrceEx0](./examples/rsrc/ex0.c): CMD=calc.exe shellcode icon resource

## References

- [Alertable I/O](https://learn.microsoft.com/en-us/windows/win32/fileio/alertable-i-o)
- [ExploitDB: hunting process injection by Windows API calls](https://www.exploit-db.com/docs/47983)
- [MalAPI](https://malapi.io/)
- [Metasploit unleashed: generating payloads](https://www.offsec.com/metasploit-unleashed/generating-payloads/)
- [Nullprogram: CRT-free ...](https://nullprogram.com/blog/2023/02/15/)
- [Nullprogram: Hand-written Windows API prototypes](https://nullprogram.com/blog/2023/05/31/)
- [Windows API List](https://learn.microsoft.com/en-us/windows/win32/apiindex/windows-api-list)

## Interesting ideas

### Shorten Endpoint Detection Response (EDR) cycle

Consider implementing integration level testing with CTest to ensure distributed binaries do not trigger Endpoint Detection Response

#### Useful EDR integration testing links

- [Awesome Yara](https://github.com/InQuest/awesome-yara?tab=readme-ov-file#rules)
- [Convention engine](https://github.com/stvemillertime/ConventionEngine)
- [Yara](https://github.com/VirusTotal/yara)

### Libsodium crypter/unpacker

Developing a crypter/unpacker is an interesting exercise in Windows systems programming. Perhaps self-decrypting payloads, metamorphic and polymorphic code should take higher precedence

#### Useful links

- [Libsodium](https://github.com/jedisct1/libsodium)
- [Resource only dll](https://learn.microsoft.com/en-us/cpp/build/creating-a-resource-only-dll?view=msvc-170)

## See also

- [Awesome malware techniques](https://github.com/fr0gger/Awesome_Malware_Techniques)
- [Beginners guide to EDR evasion](https://kylemistele.medium.com/a-beginners-guide-to-edr-evasion-b98cc076eb9a)
- [Dll hijack by proxy](https://github.com/tothi/dll-hijack-by-proxying)
- [Nullprogram: Win32 environment blocks](https://nullprogram.com/blog/2023/08/23/)
- [Pentester's promiscuous notebook](https://ppn.snovvcrash.rocks/red-team/maldev)
- [Red team notes: APC Queue injection](https://www.ired.team/offensive-security/code-injection-process-injection/apc-queue-code-injection)
- [Red team notes: writing and compiling shellcode in c](https://www.ired.team/offensive-security/code-injection-process-injection/writing-and-compiling-shellcode-in-c)
- [Red teaming toolkit: defense evasion](https://github.com/infosecn1nja/Red-Teaming-Toolkit#defense-evasion)
- [Reprogrammed: archive](https://reprgm.github.io/archive/)
- [Shell storm](https://shell-storm.org/shellcode/index.html)
- [SysWhispers2](https://github.com/jthuraisamy/SysWhispers2)
- [The undocumented functions](http://undocumented.ntinternals.net/)
- [Tips for writing anti-cheat](https://dev.to/igorsegallafa/tips-for-writing-an-anti-cheat-4m6k)
