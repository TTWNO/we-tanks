# We Tank

This is a proof-of-concept implementation based off of the Wii Play: Tanks game.

Written with the SFML framework.

## Features:
Prints a red circle roughly in the middle of the window.

### Compiling
During development, binaries will not be released. Please compile on your own system.

#### Linux:
For Linux, it's just run `make`.

#### Windows:
I'm not 100% sure if it'll work on Windows. The make file should work IF you have the GCC C++ compiler installed. Although the paths may need backslashes to work properly.
I really don't know how to get the mvsc compiler to work, but I'm sure it'll be dealt with soon.

#### Mac:
Run `make` with the GCC C++ compiler installed.

##### Note:
The SFML framework is compatible with all compilers. So it only takes minimal editing of the Makefile to get this to work on other systems.

### Running

Run `make run`, because it has to set an environment variable before executing the binary.
You can run it yourself if you set `LD_LIBRARY_PATH=/path/to/SFML/lib/dir`, then run the produced binary.

On linux, this is `make linux-run`
