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
#if NODE_SIZE == 1
struct {
  unsigned char input [TRIALS] [INPUT_NODES];
  unsigned char middle [TRIALS] [LAYERS] [MIDDLE_NODES];
  unsigned char output [TRIALS] [OUTPUT_NODES];
} nodes;
#elif NODE_SIZE == 2
struct {
  unsigned int input [TRIALS] [INPUT_NODES];
  unsigned int middle [TRIALS] [LAYERS] [MIDDLE_NODES];
  unsigned int output [TRIALS] [OUTPUT_NODES];
} nodes;
#elif NODE_SIZE == 3
struct {
  unsigned long long int input [TRIALS] [INPUT_NODES];
  unsigned long long int middle [TRIALS] [LAYERS] [MIDDLE_NODES];
  unsigned long long int output [TRIALS] [OUTPUT_NODES];
} nodes;
#else
#error "NODE_SIZE out of range"
#endif

struct {
  double input [TRIALS] [INPUT_NODES];
  #if LAYERS < 1
  double middle [TRIALS] [LAYERS-1] [MIDDLE_NODES];
  #endif
  double output [TRIALS] [OUTPUT_NODES];
} wires;

int evaluate(int trial, 
#if NODE_SIZE == 1
char input[INPUT_NODES]
#elif
            ) {
  
  return 0;
}

int main() {
  return 0;
}
