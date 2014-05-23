#!/bin/sh

gnuplot << EOT
set grid

set logscale y

set xlabel "d"
set ylabel "number of nodes"

set title "Number of nodes in product and sparse grid with l = 4 and different dimensions"
plot "data_sh3_12_num_of_nodes" using 1:2 with p lt rgb "red" title "product rule", \
"data_sh3_12_num_of_nodes" using 1:3 with p lt rgb "blue" title "sparse grid"
pause mouse

set term gif

set output "sh3_task12_num_of_nodes.gif"
set title "Number of nodes in product and sparse grid with l = 4 and different dimensions"
plot "data_sh3_12_num_of_nodes" using 1:2 with p lt rgb "red" title "product rule", \
"data_sh3_12_num_of_nodes" using 1:3 with p lt rgb "blue" title "sparse grid"
pause mouse

set term pdf

set output "sh3_task12_num_of_nodes.pdf"
set title "Number of nodes in product and sparse grid with l = 4 and different dimensions"
plot "data_sh3_12_num_of_nodes" using 1:2 with p lt rgb "red" title "product rule", \
"data_sh3_12_num_of_nodes" using 1:3 with p lt rgb "blue" title "sparse grid"
pause mouse

EOT
#set term pdf color blacktext "Helvetica" 14
#set term postscript eps color blacktext "Helvetica" 14
