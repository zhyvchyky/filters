//
// Created by noxin on 12/28/20.
//

#ifndef FILTERS_FILTERSWINDOW_H
#define FILTERS_FILTERSWINDOW_H

#include <QTabWidget>
#include <QtWidgets/QPushButton>
#include <Filters.h>
#include <gui/cards/ConveyorManagerCard.h>
#include "FiltersScene.h"
#include "FiltersView.h"

class FiltersWindow : public QTabWidget, public IObserver<ConveyorManager>{
Q_OBJECT
public:
    FiltersWindow(QWidget *parent = nullptr);

    void resizeEvent(QResizeEvent *) override;

    void notify(std::shared_ptr<ConveyorManager>) override;

    void setFilters(std::shared_ptr<Filters>);

private slots:

    void handleRunButton();
    void handleCloseRequest(int);
    void handleAddButton();

private:
    std::map<size_t, size_t> tabIndexToConveyorIndex;
    std::map<size_t, size_t> conveyorIndexToTabIndex;
    std::map<size_t, std::shared_ptr<FiltersScene>> scenes;
    std::map<size_t, FiltersView*> sceneViews;
    std::shared_ptr<Filters> filters;
    std::set<size_t> conveyors;
    QPushButton *runButton;
    QPushButton *addConveyorButton;
};


#endif //FILTERS_FILTERSWINDOW_H