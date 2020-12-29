#include <QtWidgets/QApplication>
#include <command/attachCommands/AttachConveyorManagerCommand.h>


#include "gui/FiltersScene.h"
#include "gui/FiltersView.h"
#include "gui/FiltersWindow.h"
#include "command/createCommands/CreateConveyorCommand.h"
#include "gui/cards/ConveyorManagerCard.h"
#include "Filters.h"


int main(int argc, char *argv[]) {
    auto filters = std::make_shared<Filters>();
    QApplication app(argc, argv);


    auto *window = new FiltersWindow;
    window->setFilters(filters);

    auto cmd = make_shared<AttachConveyorManagerCommand>(filters->getConveyorManager(), std::shared_ptr<FiltersWindow>(window));
    filters->executeCommand(cmd);

    window->setWindowTitle("Filters");

    window->resize(800, 600);



    window->show();

    return app.exec();


}