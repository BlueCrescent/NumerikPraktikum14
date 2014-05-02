gnuplot << EOT

set title "estimation of call-option expectation"
set xrange [1:11]
set yrange [8.5:8.9]
set xlabel "level"
set ylabel "relative error"
set grid

set term gif
set output "task10_convergence_plot.gif"

plot "data_callF_Trapezodial_K=10" using 1:2 with l title "Trapezodial, K = 10", \
"data_callF_GaussLegendre_K=10" using 1:2 with l title "Gauss Legendre, K = 10", \
"data_callF_Clenshaw_K=10" using 1:2 with l title "Clenshaw Curtis, K = 10", \
"data_callF_MonteCarlo_K=10" using 1:2 with l title "Monte Carlo, K = 10", \
"data_callF_Trapezodial_K=0" using 1:2 with l title "Trapezodial, K = 0", \
"data_callF_GaussLegendre_K=0" using 1:2 with l title "Gauss Legendre, K = 0", \
"data_callF_Clenshaw_K=0" using 1:2 with l title "Clenshaw Curtis, K = 0", \
"data_callF_MonteCarlo_K=0" using 1:2 with l title "Monte Carlo, K = 0"

EOT
