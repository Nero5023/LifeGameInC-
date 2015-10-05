//
//  LGContext.h
//  LifeGameC++
//
//  Created by Nero Zuo on 15/9/18.
//  Copyright (c) 2015年 Nero. All rights reserved.
//

#ifndef __LifeGameC____LGContext__
#define __LifeGameC____LGContext__

#include <iostream>
#include "LGElement.h"
#include <vector>
using namespace std;

class LGContext {
private:
  vector<vector<LGElement>> elements;
  int columns;
  int rows;

public:
  LGContext();
  LGContext(int newColumns, int newRows);
  void setElementIsAliveInRowAndColumn(int row, int column, bool isAlive);
  void updateIsAliveFormNextIsAlive();
  void configureNextGeneration();
};



#endif /* defined(__LifeGameC____LGContext__) */
