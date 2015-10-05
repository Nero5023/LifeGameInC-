//
//  LGContext.cpp
//  NoBoundsLifeGame
//
//  Created by Nero Zuo on 15/9/18.
//  Copyright (c) 2015年 Nero. All rights reserved.
//

#include "LGContext.h"
#include <sstream>

LGContext::LGContext() {
  
}

LGContext::LGContext(vector<string> aliveElements) {
  for (int i = 0; i < aliveElements.size(); i++) {
    aliveElementsDic[aliveElements[i]] = true;
  }
}

void LGContext::nextGeneration() {
  map<string,int> neighborCountDic;
  map<string,bool>nextAliveDic;
  map<string,bool>::iterator pos = aliveElementsDic.begin();
  for (; pos != aliveElementsDic.end(); pos++) {
    string str = pos->first;
    int i = 0;
    for (i = 0; i < str.length(); i++) {
      char ch = str[i];
      if ( ch == ',') {
        break;
      }
    }
    string strx = str.substr(0,i);
    string stry = str.substr(i+1,str.length() - (i+1));
    stringstream ss;
    stringstream ss1;
    int x;
    int y;
    ss << strx;
    ss >> x;
    ss.clear();
    ss << stry;
    ss >> y;
    
    string str1;
    string str2;
    string str3;
    string str4;
    string str5;
    string str6;
    string str7;
    string str8;
    ss.clear();
    ss << x-1 << "," << y-1;
    ss >> str1;
    ss.clear();
    ss << x-1 << "," << y;
    ss >> str2;
    ss.clear();
    ss << x-1 << "," << y+1;
    ss >> str3;
    ss.clear();
    ss << x << "," << y-1;
    ss >> str4;
    ss.clear();
    ss << x << "," << y+1;
    ss >> str5;
    ss.clear();
    ss << x+1 << "," << y-1;
    ss >> str6;
    ss.clear();
    ss << x+1 << "," << y;
    ss >> str7;
    ss.clear();
    ss << x+1 << "," << y+1;
    ss >> str8;
    neighborCountDic[str1]++;
    neighborCountDic[str2]++;
    neighborCountDic[str3]++;
    neighborCountDic[str4]++;
    neighborCountDic[str5]++;
    neighborCountDic[str6]++;
    neighborCountDic[str7]++;
    neighborCountDic[str8]++;
  }
  map<string,int>::iterator countPos = neighborCountDic.begin();
  for (; countPos != neighborCountDic.end(); countPos++) {
    string element = countPos->first;
    if (aliveElementsDic[element]) {
      switch (countPos->second) {
        case 0:
        case 1:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
//          aliveElementsDic[element] = false;
          break;
        case 2:
        case 3:
          nextAliveDic[element] = true;
          break;
        default:
          cout << "neighborCount error" << endl;
          break;
      }
    }else {
      if (countPos->second == 3) {
        nextAliveDic[element] = true;
      }
//      else {
//        aliveElementsDic[element] = false;
//      }
    }
  }
  aliveElementsDic = nextAliveDic;
}

void LGContext::print() {
  map<string,bool>::iterator pos = aliveElementsDic.begin();
  for (; pos != aliveElementsDic.end(); pos++) {
    string element = pos->first;
    cout << "(" << element << ")";
  }
}
//void LGContext::print() {
//  map<LGElement,bool>::iterator pos = aliveElementsDic.begin();
//  for (; pos != aliveElementsDic.end(); pos++) {
//    LGElement element = pos->first;
//    if (pos->second) {
//      element.description();
//    }
//  }
//  cout << endl;
//}
