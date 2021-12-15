set xlabel "thread"
set ylabel "time"
set title "euler at n=500"
plot "./data/thread" using 1:2 title "thread vs parallel euler" w l
replot "./data/thread" using 1:3 title "thread vs series euler" w l
replot "./data/thread" using 1:6 title "speed up" w l
pause -1 "Hit" 
set title "leibniz at n=1000000000"
plot "./data/thread" using 1:4 title "thread vs parallel leibniz" w l
replot "./data/thread" using 1:5 title "thread vs series leibniz" w l
replot "./data/thread" using 1:7 title "speed up" w l
pause -1 "Hit"

