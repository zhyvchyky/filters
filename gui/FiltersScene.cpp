//
// Created by noxin on 12/27/20.
//

#include "FiltersScene.h"
#include <iostream>


FiltersScene::FiltersScene(size_t conveyorId, std::shared_ptr<Filters> filters, QObject *parent) : QGraphicsScene(parent) {
    this->conveyorId = conveyorId;
    this->filters = filters;
}
size_t FiltersScene::getConveyorId(){
    return this->conveyorId;
}

std::shared_ptr<Filters> FiltersScene::getFilters() {
    return this->filters;
}

void FiltersScene::processNotify(std::shared_ptr<Conveyor> conveyor) {
    std::cout << "ProcessNotify" << std::endl;
    auto result = conveyor->getNodes()[0]->getOutputPtr();
    //QImage image(std::max(result->getWidth(), result->getHeight()),std::max(result->getWidth(), result->getHeight()), QImage::Format_RGB16);
    QImage image(result->getWidth(), result->getHeight(), QImage::Format_RGB16);

    for(int i = 0; i < image.height(); i++){
        for(int j = 0; j < image.width(); j++){
            QColor color = QColor(result->getPixel(i, j).red, result->getPixel(i, j).green, result->getPixel(i, j).blue);
            image.setPixel(QPoint(j, i), color.rgb());
        }
    }


    auto scene = new QGraphicsScene(this);
    scene->addPixmap(QPixmap::fromImage(image));
    scene->setSceneRect(image.rect());
    auto sceneView = new QGraphicsView(scene);
    sceneView->show();
}

void FiltersScene::notify(std::shared_ptr<Conveyor>) {
    return;
}
