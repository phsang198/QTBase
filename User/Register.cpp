#include "Expense.h"
#include "src/Control.h"
#include "src/object.h"

// Function: Register
// Description: [include some functions for Register's task in view].
// 
//-------------------------------register------------------------------//
void Expense::regiter_clear()
{
    ui.username_re->setText("");
    ui.password_re->setText("");
    ui.confirm_password_re->setText("");
    ui.fullname_re->setText("");
    ui.role_re->setCurrentIndex(0);
}
void Expense::on_register_clicked()
{
    std::string username = ui.username_re->text().toStdString();
    std::string password = ui.password_re->text().toStdString();
    std::string confirm_password = ui.confirm_password_re->text().toStdString();
    
    std::string fullname = ui.fullname_re->text().toStdString();
    std::string position = ui.role_re->currentText().toStdString();

    if (username == "" || password == "" || confirm_password == "" || fullname == "")
    {
        QMessageBox::warning(this, "Error", "Empty input!");
        return;
    }

    if (password != confirm_password)
    {
        QMessageBox::warning(this, "Msg", "Password not match with confirm password!");
        return;
    }

    std::shared_ptr<object> obj = std::make_shared<user>(username, password, fullname, position);

    std::string msg = "";
    Controller::add(obj, msg);
    if (msg != "")
    {
        QMessageBox::warning(this, "Error", msg.c_str());
        return; 
    }
    QMessageBox::information(this, "Msg", "Add user successfully!");

    Controller::getUser(username, password, msg);

    regiter_clear();

    if (position == "ADMIN")
    {
        Admin_view();
    }
    else if (position == "USER")
    {
        Manager_view();
    }
}
void Expense::Register_view()
{
    ui.tabwidget->setCurrentIndex(2);
    regiter_clear();
}