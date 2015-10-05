//
//  LGContext.h
//  NoBoundsLifeGame
//
//  Created by Nero Zuo on 15/9/18.
//  Copyright (c) 2015年 Nero. All rights reserved.
//

#ifndef __NoBoundsLifeGame__LGContext__
#define __NoBoundsLifeGame__LGContext__

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class LGContext {
private:
  map<string,bool> aliveElementsDic;
public:
  LGContext();
  LGContext(vector<string>);
  void nextGeneration();
  void print();
};

#endif /* defined(__NoBoundsLifeGame__LGContext__) */
