#include "QApplicationGlobal.h"

std::vector<Shift*> QApplicationGlobal::Shifts;
std::vector<User*> QApplicationGlobal::Users;
Controller* QApplicationGlobal::CmdController;

QApplicationGlobal::QApplicationGlobal(int &argc, char **argv) : QApplication(argc, argv){ }
