#!/bin/sh

gnuplot << EOT

set title "estimation of mean of call-option prices"
set xlabel "sigma"
set ylabel "mean estimation"


plot "data_sh2_1" using 1:2 pt 7 ps 2 notitle


pause mouse

set term gif
set output "sh2_task1_mean_estimates_plot.gif"

plot "data_sh2_1" using 1:2 pt 7 ps 2 notitle

set term postscript eps color blacktext "Helvetica" 14
set output 'sh2_task1_mean_estimates_plot.eps'

plot "data_sh2_1" using 1:2 pt 7 ps 2 notitle

EOT
