DISCONTINUATION OF PROJECT

This project will no longer be maintained by Intel.

Intel has ceased development and contributions including, but not limited to, maintenance, bug fixes, new releases, or updates, to this project.  

Intel no longer accepts patches to this project.

If you have an ongoing need to use this project, are interested in independently developing it, or would like to maintain patches for the open source software community, please create your own fork of this project.  

Contact: webadmin@linux.intel.com
# Template for Intel-QS application

Example of a quantum computing application using
[Intel Quantum Simulator](https://github.com/iqusoft/intel-qs)
for the numerical study.


### Installation

This repository include IQS as submodule. It is recommended to clone it with:
```bash
git clone --recurse-submodules git@github.com:iqusoft/iqs-application-template.git
```

To install it, once in the main repo dir type:
```bash
mkdir build
cd build
cmake -DIqsAppUtest=OFF ..
make -j 4
```

**NOTE:** To enable all functionalities, update git to its 2.17+ version.


### Circuit for the example

This simple example implement the gearbox circuit from:

   Wiebe, N. \& Kliuchnikov, V.
   *Floating point representations in quantum circuit synthesis*
   [New J. Phys. 15, 093041 (2013)](http://iopscience.iop.org/article/10.1088/1367-2630/15/9/093041/meta)

As an interesting exercise, consider extending the gearbox circuit to its
conditional form, following:

   Guerreschi, G. G.
   *Repeat-Until-Success circuits with fixed-point oblivious amplitude amplification*
   [Phys. Rev. A 99, 022306 (2019)](https://arxiv.org/abs/1808.02900)
