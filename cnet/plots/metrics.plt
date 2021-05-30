#!/usr/local/bin/gnuplot --persist -c
# USAGE:
# ./metrics.plt path/to/data.dat
# Expected row format
# train_loss val_loss train_metric val_metric

FILE = ARG1
set key outside;

# Loss plot
set title "Loss";
set terminal qt 0;
plot FILE using 0:1 with lines title 'Train Loss',\
     FILE using 0:2 with lines title 'Val loss'

# Metrics plot
set title "Metric";
set terminal qt 1;
plot FILE using 0:3 with lines title 'Train Metric',\
     FILE using 0:4 with lines title 'Val Metric'
