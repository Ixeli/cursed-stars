# Cursed Stars
A silly little demo, made to practice working with ncurses and multiple-file C projects.

## Dependencies
For now, the only dependency is ncurses, which should already be installed on most *nix systems.
(You'll also need a way to compile code, but any system with ```make``` and a C compiler (preferably GCC) shouldn't have too much trouble.

## Building
The build process is extremely simple if you don't want to mess with the configuration:
```
git clone https://github.com/Ixeli/cursed-stars
cd cursed-stars
make
```
After that, the executable ```./cursed-stars``` contains all of the program's information. Where you decide to put it shouldn't matter.

### Configuring
If you want to mess with the configuration before compiling (such as to modify the keybinds), you can do so by modifying ```src/config.h``` within your favorite editor *before* running ```make```. Each option contains a comment describing what it does.

## Controls
The default controls (if you don't modify src/config.h) are as follows:
- w to move forward
- s to move back
- z to move up
- x to move down
- a to look left
- d to look right
- q to quit
(Strafing may be added in the future?)

## Potential issues
I'm not aware of any major bugs with the program or build process. However, this code has only ever been tested on Debian 12 running on the amd64 architecture, so please inform me if it doesn't work on other machines!
It is intended to work well on any UNIX-like machine. MS-DOS/Windows support, along with other operating systems, may require additional effort. 
