#include <QtWidgets/QApplication>


#include <gui/FiltersScene.h>
#include "gui/FiltersView.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FiltersScene scene;

    FiltersView view(&scene);

    view.setWindowTitle("Node-based flow editor");
    view.resize(800, 600);
    view.show();

    return app.exec();
}