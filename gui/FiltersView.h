//
// Created by noxin on 12/27/20.
//

#ifndef FILTERS_FILTERSVIEW_H
#define FILTERS_FILTERSVIEW_H

#include <cmath>
#include <QtWidgets/QGraphicsView>
#include "gui/FiltersScene.h"

class FiltersView : public QGraphicsView{
    Q_OBJECT
public:
    FiltersView(QWidget *parent = Q_NULLPTR);

    FiltersView(FiltersScene *scene, QWidget *parent = Q_NULLPTR);
    void setScene(FiltersScene *scene);

protected:
    void drawBackground(QPainter* painter, const QRectF& r) override;
    void showEvent(QShowEvent *event) override;

    FiltersScene* _scene;
};


#endif //FILTERS_FILTERSVIEW_H
