/*
 * QMCMultiIntegrator.h
 *
 *  Created on: 28.05.2014
 *      Author: BlueCrescent
 */

#ifndef QMCMULTIINTEGRATOR_H_
#define QMCMULTIINTEGRATOR_H_

#include "MultiVariateIntegrator.h"

class QMCMultiIntegrator: public MultiVariateIntegrator {
public:
  NodesAndWeights getNodesAndWeights(int l, int d) const;
};

#endif /* QMCMULTIINTEGRATOR_H_ */
