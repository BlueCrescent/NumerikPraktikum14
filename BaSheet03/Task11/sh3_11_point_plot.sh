#!/bin/sh

gnuplot << EOT
set grid

set xlabel "x"
set ylabel "y"

set title "Nodes of 2D trapezoidal sparse grid with l = 5"
plot "data_sh3_11_trapezoidal_l=5" using 1:2 with p lt rgb "red" notitle
pause mouse

set title "Nodes of 2D Clenshaw-Curtis sparse grid with l = 5"
plot "data_sh3_11_clenshawCurtis_l=5" using 1:2 with p lt rgb "green" notitle
pause mouse

set title "Nodes of 2D trapezoidal sparse grid with l = 7"
plot "data_sh3_11_trapezoidal_l=7" using 1:2 with p lt rgb "red" notitle
pause mouse

set title "Nodes of 2D Clenshaw-Curtis sparse grid with l = 7"
plot "data_sh3_11_clenshawCurtis_l=7" using 1:2 with p lt rgb "green" notitle
pause mouse

set term gif

set output "sh3_task11_point_plot_trapezoidal_l=5.gif"
set title "Nodes of 2D trapezoidal sparse grid with l = 5"
plot "data_sh3_11_trapezoidal_l=5" using 1:2 with p lt rgb "red" notitle
set output "sh3_task11_point_plot_clenshawCurtis_l=5.gif"
set title "Nodes of 2D Clenshaw-Curtis sparse grid with l = 5"
plot "data_sh3_11_clenshawCurtis_l=5" using 1:2 with p lt rgb "green" notitle
set output "sh3_task11_point_plot_trapezoidal_l=6.gif"
set title "Nodes of 2D trapezoidal sparse grid with l = 7"
plot "data_sh3_11_trapezoidal_l=7" using 1:2 with p lt rgb "red" notitle
set output "sh3_task11_point_plot_clenshawCurtis_l=7.gif"
set title "Nodes of 2D Clenshaw-Curtis sparse grid with l = 7"
plot "data_sh3_11_clenshawCurtis_l=7" using 1:2 with p lt rgb "green" notitle

set term pdf

set output "sh3_task11_point_plot_trapezoidal_l=5.pdf"
set title "Nodes of 2D trapezoidal sparse grid with l = 5"
plot "data_sh3_11_trapezoidal_l=5" using 1:2 with p lt rgb "red" notitle
set output "sh3_task11_point_plot_clenshawCurtis_l=5.pdf"
set title "Nodes of 2D Clenshaw-Curtis sparse grid with l = 5"
plot "data_sh3_11_clenshawCurtis_l=5" using 1:2 with p lt rgb "green" notitle
set output "sh3_task11_point_plot_trapezoidal_l=6.pdf"
set title "Nodes of 2D trapezoidal sparse grid with l = 7"
plot "data_sh3_11_trapezoidal_l=7" using 1:2 with p lt rgb "red" notitle
set output "sh3_task11_point_plot_clenshawCurtis_l=7.pdf"
set title "Nodes of 2D Clenshaw-Curtis sparse grid with l = 7"
plot "data_sh3_11_clenshawCurtis_l=7" using 1:2 with p lt rgb "green" notitle

EOT
#set term pdf color blacktext "Helvetica" 14
#set term postscript eps color blacktext "Helvetica" 14
