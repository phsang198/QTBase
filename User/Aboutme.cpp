#include "Expense.h"
#include "src/Control.h"
#include "src/object.h"
#include "src/objectManager.h"

// Function: Aboutme
// Description: [include some functions for About me's task in view( update password, update info )].
// 
//-------------------------------forget password------------------------------//
void Expense::on_change_pass_clicked()
{
    std::string username = ui.fusername->text().toStdString(); 
    std::string newpass = ui.newpass->text().toStdString(); 
    std::string confirm_newpass = ui.confirm_new_password->text().toStdString(); 
    if (username == "" || newpass == "" || confirm_newpass == "" )
    {
        QMessageBox::warning(this, "Error", "Empty input!");
        return;
    }
    if (newpass != confirm_newpass)
    {
        QMessageBox::warning(this, "Msg", "Password not match with confirm password!");
        return;
    }
    std::shared_ptr<object> obj = std::make_shared<user>(username, newpass, "", "");
    std::string msg; 
    Controller::update(obj,msg); 

    if (msg != "")
    {
        QMessageBox::warning(this, "Error", msg.c_str());
        return;
    }
    QMessageBox::information(this, "Msg", "Change password successfully!");
    login_view();
}
void Expense::fotget_passs_view()
{
    ui.tabwidget->setCurrentIndex(1);
    ui.fusername->setText("");
    ui.newpass->setText("");
    ui.confirm_new_password->setText("");
}
//-------------------------------update user------------------------------//
void Expense::on_update_clicked()
{
    std::string username = ui.username_up->text().toStdString();
    std::string fullname = ui.fullname_up->text().toStdString();
    if (fullname == "" )
    {
        QMessageBox::warning(this, "Error", "Empty input!");
        return;
    }
    std::shared_ptr<object> obj = std::make_shared<user>(username, "", fullname, "");
    std::string msg;
    Controller::update(obj, msg);

    if (msg != "")
    {
        QMessageBox::warning(this, "Error", msg.c_str());
        return;
    }
    QMessageBox::information(this, "Msg", "Update successfully!");
}
//-------------------------------logout------------------------------//
void Expense::on_logout_clicked()
{
    login_view(); 
    user tmp; 
    ObjectManager::_user = tmp; 
}
//-------------------------------show----------------------------------//
void Expense::About_me_view()
{
    ui.tabwidget->setCurrentIndex(3);
    ui.username_up->setText(ObjectManager::_user.username.c_str());
    ui.fullname_up->setText(ObjectManager::_user.fullname.c_str());
    if (ObjectManager::_user.position == "ADMIN")
        ui.role_up->setCurrentIndex(0);
    else if (ObjectManager::_user.position == "USER")
        ui.role_up->setCurrentIndex(3);
}