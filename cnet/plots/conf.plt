#!/usr/local/bin/gnuplot --persist -c
# USAGE:
# ./conf.plt path/to/data.dat
# Expects a 10 x 10 Confusion Matrix

FILE = ARG1

set title "Confusion Matrix" 
set cblabel "Score"
unset key

set autoscale yfix
set autoscale xfix

set xlabel "Predicted"
set xrange [ -0.500000 : 9.50000 ] noreverse nowriteback
set x2range [ * : * ] noreverse writeback
set xtics border in scale 0,0 mirror norotate  autojustify
set xtics (\
    "Digit 9" 9.0,\
    "Digit 8" 8.0,\
    "Digit 7" 7.0,\
    "Digit 6" 6.0,\
    "Digit 5" 5.0,\
    "Digit 4" 4.0,\
    "Digit 3" 3.0,\
    "Digit 2" 2.0,\
    "Digit 1" 1.0,\
    "Digit 0" 0.0)


set ylabel "Real"
set yrange [ -0.500000 : 9.50000 ] reverse nowriteback
set y2range [ * : * ] reverse writeback
set ytics border in scale 0,0 mirror norotate  autojustify
set ytics (\
    "Digit 9" 9.0,\
    "Digit 8" 8.0,\
    "Digit 7" 7.0,\
    "Digit 6" 6.0,\
    "Digit 5" 5.0,\
    "Digit 4" 4.0,\
    "Digit 3" 3.0,\
    "Digit 2" 2.0,\
    "Digit 1" 1.0,\
    "Digit 0" 0.0)

set pm3d map

splot FILE matrix with image
