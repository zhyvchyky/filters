//
// Created by noxin on 12/28/20.
//
#include <command/attachCommands/AttachConveyorManagerCommand.h>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabBar>
#include <command/deleteCommands/DeleteConveyorCommand.h>
#include <command/ProcessCommand.h>
#include <QWindow>

#include "FiltersWindow.h"
#include "command/createCommands/CreateConveyorCommand.h"
#include "command/attachCommands/AttachConveyorCommand.h"

using namespace std;

FiltersWindow::FiltersWindow(QWidget *parent) : QTabWidget(parent){
    this->setTabPosition(QTabWidget::North);
    this->setTabsClosable(true);
    //this->setMovable(true);


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
    connect(this, &QTabWidget::tabCloseRequested, this, &FiltersWindow::handleCloseRequest);

    addConveyorButton->move(25, this->height()-75);
    runButton->move(this->width() - 75, this->height()-75);

}

void FiltersWindow::handleCloseRequest(int index){
    cout << "Close " << index << endl;
    auto cmd = make_shared<DeleteConveyorCommand>(this->filters->getConveyorManager() ,this->tabIndexToConveyorIndex[index]);
    filters->executeCommand(cmd);

}

void FiltersWindow::resizeEvent(QResizeEvent *event) {
    QTabWidget::resizeEvent(event);
    runButton->move(this->width()-75, this->height()-75);
    addConveyorButton->move(25, this->height()-75);
}

void FiltersWindow::handleRunButton() {
    std::cout << "Run pressed" << std::endl;
    this->scenes[tabIndexToConveyorIndex[this->currentIndex()]]->getFilters()->getConveyorManager();
    cout << "Break" << endl;
    auto cmd = make_shared<ProcessCommand>(filters->getConveyorManager(), tabIndexToConveyorIndex[this->currentIndex()]);
    filters->executeCommand(cmd);


}

void FiltersWindow::handleAddButton() {
    auto cmd = make_shared<CreateConveyorCommand>(this->filters->getConveyorManager());
    this->filters->executeCommand(cmd);
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
        if(!newConveyors.contains(elem))
            removed.insert(elem);
    }
    for(auto elem: newConveyors){
        if(!conveyors.contains(elem))
            added.insert(elem);
    }
    conveyors = newConveyors;

    for(auto elem: added){
        this->scenes[elem] = make_shared<FiltersScene>(elem, this->filters);

        auto cmd = make_shared<AttachConveyorCommand>(this->filters->getConveyorManager(), elem, shared_ptr<FiltersScene>(this->scenes[elem]));
        this->filters->executeCommand(cmd);

        this->scenes[elem]->getFilters()->getConveyorManager();

        this->sceneViews[elem] = new FiltersView(scenes[elem].get());
        this->sceneViews[elem]->conveyorId = elem;
        this->addTab(sceneViews[elem], QString::fromStdString("conv"+to_string(elem)));
    }
    for(auto elem: removed){
        this->scenes.erase(elem);
        this->sceneViews.erase(elem);
        this->removeTab(conveyorIndexToTabIndex[elem]);

        map<size_t, size_t> newTabIndexToConveyorIndex;
        map<size_t, size_t> newConveyorIndexToTabIndex;

        for(int i = conveyorIndexToTabIndex[elem]; i < tabIndexToConveyorIndex.size()-1; i++){
            tabIndexToConveyorIndex[i] = tabIndexToConveyorIndex[i+1];
        }
        tabIndexToConveyorIndex.erase(tabIndexToConveyorIndex.size() - 1);
        conveyorIndexToTabIndex.erase(elem);
        for(auto i = tabIndexToConveyorIndex.begin(); i != tabIndexToConveyorIndex.end(); i++){
            conveyorIndexToTabIndex[i->second] = i->first;
        }

    }
    for(auto elem: added){
        tabIndexToConveyorIndex[tabIndexToConveyorIndex.size()] = elem;
        conveyorIndexToTabIndex[elem] = tabIndexToConveyorIndex.size() - 1;
    }
}

void FiltersWindow::setFilters(std::shared_ptr<Filters> f) {
    filters = f;
}