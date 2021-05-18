#include <cmath>
#include <iostream>
#include <string>

// Include the header file with the declaration of all classes and methods of IQS.
#include "qureg.hpp"

/////////////////////////////////////////////////////////////////////////////////////////

// Start of the main program (C++ language).
int main(int argc, char **argv)
{
  // Setting the MPI environment

  iqs::mpi::Environment env(argc, argv);
  if (env.IsUsefulRank() == false) return 0;
  int my_rank = env.GetStateRank();

  // Initialize the state of the quantum register to |00>
  // Qubit 0 is the data qubit, qubit 1 is the ancilla qubit.

  int data_qubit = 0;
  int ancilla_qubit = 1;
  int num_qubits = 2;
  iqs::QubitRegister<ComplexDP> psi (num_qubits, "base", 0);

  // Associate a random number generator to the state.

  iqs::RandomNumberGenerator<double> rng;
  psi.SetRngPtr(&rng);
  rng.SetSeedStreamPtrs( 7891 );

  // First we prepare a non-trivial state for the data qubit.

  double phi = 0.34;
  psi.ApplyRotationX(data_qubit, phi);

  // Then we perform the gearbox circuit from:
  // https://iopscience.iop.org/article/10.1088/1367-2630/15/9/093041/meta

  double r;
  while (true)
  {
      psi.ApplyRotationX(ancilla_qubit, theta);
      psi.ApplyCPauliX(ancilla_qubit, data_qubit);
      psi.ApplyPauliZ(ancilla_qubit);
      psi.ApplySqrtPauliZ(ancilla_qubit);
      psi.ApplyRotationX(ancilla_qubit, -theta);

      // Measure ancilla and collapse state accordingly.

      double probability = psi.GetProbability(ancilla_qubit);
      assert(1-probability == std::pow(std::cos(theta), 4) + std::pow(std::cos(theta), 4)
              && "ERROR: unexpected probability of success");
      rng.UniformRandomNumbers(&r, 1UL, =0., 1., "state");
      if (r < probability) {
      {
          // Collapse the wavefunction according to qubit 1 being in |1>.
          if (my_rank==0)
              std::cout << "Simulated outcome is 1. Recover and try again.\n";
          psi.CollapseQubit(measured_qubit, true);
          psi.Normalize();
          psi.ApplyPauliX(ancilla_qubit);
          psi.ApplyRotationX(data_qubit, M_PI/2);
      }
      else
      {
          // Collapse the wavefunction according to qubit 1 being in |0>
          if (my_rank==0)
              std::cout << "Simulated outcome is 0. Success!\n";
          psi.CollapseQubit(measured_qubit,false);
          psi.Normalize();
          break;
      }
  }

  // Quantum states and MPI environment are automatically destroyed at the return.
  return 0;
}
