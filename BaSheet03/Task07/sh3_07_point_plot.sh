#!/bin/sh

gnuplot << EOT
set grid

set title "Halton vs. UniformS"
set xlabel "x"
set ylabel "y"

plot "data_s3_07_halton" using 1:2 with p title "Halton sequence", \
"data_s3_07_uniform" using 1:2 with p title "uniform random"

pause mouse

set term pdf
set output 'sh3_task7_point_plot.pdf'

plot "data_s3_07_halton" using 1:2 with p title "Halton sequence", \
"data_s3_07_uniform" using 1:2 with p title "uniform random"
EOT

