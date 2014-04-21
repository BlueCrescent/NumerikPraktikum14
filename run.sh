#!/bin/sh

mkdir -p Output/Data
cd Output/Data

../../Release/NumerikPraktikum14

octave << EOT
source ("../../BaSheet01/Task03/plot_script.m");
k = waitforbuttonpress;
EOT
mv task3plot.eps ../task3plot.eps

../../BaSheet01/Task09/task9convPlot.sh
mv task9_convergence_plot.gif ../task9_convergence_plot.gif
mv task9_convergence_plot.eps ../task9_convergence_plot.eps

../../BaSheet01/Task10/task10processPlot.sh
mv task10_process_plot.gif ../task10_process_plot.gif
mv task10_process_plot.eps ../task10_process_plot.eps
mv task10_wiener_plot.gif  ../task10_wiener_plot.gif
mv task10_wiener_plot.eps  ../task10_wiener_plot.eps

