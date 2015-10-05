//
//  LGContext.cpp
//  LifeGameC++
//
//  Created by Nero Zuo on 15/9/18.
//  Copyright (c) 2015年 Nero. All rights reserved.
//

#include "LGContext.h"
LGContext:: LGContext() {
  rows = 10;
  columns = 10;
  for (int i = 0; i < rows + 1; i ++) {
    vector<LGElement> elementsInOneRow;
    for (int j = 0 ; j < columns + 1; j ++) {
      LGElement element = LGElement();
      elementsInOneRow.push_back(element);
    }
    elements.push_back(elementsInOneRow);
  }
}

LGContext::LGContext(int newColumns, int newRows) {
  rows = newRows;
  columns = newColumns;
  for (int i = 0; i < rows + 1; i ++) {
    vector<LGElement> elementsInOneRow;
    for (int j = 0 ; j < columns + 1; j ++) {
      LGElement element = LGElement();
      elementsInOneRow.push_back(element);
    }
    elements.push_back(elementsInOneRow);
  }
}

void LGContext::setElementIsAliveInRowAndColumn(int row, int column, bool isAlive) {
  if (row >= 0 && row <= rows && column >= 0 && column <= columns ) {
    elements[row][column].setNextIsAlive(isAlive);
  }else {
    cout << "error: coordinate out of bounds" << endl;
  }
}

void LGContext::updateIsAliveFormNextIsAlive() {
  for (int row = 1 ; row < rows ; row++) {
    for (int column = 1; column < columns; column++) {
      elements[row][column].nextGeneration();
    }
  }
}

void LGContext::configureNextGeneration() {
  updateIsAliveFormNextIsAlive();
  for (int row = 1 ; row < rows ; row++) {
    for (int column = 1; column < columns; column++) {
      int neighbors = elements[row - 1][column - 1].checkIsAlive() + elements[row - 1][column].checkIsAlive() + elements[row - 1][column + 1].checkIsAlive() + elements[row][column - 1].checkIsAlive() + elements[row][column + 1].checkIsAlive() + elements[row + 1][column - 1].checkIsAlive() + elements[row + 1][column].checkIsAlive() + elements[row + 1][column + 1].checkIsAlive();
      elements[row][column].setNeighborCount(neighbors);
      elements[row][column].updateNextIsAlive();
       cout << elements[row][column].checkIsAlive() <<" ";
    }
    cout << endl;
  }
  cout << endl;
}

