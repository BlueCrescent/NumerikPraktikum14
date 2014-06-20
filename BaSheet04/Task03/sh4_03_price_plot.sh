#!/bin/sh

gnuplot << EOT

set grid

set title "Plot of Down-Out Call option prices with different barriers."
set xlabel "barrier"
set ylabel "fair price"

plot "data_s4_03" using 1:2 with lp notitle
pause mouse

set term pdf
set output 'sh4_task3_price_plot.pdf'

plot "data_s4_03" using 1:2 with lp notitle
EOT

