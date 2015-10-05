//
//  main.cpp
//  NoBoundsLifeGame
//
//  Created by Nero Zuo on 15/9/18.
//  Copyright (c) 2015年 Nero. All rights reserved.
//

#include <iostream>
//#include <map>
//#include <string>
//#include <vector>
#include "LGContext.h"
using namespace std;
int main(int argc, const char * argv[]) {
  string str;
  vector<string> strs;
  while (cin >> str) {
    if (str == "0") {
      break;
    }
    strs.push_back(str);
  }
  LGContext context = LGContext(strs);
  context.print();
  cout << endl;  
  while (1) {
    cout << "if continue?(y/n)" << endl;
    char ifContinue;
    cin >> ifContinue;
    if (ifContinue == 'y') {
      context.nextGeneration();
      context.print();
      cout << endl;
    }else {
      break;
    }
  }
}
