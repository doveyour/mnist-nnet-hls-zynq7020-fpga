#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/dy/Desktop/20210510/hls/mnist/solution1/.autopilot/db/a.g.bc ${1+"$@"}