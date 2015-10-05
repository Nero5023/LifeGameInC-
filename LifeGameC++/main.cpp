//
//  main.cpp
//  LifeGameC++
//
//  Created by Nero Zuo on 15/9/18.
//  Copyright (c) 2015年 Nero. All rights reserved.
//

#include <iostream>
#include "LGContext.h"
using namespace std;

int main(int argc, const char * argv[]) {
//  cout << "Please input rows and columns" << endl;
  int rows = 20;
  int columns = 20;
////  scanf("%d %d", &rows, &columns);
////  cin >> rows >> columns;
  LGContext context = LGContext(rows, columns);
  int row = 1;
  cout << "Please input element 'space' represent dead, '*' represent alive, '0' represent end of input" << endl;
  while (row <= rows) {
    char str[256];
    cin.getline(str, 256);   //cin.getline(str,256,'0')  //'0'为终止符
    for (int i = 0; i < strlen(str); i++) {
      if (str[i] == '*') {
        context.setElementIsAliveInRowAndColumn(row, (i+1), true);
      }else if (str[i] == '0') {
        row = rows + 1;
      }
    }
    row ++;
  }
  context.configureNextGeneration();
  while (1) {
    cout << "if continue?(y/n)" << endl;
    char ifContinue;
    cin >> ifContinue;
    if (ifContinue == 'y') {
      context.configureNextGeneration();
    }else {
      break;
    }
  }
  
  
  return 0;
}




