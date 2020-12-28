//
// Created by noxin on 12/27/20.
//

#include "FiltersView.h"

void FiltersView::drawBackground(QPainter *painter, const QRectF &r) {
    QGraphicsView::drawBackground(painter, r);

    QBrush bBrush = backgroundBrush();

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

void FiltersView::contextMenuEvent(QContextMenuEvent *event) {
    if (itemAt(event->pos())) {
        QGraphicsView::contextMenuEvent(event);
        return;
    }

    QMenu modelMenu;

    auto skipText = QStringLiteral("skip me");

    //Add filterbox to the context menu
    auto *txtBox = new QLineEdit(&modelMenu);

    txtBox->setPlaceholderText(QStringLiteral("Filter"));
    txtBox->setClearButtonEnabled(true);

    auto *txtBoxAction = new QWidgetAction(&modelMenu);
    txtBoxAction->setDefaultWidget(txtBox);

    modelMenu.addAction(txtBoxAction);

    auto *listView = new QListWidget(&modelMenu);
    auto *listViewAction = new QWidgetAction(&modelMenu);
    listViewAction->setDefaultWidget(listView);
    modelMenu.addAction(listViewAction);

    listView->addItem("somestring");


    txtBox->setFocus();
    modelMenu.exec(event->globalPos());
}




