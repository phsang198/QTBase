#include "Expense.h"
#include "src/Control.h"
#include "src/object.h"
#include "src/objectManager.h"

Expense::Expense(QWidget *parent)
    : QMainWindow(parent)
{
    ObjectManager::init(); 
    ui.setupUi(this);

    connect(ui.login, &QPushButton::clicked, this, &Expense::on_login_clicked);
    connect(ui.no_account_btn, &QPushButton::clicked, this, &Expense::on_no_account_clicked);
    connect(ui.forget_pass_btn, &QPushButton::clicked, this, &Expense::on_forget_pass_clicked);
    connect(ui.change, &QPushButton::clicked, this, &Expense::on_change_pass_clicked);

    connect(ui.about_me, &QPushButton::clicked, this, &Expense::on_about_me_clicked);

    connect(ui.update_btn, &QPushButton::clicked, this, &Expense::on_update_clicked);
    connect(ui.logout, &QPushButton::clicked, this, &Expense::on_logout_clicked);

    connect(ui.register_btn, &QPushButton::clicked, this, &Expense::on_register_clicked);
    

    connect(ui.about_me_ex, &QPushButton::clicked, this, &Expense::on_about_me_clicked);
}

Expense::~Expense()
{}

