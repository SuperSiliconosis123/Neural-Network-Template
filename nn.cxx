/* 
 *                                        A General Template for a Neural Network using the Genetic Algorithm
 * 
 * Settings:
 *   NODE_SIZE:
 *     1 = unsigned char
 *     2 = unsigned int
 *     3 = unsigned long long int
 *   LAYERS:
 *     The number of layers of nodes between the input and output layers, aka the hidden layers, non-inclusive.
 *   INPUT_NODES:
 *     The number of nodes in the input layer.
 *   MIDDLE_NODES:
 *     The number of nodes in each of the middle/hidden layers.
 *   OUTPUT_NODES:
 *     The number of nodes in the output layer.
 *
 */
#include <iostream>
#include <string>
using namespace std;


//general program settings
#define NODE_SIZE 2
#define LAYERS 3

#define INPUT_NODES 10
#define MIDDLE_NODES 30
#define OUTPUT_NODES 10


//implement the settings
#if NODE_SIZE == 1
struct {
  unsigned char input [INPUT_NODES];
  unsigned char middle [LAYERS] [MIDDLE_NODES];
  unsigned char output [OUTPUT_NODES];
} nodes;
#elif NODE_SIZE == 2
struct {
  unsigned int input [INPUT_NODES];
  unsigned int middle [LAYERS] [MIDDLE_NODES];
  unsigned int output [OUTPUT_NODES];
} nodes;
#elif NODE_SIZE == 2
struct {
  unsigned long long int input [INPUT_NODES];
  unsigned long long int middle [LAYERS] [MIDDLE_NODES];
  unsigned long long int output [OUTPUT_NODES];
} nodes;
#else
#error "NODE_SIZE out of range"
#endif

