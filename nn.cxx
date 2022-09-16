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
  #if LAYERS > 2
  unsigned char middle [TRIALS] [LAYERS-2] [MIDDLE_NODES] [MIDDLE_NODES];
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
  #if LAYERS > 2
  unsigned int middle [TRIALS] [LAYERS-2] [MIDDLE_NODES] [MIDDLE_NODES];
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
  #if LAYERS > 2
  unsigned long long int middle [TRIALS] [LAYERS-2] [MIDDLE_NODES] [MIDDLE_NODES];
  #endif
  unsigned long long int output [TRIALS] [MIDDLE_NODES] [OUTPUT_NODES];
} wires;
#else
#error "NODE_SIZE out of range"
#endif

struct {
  double input [TRIALS] [INPUT_NODES] [MIDDLE_NODES];
  #if LAYERS > 2
  double middle [TRIALS] [LAYERS-2] [MIDDLE_NODES] [MIDDLE_NODES];
  #endif
  double output [TRIALS] [OUTPUT_NODES] [MIDDLE_NODES];
} weights;

int evaluate(int trial) {
  #if NODE_SIZE == 1
  unsigned char average;
  #elif NODE_SIZE == 2
  unsigned int average;
  #elif NODE_SIZE == 3
  unsigned long long int average;
  #enif
  for(int i = 0; i < INPUT_NODES; i++) {
    for(int x = 0; x < MIDDLE_NODES; x++) {
      wires.input[trial][i][x] = (nodes.input[i] * weights.input[trial][i][x])/INPUT_NODES;
    }
  }
  for(int i = 0; i < MIDDLE_NODES; i++) {
    for(int x = 0; i < INPUT_NODES; x++) {
      
    }
    node.middle[trial][0][i] = 
  }
  return 0;
}

int main() {
  return 0;
};
