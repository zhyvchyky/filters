#include <QtWidgets/QApplication>


#include "gui/FiltersScene.h"
#include "gui/FiltersView.h"
#include "gui/FiltersWindow.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FiltersScene scene;
    FiltersScene scene2;

    FiltersView view(&scene);
    FiltersView view2(&scene2);

    view.setWindowTitle("Node-based flow editor");
    //view.resize(800, 600);
    //view.show();

    FiltersWindow window;
    window.setWindowTitle("Filters");
    window.resize(800, 600);
    window.addTab(view.viewport(), QString("tab"));
    window.addTab(view2.viewport(), QString("tab2"));

    window.show();

    return app.exec();
}