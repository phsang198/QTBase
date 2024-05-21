#include "Expense.h"
#include "src/Control.h"
#include "src/object.h"
#include "src/objectManager.h"
#include "ExpenseTable.h"
#include "ExpenseChart.h"
#include "src/StringProcess.h"

// Function: Manager
// Description: [include some functions for expense manager's task in view].
// 
//-------------------------------expense------------------------------//
void Expense::on_about_me_clicked()
{
    About_me_view();
}
void Expense::Manager_view()
{
    ui.tabwidget->setCurrentIndex(5);
}