#!/bin/sh

gnuplot << EOT
set logscale
set grid

set title "discrete geometric average simulation convergence"
set xlabel "Num simulations"
set ylabel "relative error"

plot "data_s3_03_M10" using 1:2 with l title "M = 10", \
"data_s3_03_M200" using 1:2 with l title "M = 200"

pause mouse

set term gif
set output "sh3_task3_convergence_plot.gif"

plot "data_s3_03_M10" using 1:2 with l title "M = 10", \
"data_s3_03_M200" using 1:2 with l title "M = 200"

set term postscript eps color blacktext "Helvetica" 14
set output 'sh3_task3_convergence_plot.eps'

plot "data_s3_03_M10" using 1:2 with l title "M = 10", \
"data_s3_03_M200" using 1:2 with l title "M = 200"
EOT

