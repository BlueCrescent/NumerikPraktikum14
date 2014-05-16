#!/bin/sh

gnuplot << EOT
set grid

set xlabel "x"
set ylabel "y"

set title "Nodes of 2D trapezoidal product rules"
plot "data_sh3_09_trapezoidal" using 1:2 with p lt rgb "red"
pause mouse

set title "Nodes of 2D Gauss-Legendre product rules"
plot "data_sh3_09_gaussLegendre" using 1:2 with p lt rgb "blue"
pause mouse

set title "Nodes of 2D Clenshaw-Curtis product rules"
plot "data_sh3_09_clenshawCurtis" using 1:2 with p lt rgb "green"
pause mouse

set term gif

set output "sh3_task9_point_plot_trapezoidal.gif"
set title "Nodes of 2D trapezoidal product rules"
plot "data_sh3_09_trapezoidal" using 1:2 with p lt rgb "red"
set output "sh3_task9_point_plot_gaussLegendre.gif"
set title "Nodes of 2D Gauss-Legendre product rules"
plot "data_sh3_09_gaussLegendre" using 1:2 with p lt rgb "blue"
set output "sh3_task9_point_plot_clenshawCurtis.gif"
set title "Nodes of 2D Clenshaw-Curtis product rules"
plot "data_sh3_09_clenshawCurtis" using 1:2 with p lt rgb "green"

set term pdf color blacktext "Helvetica" 14

set output 'sh3_task9_point_plot_trapezoidal.pdf'
set title "Nodes of 2D trapezoidal product rules"
plot "data_sh3_09_trapezoidal" using 1:2 with p lt rgb "red"
set output 'sh3_task9_point_plot_gaussLegendre.pdf'
set title "Nodes of 2D Gauss-Legendre product rules"
plot "data_sh3_09_gaussLegendre" using 1:2 with p lt rgb "blue"
set output 'sh3_task9_point_plot_clenshawCurtis.pdf'
set title "Nodes of 2D Clenshaw-Curtis product rules"
plot "data_sh3_09_clenshawCurtis" using 1:2 with p lt rgb "green"

EOT

#set term postscript eps color blacktext "Helvetica" 14
