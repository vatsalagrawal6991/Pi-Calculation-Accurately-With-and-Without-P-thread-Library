# Made BY VATSAL AGRAWAL

# Pi-Calculation-Accurately-With-and-Without-P-thread-Library
PI- 3.14 calculation using Leibniz and Euler Method with p thread library and normal and done comparison between them

How To Make Executable and Run Programme
1) Unzip File at location x
2) Open Terminal and change directory to that location x
3) Now enter command make.
This will create Executables
4) Enter Command make run to run the executables
5) Give arguments by writing ./all.out followed by arguments

Problem Question

writing and debugging multithreaded
C pthreads programs, using synchronization primitives, and experience designing and running
scalability experiments.
Use any two numerical methods to calculate the value of p. Some of the popular methods are
described in this reference:
https://ieeexplore.ieee.org/document/6298658

Software Specifications:
- The inputs should only be taken through the command line arguments only not by
using scanf or any similar methods.
- The command line arguments for assignment-2 are in the following order:
<executable_name> <number_of_threads> <number_of_iterations>
- The output should show us the following parameters:
- Accuracy
- Speedup
- Exact number of bits
- Time taken
- For assignment-2, below should have the below make targets:
- build : compile the source code and build the executable file from the object
file.
- run : execute the code with command line arguments passed through the
command line.
- clean : delete the executable and object file generated.
- plot : plot the graph using the data collected during experimentation.


Result
1) I have implemented Euler and Leibniz method in both serial and
parallel form
2) I have tweaked parallel computation to avoid unnecessary
computation by taking out variables that are calculated every time
in each thread
3) Accuracy of serial and parallel in Euler for the same value of
iteration is found to be the same
4) Accuracy of serial and parallel in Leibniz for the same value of
iteration is found to be the same
5) The Accuracy of Euler is found to be more on n =200 as compared
to the Accuracy of Leibniz on n = 109
6) Speed_UP of running Euler in for parallel is negative as compared
to running Euler in Series
this is because less no of computation is involved and large
overhead of threading and concurrency
7) Speed_UP of running Leibniz in for parallel is positive as compared
to running Leibniz in Series.
It is found to be 2X times for a large value of n = 1010
This is because other cores of computers are also utilized for the
calculation
8) A sample running screenshot of the Programme is given below
9) Time for Euler to calculate pi is also less than the time to calculate
pi for Leibniz
10) We found no of bits which are same in both serial and parallel
computation is same in both algo
11) The result given below is for n =1000000000 for Leibniz and
thread number =10
12) The result given below is for n =500 for Euler and thread
number =10
Fig3. Running Screenshot 1
Note Accuracy = 􀭓􀭠􀭱􀭣􀭰􀭴􀭣􀭢 􀭴􀭟􀭪􀭳􀭣
􀭅􀭡􀭲􀭳􀭟􀭪 􀭴􀭟􀭪􀭳􀭣
= 􀮾􀯥􀯥􀯢􀯥
􀮺􀯖􀯧􀯨􀯔􀯟 􀯏􀯔􀯟􀯨􀯘
Error =
frexp() – is used to get the trailing no of 0 after the
decimal. Also, it gives an exponent of the error, which
is expressed in the power of 2
Conclusion
1) Both Parallel and Serial versions give the same accuracy/error
almost for the same no of iteration for the same method – if the
implementation is the same
2) Leibniz converges very slow in comparison to Euler for the value
of pi
3) For the small value of n, Euler has significantly less error, while for
the very large value of n, Leibniz has a significant error
4) For a very large value of n, Leibniz does not come as close to pi as
Euler comes in only 200 iteration
5) For small iteration in Leibniz, it does not give the correct value of
pi
6) The parallel speedup can be obtained if we tweak algo such that
useless calculation is not calculated in every thread in Leibniz
7) Euler can show speedup for parallel for very large value of n,
which is not necessary
8) Serial compuatation is preferred for Euler while parallel
computation is preferred for Leibniz
9) Leibniz show speed up in its computation due to large value of n
10) Exact no of bits is more in Euler as compared to Leibniz
11) Also, the exact number of bits is found to be the same for both
serial and parallel computation in both algo
12) Time taken to run Euler to get high accuracy is very much less
than the time taken by Leibniz to get that accuracy
13) The accuracy which is achieved by Euler in 1 s is not achieved
by Leibniz in 100 sec also
14) From the above graph and table, it is found that a value of 500
for iteration of Euler would be perfect for getting high accuracy up
to 15 decimal digits
15) From the above graph and table, it is seen that a value of
1000000000 for iteration of Leibniz would be perfect for getting
high accuracy up to 8 decimal digits keeping in mind the time
taken to compute it
16) Most of the time, the speedup is of about 2 in Leibniz
17) From the graph and table below, we can clearly see that max
speed up for Leibniz at n=109 is achieved at thread = 8
18) But also, it can be seen that for almost any value of thread >2,
the speed is almost the same for Leibniz
This is because our CPU has two cores
19) Also, for Euler at n=500, we can clearly see that max speed up
is obtained at thread = 4
20) But also it can be seen that for almost any value of thread >2,
the speed is almost the same for Euler also
thread Parallel
