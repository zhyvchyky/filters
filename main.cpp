#include <QtWidgets/QApplication>
#include <command/attachCommands/AttachConveyorManagerCommand.h>
//
//
#include "gui/FiltersScene.h"
#include "gui/FiltersView.h"
#include "gui/FiltersWindow.h"
#include "command/createCommands/CreateConveyorCommand.h"
#include "gui/cards/ConveyorManagerCard.h"
#include "Filters.h"
//#include <command/setCommands/SetNodeInputCommand.h>
//#include "Filters.h"
//#include "command/createCommands/CreateConveyorCommand.h"
//#include "command/createCommands/CreateNodeCommand.h"
//#include "command/createCommands/CreateConnectionCommand.h"
//#include "command/setCommands/SetColorGeneratorCommand.h"
//#include "command/setCommands/SetNodeOutputCommand.h"
//#include "command/setCommands/SetGaussianNoiseCommand.h"
//#include "command/ProcessCommand.h"

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

//    auto filters = std::make_shared<Filters>();
//    auto createConv = std::make_shared<CreateConveyorCommand>(filters->getConveyorManager());
//    auto nodeIn = std::make_shared<CreateNodeCommand>(filters->getConveyorManager(), 0, NodeType::NodeInput);
//    auto nodeEf = std::make_shared<CreateNodeCommand>(filters->getConveyorManager(), 0, NodeType::BlackAndWhiteNode);
//    auto nodeNS = std::make_shared<CreateNodeCommand>(filters->getConveyorManager(), 0, NodeType::GaussianNoiseNode);
//    auto nodeComb = std::make_shared<CreateNodeCommand>(filters->getConveyorManager(), 0, NodeType::CombineNode);
//
//    auto con1 = std::make_shared<CreateConnectionCommand>(filters->getConveyorManager(), 0, 1, 2);
//    auto con2 = std::make_shared<CreateConnectionCommand>(filters->getConveyorManager(), 0, 2, 4);
//    auto con3 = std::make_shared<CreateConnectionCommand>(filters->getConveyorManager(), 0, 3, 4);
//    auto con4 = std::make_shared<CreateConnectionCommand>(filters->getConveyorManager(), 0, 4, 0);
//
//
//    auto set1 = std::make_shared<SetGaussianNoiseCommand>(filters->getConveyorManager(), 0, 3, 1000, 500, 500);
//    auto set2 = std::make_shared<SetNodeOutputCommand>(filters->getConveyorManager(), 0, "anon1.ppm");
//    auto set3 = std::make_shared<SetNodeInputCommand>(filters->getConveyorManager(), 0, 1, "girl.ppm");
//
//    auto pro = std::make_shared<ProcessCommand>(filters->getConveyorManager(), 0);
//
//    filters->executeCommand(createConv);
//    filters->executeCommand(nodeIn);
//    filters->executeCommand(nodeEf);
//    filters->executeCommand(nodeNS);
//    filters->executeCommand(nodeComb);
//    filters->executeCommand(con1);
//    filters->executeCommand(con2);
//    filters->executeCommand(con3);
//    filters->executeCommand(con4);
//    filters->executeCommand(set1);
//    filters->executeCommand(set2);
//    filters->executeCommand(set3);
//    filters->executeCommand(pro);


}