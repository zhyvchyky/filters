//
// Created by noxin on 12/28/20.
//
#include <command/attachCommands/AttachConveyorManagerCommand.h>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabBar>

#include "FiltersWindow.h"
#include "command/createCommands/CreateConveyorCommand.h"
#include "command/attachCommands/AttachConveyorCommand.h"

using namespace std;

FiltersWindow::FiltersWindow(QWidget *parent) : QTabWidget(parent){
    this->setTabPosition(QTabWidget::North);
    this->setTabsClosable(true);
    this->setMovable(true);


    runButton = new QPushButton(this);
    addConveyorButton = new QPushButton(this);

    runButton->setParent(this);
    addConveyorButton->setParent(this);

    addConveyorButton->setFixedSize(50, 50);
    runButton->setFixedSize(50, 50);

    addConveyorButton->setStyleSheet("background-color: yellow");
    runButton->setStyleSheet("background-color: green");

    connect(runButton, &QPushButton::clicked, this, &FiltersWindow::handleRunButton);
    connect(addConveyorButton, &QPushButton::clicked, this, &FiltersWindow::handleAddButton);

    addConveyorButton->move(25, this->height()-75);
    runButton->move(this->width() - 75, this->height()-75);

}

void FiltersWindow::resizeEvent(QResizeEvent *event) {
    QTabWidget::resizeEvent(event);
    runButton->move(this->width()-75, this->height()-75);
    addConveyorButton->move(25, this->height()-75);
}

void FiltersWindow::handleRunButton() {
    std::cout << "Run pressed" << std::endl;
}

void FiltersWindow::handleAddButton() {
    auto cmd = make_shared<CreateConveyorCommand>(this->filters->getConveyorManager());
    this->filters->executeCommand(cmd);
    std::cout << "Conveyor added" << std::endl;
}

void FiltersWindow::notify(std::shared_ptr<ConveyorManager> manager) {

    std::set<size_t> added;
    std::set<size_t> removed;
    std::set<size_t> newConveyors;

    auto conveyorsVector = manager->getConveyors();
    for(size_t i = 0; i < conveyorsVector.size(); i++){
        if(conveyorsVector[i] != nullptr){
            newConveyors.insert(i);
        }
    }
    //may add optimization
    for(auto elem: this->conveyors){
        if(newConveyors.contains(elem))
            removed.insert(elem);
    }
    for(auto elem: newConveyors){
        if(conveyors.contains(elem))
            added.insert(elem);
    }
    conveyors = newConveyors;
}

void FiltersWindow::setFilters(std::shared_ptr<Filters> f) {
    filters = f;
}
