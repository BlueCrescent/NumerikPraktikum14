#!/bin/sh

gnuplot << EOT

set title "estimation of mean of call-option prices"
set xlabel "delta t"
set ylabel "mean / variance estimation"


plot "data_sh2_2" using 1:3 pt 7 ps 2 title "variance estimation", \
     "data_sh2_2" using 1:2 pt 7 ps 1 title "mean estimation"


pause mouse

set term gif
set output "sh2_task2_variance_estimates_plot.gif"

plot "data_sh2_2" using 1:3 pt 7 ps 2 title "variance estimation", \
     "data_sh2_2" using 1:2 pt 7 ps 1 title "mean estimation"

set term postscript eps color blacktext "Helvetica" 14
set output 'sh2_task2_variance_estimates_plot.eps'

plot "data_sh2_2" using 1:3 pt 7 ps 2 title "variance estimation", \
     "data_sh2_2" using 1:2 pt 7 ps 1 title "mean estimation"

EOT
