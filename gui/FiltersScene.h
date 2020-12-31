//
// Created by noxin on 12/27/20.
//

#ifndef FILTERS_FILTERSSCENE_H
#define FILTERS_FILTERSSCENE_H

#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <Filters.h>

class FiltersScene : public QGraphicsScene, public IConveyorObserver{
    Q_OBJECT

public:
    FiltersScene(size_t conveyorId, std::shared_ptr<Filters> filters, QObject *parent = Q_NULLPTR);
    size_t getConveyorId();
    std::shared_ptr<Filters> getFilters();
    void notify(std::shared_ptr<Conveyor>) override;
    void processNotify(std::shared_ptr<Conveyor>) override;
    //~FiltersScene();
private:
    std::shared_ptr<Filters> filters;
    size_t conveyorId;
};


#endif //FILTERS_FILTERSSCENE_H
