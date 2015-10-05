//
//  LGElement.cpp
//  LifeGameC++
//
//  Created by Nero Zuo on 15/9/18.
//  Copyright (c) 2015年 Nero. All rights reserved.
//

#include "LGElement.h"
LGElement::LGElement() {
  isAlive = false;
  nextIsAlive = false;
  neighborCount = 0;
}

int LGElement::checkIsAlive() {
  return isAlive ? 1 : 0;
}

void LGElement::updateNextIsAlive() {
  if (isAlive) {
    switch (neighborCount) {
      case 0:
      case 1:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
        nextIsAlive = false;
        break;
      case 2:
      case 3:
        nextIsAlive = true;
        break;
      default:
        cout << "neighborCount error" << endl;
        break;
    }
  }else {
    if (neighborCount == 3) {
      nextIsAlive = true;
    }else if (neighborCount <= 8 && neighborCount>=0) {
      nextIsAlive = false;
    }else {
      cout << "neighborCount error" << endl;
    }
  }
}

void LGElement::nextGeneration() {
  isAlive = nextIsAlive;
}


void LGElement::setNeighborCount(int count) {
  if (count >= 0 && count <= 8) {
    neighborCount = count;
  }else {
    cout << "neighborCount error" << endl;
  }
}

void LGElement::setNextIsAlive(bool lgNextIsAlive) {
  nextIsAlive = lgNextIsAlive;
}