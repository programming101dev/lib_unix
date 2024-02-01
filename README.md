# lib_unix Repository Guide

Welcome to the `lib unix` repository. This guide will help you set up and run the provided scripts.

## **Table of Contents**

1. [Cloning the Repository](#cloning-the-repository)
2. [Prerequisites](#Prerequisites)
3. [Running the `generate-cmakelists.sh` Script](#running-the-generate-cmakelistssh-script)
4. [Running the `change-compiler.sh` Script](#running-the-change-compilersh-script)
5. [Running the `build.sh` Script](#running-the-buildsh-script)
6. [Running the `install.sh` Script](#running-the-installsh-script)

## **Cloning the Repository**

Clone the repository using the following command:

```bash
git clone https://github.com/programming101dev/lib_unix.git
```

Navigate to the cloned directory:

```bash
cd lib_unix
```

Ensure the scripts are executable:

```bash
chmod +x *.sh
```

## **Prerequisites**

- to ensure you have all of the required tools installed, run:
```bash
./check-env.sh
```

If you are missing tools follow these [instructions](https://docs.google.com/document/d/1ZPqlPD1mie5iwJ2XAcNGz7WeA86dTLerFXs9sAuwCco/edit?usp=drive_link).

You will need to install:
- [libp101_error](https://github.com/programming101dev/lib_error)
- [libp101_env](https://github.com/programming101dev/lib_env)
- [libp101_c](https://github.com/programming101dev/lib_c)

## **Running the generate-cmakelists.sh Script**

You will need to create the CMakeLists.txt file:

```bash
./generate-cmakelists.sh
```

## **Running the change-compiler.sh Script**

Tell CMake which compiler you want to use:

```bash
./change-compiler.sh -c <compiler>
```

To the see the list of possible compilers:

```bash
cat supported_c_compilers.txt
```

## **Running the build.sh Script**

To build the library run:

```bash
./build.sh
```

## **Running the install.sh Script**

To install the library run:

```bash
./install.sh
```

You may need to run it via sudo, or give the user account access to the install directories.
