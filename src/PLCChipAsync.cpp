#include "PLCChipAsync.hpp"

using namespace std;


PLCChipAsync::PLCChipAsync(uint_fast8_t inputs, uint_fast8_t outputs) : PLCChip(inputs, outputs) {  }
void PLCChipAsync::handleApply() { this->apply(); }