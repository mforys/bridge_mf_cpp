//
//  HandSuitsPoints.hpp
//  Bridge_MF_Demo
//
//  Created by Marek Forys on 22.02.2019.
//

#ifndef HandSuitsPoints_h
#define HandSuitsPoints_h

#include <stdio.h>

#include "HandSuits.h"

class HandSuitsPoints : public HandSuits
{
public:
    HandSuitsPoints(UI clubs, UI diamonds, UI hearts, UI spades, UI points);
};

#endif /* HandSuitsPoints_h */
