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

set term pdf4
set output 'sh3_task3_convergence_plot.pdf'

plot "data_s3_03_M10" using 1:2 with l title "M = 10", \
"data_s3_03_M200" using 1:2 with l title "M = 200"
EOT

