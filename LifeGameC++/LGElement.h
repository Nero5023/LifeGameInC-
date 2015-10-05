//
//  LGElement.h
//  LifeGameC++
//
//  Created by Nero Zuo on 15/9/18.
//  Copyright (c) 2015年 Nero. All rights reserved.
//

#ifndef __LifeGameC____LGElement__
#define __LifeGameC____LGElement__

#include <iostream>
using namespace std;

class LGElement {
private:
  int neighborCount;
  bool isAlive;
  bool nextIsAlive;
public:
  LGElement();
  int checkIsAlive();
  void updateNextIsAlive();
  void setNeighborCount(int count);
  void nextGeneration();
  void setNextIsAlive(bool lgNextIsAlive);
};

#endif /* defined(__LifeGameC____LGElement__) */
