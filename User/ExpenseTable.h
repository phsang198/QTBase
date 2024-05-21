#pragma once
#ifndef EXPENSEMODEL_H
#define EXPENSEMODEL_H

#include <QAbstractTableModel>
#include <vector>
#include "src/object.h"

// Class: ExpenseModel
// Description: [To be used to show table ].
// 
class ExpenseModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    ExpenseModel(const std::vector<std::shared_ptr<expense>>& _expenses, QObject* parent = nullptr)
        : QAbstractTableModel(parent), expenses(_expenses) {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return expenses.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 7; 
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if (!index.isValid() || role != Qt::DisplayRole) {
            return QVariant();
        }

        const std::shared_ptr<expense>& expense = expenses[index.row()];
        switch (index.column()) {
        case 0: return QString::fromStdString(expense->date);
        case 1: return QString::fromStdString(expense->category);
        case 2: return QString::fromStdString(expense->subcategory);
        case 3: return expense->amount;
        case 4: return expense->balance;
        case 5: return expense->id;
        case 6: return expense->userID;
        default: return QVariant();
        }
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role != Qt::DisplayRole) {
            return QVariant();
        }

        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0: return QString("Date");
            case 1: return QString("Category");
            case 2: return QString("Subcategory");
            case 3: return QString("Amount");
            case 4: return QString("Balance");
            case 5: return QString("ID");
            case 6: return QString("User ID");
            default: return QVariant();
            }
        }
        return QVariant();
    }
    void clearData() {

        beginResetModel();
        expenses.clear();
        endResetModel();
    }

private:
    std::vector<std::shared_ptr<expense>> expenses;
};

#endif // EXPENSEMODEL_H
