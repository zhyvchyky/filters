//
// Created by noxin on 12/27/20.
//

#include "FiltersView.h"

void FiltersView::drawBackground(QPainter *painter, const QRectF &r) {
    QGraphicsView::drawBackground(painter, r);

    auto drawGrid =
            [&](double gridStep) {
                QRect windowRect = rect();
                QPointF tl = mapToScene(windowRect.topLeft());
                QPointF br = mapToScene(windowRect.bottomRight());

                double left = std::floor(tl.x() / gridStep - 0.5);
                double right = std::floor(br.x() / gridStep + 1.0);
                double bottom = std::floor(tl.y() / gridStep - 0.5);
                double top = std::floor(br.y() / gridStep + 1.0);

                // vertical lines
                for (int xi = int(left); xi <= int(right); ++xi) {
                    QLineF line(xi * gridStep, bottom * gridStep,
                                xi * gridStep, top * gridStep);

                    painter->drawLine(line);
                }

                // horizontal lines
                for (int yi = int(bottom); yi <= int(top); ++yi) {
                    QLineF line(left * gridStep, yi * gridStep,
                                right * gridStep, yi * gridStep);
                    painter->drawLine(line);
                }
            };

    QBrush bBrush = backgroundBrush();

    QPen pfine(QColor(60, 60, 60), 1.0);

    painter->setPen(pfine);
    drawGrid(15);

    QPen p(QColor(25, 25, 25), 1.0);

    painter->setPen(p);
    drawGrid(150);
}

FiltersView::FiltersView(FiltersScene *scene, QWidget *parent) : FiltersView(parent) {
    setScene(scene);
}

FiltersView::FiltersView(QWidget *parent) : QGraphicsView(parent) {
    setDragMode(QGraphicsView::ScrollHandDrag);
    setRenderHint(QPainter::Antialiasing);
    setBackgroundBrush(QColor(53, 53, 53));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    setCacheMode(QGraphicsView::CacheBackground);
}

void FiltersView::showEvent(QShowEvent *event) {
    _scene->setSceneRect(this->rect());
    QGraphicsView::showEvent(event);
}

void FiltersView::setScene(FiltersScene *scene) {
    _scene = scene;
    QGraphicsView::setScene(_scene);

}




