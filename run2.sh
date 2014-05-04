#!/bin/sh

mkdir -p Output/Data_s02
cd Output/Data_s02

../../Release/NumerikPraktikum14


../../BaSheet02/Task01/plot_mean_estimates.sh
mv sh2_task1_mean_estimates_plot.gif ../sh2_task1_mean_estimates_plot.gif
mv sh2_task1_mean_estimates_plot.eps ../sh2_task1_mean_estimates_plot.eps

../../BaSheet02/Task02/plot_variance_estimates.sh
mv sh2_task2_variance_estimates_plot.gif ../sh2_task2_variance_estimates_plot.gif
mv sh2_task2_variance_estimates_plot.eps ../sh2_task2_variance_estimates_plot.eps

../../BaSheet02/Task04/plot_mean_over_count.sh
mv sh2_task4_plot.gif ../sh2_task4_plot.gif
mv sh2_task4_plot.eps ../sh2_task4_plot.eps

../../BaSheet02/Task09/tasks2_09convPlot.sh
mv task9_convergence_plot.gif ../task9_convergence_plot.gif
mv task9_convergence_plot.eps ../task9_convergence_plot.eps

../../BaSheet02/Task10/tasks2_10convPlot.sh
mv task10_convergence_plot.gif ../task10_convergence_plot.gif
mv task10_convergence_plot.eps ../task10_convergence_plot.eps
