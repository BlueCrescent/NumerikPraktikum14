#!/bin/sh

gnuplot << EOT
set grid

set logscale x
set logscale y

set xlabel "N"
set ylabel "relativ Error"

set title "convergence plot for d = 1"
plot "data_s3_13_d=1" using 9:2 with lp title "Monte Carlo", \
 "data_s3_13_d=1" using 9:3 with lp title "Quasi Monte Carlo", \
 "data_s3_13_d=1" using 1:4 with lp title "Product - Trapez", \
 "data_s3_13_d=1" using 1:5 with lp title "Product - Clensha Curtis", \
 "data_s3_13_d=1" using 6:7 with lp title "Sparse Grid - Trapez", \
 "data_s3_13_d=1" using 6:8 with lp title "Sparse Grid - Clensha Curtis"
pause mouse

set title "convergence plot for d = 2"
plot "data_s3_13_d=2" using 9:2 with lp title "Monte Carlo", \
 "data_s3_13_d=2" using 9:3 with lp title "Quasi Monte Carlo", \
 "data_s3_13_d=2" using 1:4 with lp title "Product - Trapez", \
 "data_s3_13_d=2" using 1:5 with lp title "Product - Clensha Curtis", \
 "data_s3_13_d=2" using 6:7 with lp title "Sparse Grid - Trapez", \
 "data_s3_13_d=2" using 6:8 with lp title "Sparse Grid - Clensha Curtis"
pause mouse

set title "convergence plot for d = 4"
plot "data_s3_13_d=4" using 9:2 with lp title "Monte Carlo", \
 "data_s3_13_d=4" using 9:3 with lp title "Quasi Monte Carlo", \
 "data_s3_13_d=4" using 1:4 with lp title "Product - Trapez", \
 "data_s3_13_d=4" using 1:5 with lp title "Product - Clensha Curtis", \
 "data_s3_13_d=4" using 6:7 with lp title "Sparse Grid - Trapez", \
 "data_s3_13_d=4" using 6:8 with lp title "Sparse Grid - Clensha Curtis"
pause mouse

set title "convergence plot for d = 8"
plot "data_s3_13_d=8" using 9:2 with lp title "Monte Carlo", \
 "data_s3_13_d=8" using 9:3 with lp title "Quasi Monte Carlo", \
 "data_s3_13_d=8" using 1:4 with lp title "Product - Trapez", \
 "data_s3_13_d=8" using 1:5 with lp title "Product - Clensha Curtis", \
 "data_s3_13_d=8" using 6:7 with lp title "Sparse Grid - Trapez", \
 "data_s3_13_d=8" using 6:8 with lp title "Sparse Grid - Clensha Curtis"
pause mouse


set term pdf

set output "sh3_task13_convergencePlotd1.pdf"
set title "convergence plot for d = 1"
plot "data_s3_13_d=1" using 9:2 with lp title "Monte Carlo", \
 "data_s3_13_d=1" using 9:3 with lp title "Quasi Monte Carlo", \
 "data_s3_13_d=1" using 1:4 with lp title "Product - Trapez", \
 "data_s3_13_d=1" using 1:5 with lp title "Product - Clensha Curtis", \
 "data_s3_13_d=1" using 6:7 with lp title "Sparse Grid - Trapez", \
 "data_s3_13_d=1" using 6:8 with lp title "Sparse Grid - Clensha Curtis"

set output "sh3_task13_convergencePlotd2.pdf"
set title "convergence plot for d = 2"
plot "data_s3_13_d=2" using 9:2 with lp title "Monte Carlo", \
 "data_s3_13_d=2" using 9:3 with lp title "Quasi Monte Carlo", \
 "data_s3_13_d=2" using 1:4 with lp title "Product - Trapez", \
 "data_s3_13_d=2" using 1:5 with lp title "Product - Clensha Curtis", \
 "data_s3_13_d=2" using 6:7 with lp title "Sparse Grid - Trapez", \
 "data_s3_13_d=2" using 6:8 with lp title "Sparse Grid - Clensha Curtis"

set output "sh3_task13_convergencePlotd4.pdf"
set title "convergence plot for d = 4"
plot "data_s3_13_d=4" using 9:2 with lp title "Monte Carlo", \
 "data_s3_13_d=4" using 9:3 with lp title "Quasi Monte Carlo", \
 "data_s3_13_d=4" using 1:4 with lp title "Product - Trapez", \
 "data_s3_13_d=4" using 1:5 with lp title "Product - Clensha Curtis", \
 "data_s3_13_d=4" using 6:7 with lp title "Sparse Grid - Trapez", \
 "data_s3_13_d=4" using 6:8 with lp title "Sparse Grid - Clensha Curtis"

set output "sh3_task13_convergencePlotd8.pdf"
set title "convergence plot for d = 8"
plot "data_s3_13_d=8" using 9:2 with lp title "Monte Carlo", \
 "data_s3_13_d=8" using 9:3 with lp title "Quasi Monte Carlo", \
 "data_s3_13_d=8" using 1:4 with lp title "Product - Trapez", \
 "data_s3_13_d=8" using 1:5 with lp title "Product - Clensha Curtis", \
 "data_s3_13_d=8" using 6:7 with lp title "Sparse Grid - Trapez", \
 "data_s3_13_d=8" using 6:8 with lp title "Sparse Grid - Clensha Curtis"
pause mouse

EOT
#set term pdf color blacktext "Helvetica" 14
#set term postscript eps color blacktext "Helvetica" 14
