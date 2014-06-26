#!/bin/sh

gnuplot << EOT
set grid

set logscale

set xlabel "number of nodes"
set ylabel "relativ Error"

set title "convergence plot of discrete geom. asien options with random walk"
plot "data_s3_16" using 1:4 with lp title "Monte Carlo", \
 "data_s3_16" using 1:5 with lp title "Quasi Monte Carlo", \
 "data_s3_16" using 2:6 with lp title "Product - Trapez", \
 "data_s3_16" using 2:7 with lp title "Product - Clensha Curtis", \
 "data_s3_16" using 3:8 with lp title "Sparse Grid - Trapez", \
 "data_s3_16" using 3:9 with lp title "Sparse Grid - Clensha Curtis"
pause mouse

set title "convergence plot of discrete geom. asien options with brownian bridge"
plot "data_s3_16" using 1:10 with lp title "Monte Carlo", \
 "data_s3_16" using 1:11 with lp title "Quasi Monte Carlo", \
 "data_s3_16" using 2:12 with lp title "Product - Trapez", \
 "data_s3_16" using 2:13 with lp title "Product - Clensha Curtis", \
 "data_s3_16" using 3:14 with lp title "Sparse Grid - Trapez", \
 "data_s3_16" using 3:15 with lp title "Sparse Grid - Clensha Curtis"
pause mouse

set term pdf

set output "sh3_task16_convergence_plot_rw.pdf"
set title "convergence plot of discrete geom. asien options with random walk"
plot "data_s3_16" using 1:4 with lp title "Monte Carlo", \
 "data_s3_16" using 1:5 with lp title "Quasi Monte Carlo", \
 "data_s3_16" using 2:6 with lp title "Product - Trapez", \
 "data_s3_16" using 2:7 with lp title "Product - Clensha Curtis", \
 "data_s3_16" using 3:8 with lp title "Sparse Grid - Trapez", \
 "data_s3_16" using 3:9 with lp title "Sparse Grid - Clensha Curtis"

set output "sh3_task16_convergence_plot_bb.pdf"
set title "convergence plot of discrete geom. asien options with brownian bridge"
plot "data_s3_16" using 1:10 with lp title "Monte Carlo", \
 "data_s3_16" using 1:11 with lp title "Quasi Monte Carlo", \
 "data_s3_16" using 2:12 with lp title "Product - Trapez", \
 "data_s3_16" using 2:13 with lp title "Product - Clensha Curtis", \
 "data_s3_16" using 3:14 with lp title "Sparse Grid - Trapez", \
 "data_s3_16" using 3:15 with lp title "Sparse Grid - Clensha Curtis"



EOT
#set term pdf color blacktext "Helvetica" 14
#set term postscript eps color blacktext "Helvetica" 14
