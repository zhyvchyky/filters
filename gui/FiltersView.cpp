//
// Created by noxin on 12/27/20.
//

#include <iostream>
#include <command/createCommands/CreateNodeCommand.h>
#include <command/createCommands/CreateConnectionCommand.h>
#include <command/setCommands/SetColorGeneratorCommand.h>
#include <command/setCommands/SetNodeOutputCommand.h>
#include <command/setCommands/SetGaussianNoiseCommand.h>
#include <command/setCommands/SetNodeInputCommand.h>
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

    auto *listWidget = new QListWidget(&modelMenu);
    auto *listViewAction = new QWidgetAction(&modelMenu);
    listViewAction->setDefaultWidget(listWidget);
    modelMenu.addAction(listViewAction);

    auto listItem = new QListWidgetItem();
    listItem->setData(Qt::UserRole, QVariant::fromValue(PredefinedConveyorType::NoiseConveyor));
    listItem->setText("Noise Conveyor");

    auto listItem2 = new QListWidgetItem();
    listItem2->setData(Qt::UserRole, QVariant::fromValue(PredefinedConveyorType::SecondConveyor));
    listItem2->setText("Second Conveyor");

    auto listItem3 = new QListWidgetItem();
    listItem3->setData(Qt::UserRole, QVariant::fromValue(PredefinedConveyorType::ThirdConveyor));
    listItem3->setText("Third Conveyor");


    listWidget->addItem(listItem);
    listWidget->addItem(listItem2);
    listWidget->addItem(listItem3);

    connect(listWidget, &QListWidget::itemClicked, [&](QListWidgetItem *item) {
        std::cout << item->text().toStdString() << " clicked " << conveyorId << std::endl;
        if (item->data(Qt::UserRole).value<PredefinedConveyorType>() == PredefinedConveyorType::NoiseConveyor) {
            auto nodeIn = std::make_shared<CreateNodeCommand>(this->_scene->getFilters()->getConveyorManager(),
                                                              _scene->getConveyorId(),
                                                              NodeType::ColorGeneratorNode);
            auto nodeEf = std::make_shared<CreateNodeCommand>(this->_scene->getFilters()->getConveyorManager(),
                                                              _scene->getConveyorId(),
                                                              NodeType::GaussianNoiseNode);
            auto nodeComb = std::make_shared<CreateNodeCommand>(this->_scene->getFilters()->getConveyorManager(),
                                                                _scene->getConveyorId(),
                                                                NodeType::CombineNode);

            auto con1 = std::make_shared<CreateConnectionCommand>(this->_scene->getFilters()->getConveyorManager(),
                                                                  _scene->getConveyorId(), 1, 3);
            auto con2 = std::make_shared<CreateConnectionCommand>(this->_scene->getFilters()->getConveyorManager(),
                                                                  _scene->getConveyorId(), 2, 3);
            auto con3 = std::make_shared<CreateConnectionCommand>(this->_scene->getFilters()->getConveyorManager(),
                                                                  _scene->getConveyorId(), 3, 0);

            auto set1 = std::make_shared<SetColorGeneratorCommand>(this->_scene->getFilters()->getConveyorManager(),
                                                                   _scene->getConveyorId(), 1, _scene->getConveyorId(),
                                                                   0,
                                                                   255,
                                                                   700, 500);
            auto set2 = std::make_shared<SetNodeOutputCommand>(this->_scene->getFilters()->getConveyorManager(),
                                                               _scene->getConveyorId(), "anon1.ppm");
            auto set3 = std::make_shared<SetGaussianNoiseCommand>(this->_scene->getFilters()->getConveyorManager(),
                                                                  _scene->getConveyorId(), 2, 10000, 500, 700);

            this->_scene->getFilters()->executeCommand(nodeIn);
            this->_scene->getFilters()->executeCommand(nodeEf);
            this->_scene->getFilters()->executeCommand(nodeComb);
            this->_scene->getFilters()->executeCommand(con1);
            this->_scene->getFilters()->executeCommand(con2);
            this->_scene->getFilters()->executeCommand(con3);
            this->_scene->getFilters()->executeCommand(set1);
            this->_scene->getFilters()->executeCommand(set2);
            this->_scene->getFilters()->executeCommand(set3);
        } else if (item->data(Qt::UserRole).value<PredefinedConveyorType>() == PredefinedConveyorType::SecondConveyor) {

            auto nodeIn = std::make_shared<CreateNodeCommand>(this->_scene->getFilters()->getConveyorManager(), _scene->getConveyorId(), NodeType::NodeInput);
            auto nodeEf = std::make_shared<CreateNodeCommand>(this->_scene->getFilters()->getConveyorManager(), _scene->getConveyorId(),
                                                              NodeType::BlackAndWhiteNode);
            auto nodeNS = std::make_shared<CreateNodeCommand>(this->_scene->getFilters()->getConveyorManager(), _scene->getConveyorId(),
                                                              NodeType::GaussianNoiseNode);
            auto nodeComb = std::make_shared<CreateNodeCommand>(this->_scene->getFilters()->getConveyorManager(), _scene->getConveyorId(),
                                                                NodeType::CombineNode);

            auto con1 = std::make_shared<CreateConnectionCommand>(this->_scene->getFilters()->getConveyorManager(), _scene->getConveyorId(), 1, 2);
            auto con2 = std::make_shared<CreateConnectionCommand>(this->_scene->getFilters()->getConveyorManager(), _scene->getConveyorId(), 2, 4);
            auto con3 = std::make_shared<CreateConnectionCommand>(this->_scene->getFilters()->getConveyorManager(), _scene->getConveyorId(), 3, 4);
            auto con4 = std::make_shared<CreateConnectionCommand>(this->_scene->getFilters()->getConveyorManager(), _scene->getConveyorId(), 4, 0);


            auto set1 = std::make_shared<SetGaussianNoiseCommand>(this->_scene->getFilters()->getConveyorManager(), _scene->getConveyorId(), 3, 1000, 467, 551);
            auto set2 = std::make_shared<SetNodeOutputCommand>(this->_scene->getFilters()->getConveyorManager(), _scene->getConveyorId(), "anon1.ppm");
            auto set3 = std::make_shared<SetNodeInputCommand>(this->_scene->getFilters()->getConveyorManager(), _scene->getConveyorId(), 1, "cherniy.ppm");

            this->_scene->getFilters()->executeCommand(nodeIn);
            this->_scene->getFilters()->executeCommand(nodeEf);
            this->_scene->getFilters()->executeCommand(nodeNS);
            this->_scene->getFilters()->executeCommand(nodeComb);
            this->_scene->getFilters()->executeCommand(con1);
            this->_scene->getFilters()->executeCommand(con2);
            this->_scene->getFilters()->executeCommand(con3);
            this->_scene->getFilters()->executeCommand(con4);
            this->_scene->getFilters()->executeCommand(set1);
            this->_scene->getFilters()->executeCommand(set2);
            this->_scene->getFilters()->executeCommand(set3);
        }
        modelMenu.close();
    });


    modelMenu.exec(event->globalPos());
}

