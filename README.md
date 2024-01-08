# Handling-dynamic-structures-in-C

## Overview
In this practical work, we would like to simulate the organization and sharing of the central memory (RAM) among multiple programs running in parallel on the same computer. To achieve this, we will use structures of singly linked lists and queues. A program admitted to execution is called a process and must be loaded into RAM.

It is assumed that memory is shared in partitions of variable sizes. A partition is a contiguous memory space with a starting address (where the partition begins), a size in number of bytes, and a state (free or occupied).

We consider that the description of memory partitions is found in a simple linked list with the entry point T, in ascending order of partition addresses


## Get Started

To get started with this project, follow the steps below:

1. **Clone the Repository**

2. **Install the Dependencies**:

   *Note: The following instructions are for Arch Linux-based distributions only.*

    1. install and set up raylib dependencies
        ```bash
        sudo pacman -Syu && sudo pacman -S make alsa-lib mesa libx11 libxrandr libxi libxcursor libxinerama
        ```
        - *note: if you are on wayland make sure to download this too*:
            ```bash
                sudo pacman -S wayland libxkbcommon wayland-protocols
            ```
    2. build the dynamic shared library:
        ```bash
            git clone https://github.com/raysan5/raylib.git raylib
            cd raylib
            mkdir build && cd build
            cmake -DBUILD_SHARED_LIBS=ON -DUSE_WAYLAND=ON ..
            make
            sudo make install
        ```
    3. add the LD_LIBRARY to your path (.zshrc or .bashrc):
        make sure to add the directory where you find the `librarylib.so.450` file
        ```bash
            export LD_LIBRARY_PATH=<your_path_to_raylib>/raylib/raylib/:$LD_LIBRARY_PATH
        ```
        after that simply run 
        ```bash
            source .zshrc
        ```
4. **Run the project**:
    - run this project simply by running
        ```bash
            make
        ```
    **note: make sure to be in the root directory**

5. **Contribution**:
    1. **fork the repository**
    2. **create your branch**
        ```bash
            git branch -M <your_name>
        ```
    3. **push your changes**
    4. **open a pull request and wait for the review**

6. **Resources**
    - [makefile](http://retis.sssup.it/~luca/makefiles.pdf)
    - [Raylib](https://www.raylib.com)
    - [Raylib wiki](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux)
