DESCRIPTION:
Program to generate PNG files of Bohr atomic models of all elements in the periodic table.


USAGE AND OUTPUT:
usage: orbitals <image-size> <background-colour>

<image-size> is the size of the image. For optimal display, a size of greater than 1250px is recommended. 

<background-color> refers to the amount of black in the background. A value of 0.0 will give a white background while 1.0 while give a black background. Transparent backgrounds are not supported (due to limitations of the PNGWriter library).

The output files will be named after the symbol of the element. Eg: 'Au.png' for gold.

Tested on Ubuntu 13.10 x86 with gcc 4.8.1.

PREREQUISITES:
Requires the PNGwriter library (http://pngwriter.sourceforge.net/).


LICENSE:
See LICENSE.md for license information.
