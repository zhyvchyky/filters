//
// Created by noxin on 12/28/20.
//

#include "FiltersWindow.h"

FiltersWindow::FiltersWindow(QWidget *parent) : QTabWidget(parent) {
    this->setTabPosition(QTabWidget::North);
    this->setTabsClosable(true);
}