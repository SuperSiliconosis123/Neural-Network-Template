/* 
 *                                        A General Template for a Neural Network using the Genetic Algorithm
 * 
 * Settings:
 *   NODE-SIZE:
 *     1 = unsigned char
 *     2 = unsigned int
 *     3 = unsigned long long int
 *   LAYERS:
 *     The number of layers of nodes between the input and output layers, aka the hidden layers, non-inclusive.
 *   INPUT-NODES:
 *     The number of nodes in the input layer.
 *   MIDDLE-NODES:
 *     The number of nodes in each of the middle/hidden layers.
 *   OUTPUT-NODES:
 *     The number of nodes in the output layer.
 *
 */
#include <iostream>
#include <string>
using namespace std;


//general program settings
#define NODE-SIZE 2
#define LAYERS 3

#define INPUT-NODES 10
#define MIDDLE-NODES 30
#define OUTPUT-NODES 10


//implement the settings
#if NODE-SIZE == 1
struct {
  unsigned char input [INPUT-NODES];
  unsigned char middle [LAYERS] [MIDDLE-NODES];
  unsigned char output [OUTPUT-NODES];
} nodes;
#elif NODE-SIZE == 2
struct {
  unsigned int input [INPUT-NODES];
  unsigned int middle [LAYERS] [MIDDLE-NODES];
  unsigned int output [OUTPUT-NODES];
} nodes;
#elif NODE-SIZE == 2
struct {
  unsigned long long int input [INPUT-NODES];
  unsigned long long int middle [LAYERS] [MIDDLE-NODES];
  unsigned long long int output [OUTPUT-NODES];
} nodes;
#else
#error NODE-SIZE out of range
#endif


//
