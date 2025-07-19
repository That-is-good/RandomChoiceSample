/********************************************************************************
** Form generated from reading UI file 'showresult.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWRESULT_H
#define UI_SHOWRESULT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ShowResult
{
public:
    QVBoxLayout *verticalLayout;
    QListView *ResultList;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ShowResult)
    {
        if (ShowResult->objectName().isEmpty())
            ShowResult->setObjectName("ShowResult");
        ShowResult->resize(576, 400);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("dialog-information")));
        ShowResult->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(ShowResult);
        verticalLayout->setObjectName("verticalLayout");
        ResultList = new QListView(ShowResult);
        ResultList->setObjectName("ResultList");

        verticalLayout->addWidget(ResultList);

        buttonBox = new QDialogButtonBox(ShowResult);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ShowResult);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ShowResult, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ShowResult, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ShowResult);
    } // setupUi

    void retranslateUi(QDialog *ShowResult)
    {
        ShowResult->setWindowTitle(QCoreApplication::translate("ShowResult", "\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowResult: public Ui_ShowResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWRESULT_H
