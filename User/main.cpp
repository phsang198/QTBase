#include "Expense.h"
#include "src/StringProcess.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Expense w;
    std::string path = StringProcess::getExePath() + "Res/images/favicon.ico"; 
    w.setWindowIcon(QIcon(path.c_str()));
    w.show();
    return a.exec();
}
