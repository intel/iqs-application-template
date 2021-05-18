# Template for Intel-QS application

Example of a quantum computing application using
[Intel Quantum Simulator](https://github.com/iqusoft/intel-qs)
for the numerical study.


### Installation

```bash
mkdir build
cd build
cmake -DIqsAppUtest=OFF .
make -j 4
```


### Circuit for the example

This simple example implement the gearbox circuit from:
  Wiebe, N. \& Kliuchnikov, V. "Floating point representations in quantum circuit synthesis" New J. Phys. 15, 093041 (2013)
that is open access at this
[link](http://iopscience.iop.org/article/10.1088/1367-2630/15/9/093041/meta).
