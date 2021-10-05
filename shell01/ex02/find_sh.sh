#/bin/sh
find . -type f -name *.sh -printf %f'\n'| rev | cut -d. -f2- | rev
