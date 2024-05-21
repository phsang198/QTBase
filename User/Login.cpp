#include "Expense.h"
#include "src/Control.h"
#include "src/object.h"
#include "src/objectManager.h"

// Function: Login
// Description: [include some functions for Login's task in view].
// 
//-------------------------------login------------------------------//
void Expense::on_login_clicked()
{
    std::string username = ui.username->text().toStdString();
    std::string password = ui.password->text().toStdString();
    if (username == "" || password == "")
    {
        QMessageBox::warning(this, "Error", "Empty input!");
        return;
    }
    std::string msg = "";
    Controller::getUser(username, password, msg);
    if (msg != "")
    {
        QMessageBox::warning(this, "Error", msg.c_str());
        return; 
    }
    if (ObjectManager::_user.position == "USER")
        Manager_view();
    else if (ObjectManager::_user.position == "ADMIN")
        Admin_view();
}
void Expense::on_no_account_clicked()
{
    Register_view();
}
void Expense::on_forget_pass_clicked()
{
    fotget_passs_view();
}
void Expense::login_view()
{
    ui.tabwidget->setCurrentIndex(0);
    ui.password->setText("");
}