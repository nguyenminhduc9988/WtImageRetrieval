#include "Core/quantize/quantize.h"


cvflann::Index<cvflann::L2<double>> * Quantize::treeIndex;
cvflann::Matrix<double> Quantize::dataset;
