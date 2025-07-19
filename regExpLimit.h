#pragma once

#include <QStyledItemDelegate>
#include <QRegularExpressionValidator>
#include <qlineedit.h>

class RegexValidatorDelegate : public QStyledItemDelegate {
public:
    RegexValidatorDelegate(const QString& pattern, QObject* parent = nullptr)
        : QStyledItemDelegate(parent), regex(pattern) {
    }

    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,
        const QModelIndex& index) const override {
        QLineEdit* editor = new QLineEdit(parent);
        QRegularExpressionValidator* validator = new QRegularExpressionValidator(regex, editor);
        editor->setValidator(validator);
        return editor;
    }

private:
    QRegularExpression regex;
};
