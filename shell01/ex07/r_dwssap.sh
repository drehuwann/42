#!/bin/sh

cat /etc/passwd | sed -e 's/#.*//' -e 's/[ ^I]*$//' -e '/^$/ d' -e '1d' | \
    cut -d: -f1 | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | \
    tr '\n' '#'| sed -e 's/#/,\ /g' -e 's/, $/./' 
