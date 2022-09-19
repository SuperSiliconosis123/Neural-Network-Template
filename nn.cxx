/* 
 *                                        A General Template for a Neural Network using the Genetic Algorithm
 * 
 * Settings:
 *   NODE_SIZE:
 *     the size of the variable used for the node
 *     1 = unsigned char
 *     2 = unsigned int
 *     3 = unsigned long long int
 *   LAYERS:
 *     The number of layers of nodes between the input and output layers, aka the hidden layers, non-inclusive.
 *   TRIALS:
 *     The number of trials eahc generation should go through, or rather how many times the parent network should reproduce
 *   INPUT_NODES:
 *     The number of nodes in the input layer.
 *   MIDDLE_NODES:
 *     The number of nodes in each of the middle/hidden layers.
 *   OUTPUT_NODES:
 *     The number of nodes in the output layer.
 *
 * Functions:
 *   int evaluate (int trial):
 *     determines the outcome of a neural network. returns the 
 *
 */
#include <iostream>
#include <string>
using namespace std;


//general program settings
#define NODE_SIZE 3
#define LAYERS 1
#define TRIALS 3

#define INPUT_NODES 10
#define MIDDLE_NODES 30
#define OUTPUT_NODES 10


//implement the settings
#if LAYERS == 0
#error "LAYERS out of range"
#endif
#if NODE_SIZE == 1
struct {
  unsigned char input [INPUT_NODES];
  unsigned char middle [TRIALS] [LAYERS] [MIDDLE_NODES];
  unsigned char output [TRIALS] [OUTPUT_NODES];
} nodes;
struct {
  unsigned char input [TRIALS] [INPUT_NODES] [MIDDLE_NODES];
  #if LAYERS > 1
  unsigned char middle [TRIALS] [LAYERS-1] [MIDDLE_NODES] [MIDDLE_NODES];
  #endif
  unsigned char ouTput [TRIALS] [MIDDLE_NODES] [OUTPUT_NODES];
} wires;
#elif NODE_SIZE == 2
struct {
  unsigned int input [INPUT_NODES];
  unsigned int middle [TRIALS] [LAYERS] [MIDDLE_NODES];
  unsigned int output [TRIALS] [OUTPUT_NODES];
} nodes;
struct {
  unsigned int input [TRIALS] [INPUT_NODES] [MIDDLE_NODES];
  #if LAYERS > 1
  unsigned int middle [TRIALS] [LAYERS-1] [MIDDLE_NODES] [MIDDLE_NODES];
  #endif
  unsigned int ouTput [TRIALS] [MIDDLE_NODES] [OUTPUT_NODES];
} wires;
#elif NODE_SIZE == 3
struct {
  unsigned long long int input [INPUT_NODES];
  unsigned long long int middle [TRIALS] [LAYERS] [MIDDLE_NODES];
  unsigned long long int output [TRIALS] [OUTPUT_NODES];
} nodes;
struct {
  unsigned long long int input [TRIALS] [INPUT_NODES] [MIDDLE_NODES];
  #if LAYERS > 1
  unsigned long long int middle [TRIALS] [LAYERS-1] [MIDDLE_NODES] [MIDDLE_NODES];
  #endif
  unsigned long long int output [TRIALS] [MIDDLE_NODES] [OUTPUT_NODES];
} wires;
#else
#error "NODE_SIZE out of range"
#endif

struct {
  double input [TRIALS] [INPUT_NODES] [MIDDLE_NODES];
  #if LAYERS > 1
  double middle [TRIALS] [LAYERS-1] [MIDDLE_NODES] [MIDDLE_NODES];
  #endif
  double output [TRIALS] [OUTPUT_NODES] [MIDDLE_NODES];
} weights;

int evaluate(int trial) {
  for(int i = 0; i < INPUT_NODES; i++) {
    for(int x = 0; x < MIDDLE_NODES; x++) {
      wires.input[trial][i][x] = (nodes.input[i] * weights.input[trial][i][x])/INPUT_NODES;
    }
  }
  for(int i = 0; i < MIDDLE_NODES; i++) {
    for(int x = 0; x < INPUT_NODES; x++) {
      nodes.middle[trial][0][i] += wires.input[trial][x][i] / (INPUT_NODES * MIDDLE_NODES);
    }
  }
  #if LAYERS > 1
  for(int i = 0; i < LAYERS - 1; i++) {
    for(int x = 0; x < MIDDLE_NODES; x++) {
      for(int y = 0; y < MIDDLE_NODES; y++) {
        wires.middle[trial][i][x][y] = (nodes.middle[trial][i][y] * weights.middle[trial][i][x])/INPUT_NODES;
      }
    }
    for(int i = 0; i < MIDDLE_NODES; i++) {
      for(int x = 0; x < INPUT_NODES; x++) {
        nodes.middle[trial][0][i] += wires.middle[trial][i][x][y] / (MIDDLE_NODES ^ 2);
      }
    }
  }
  #endif
  for(int i = 0; i < MIDDLE_NODES; i++) {
    for(int x = 0; x < OUTPUT_NODES; x++) {
      wires.output[trial][i][x] = (nodes.middle[trial][-1][i][x] * weights.output[trial][i][x])/INPUT_NODES;
    }
  }
  for(int i = 0; i < MIDDLE_NODES; i++) {
    for(int x = 0; x < INPUT_NODES; x++) {
      node.middle[trial][0][i] += wires.input[trial][x][i] / (OUTPU_NODES_NODES * MIDDLE_NODES);
    }
  }
  return 0;
}

int main() {
  return 0;
};
