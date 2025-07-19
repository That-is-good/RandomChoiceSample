/********************************************************************************
** Form generated from reading UI file 'settingmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGMENU_H
#define UI_SETTINGMENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingMenu
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QFormLayout *formLayout;
    QLabel *label;
    QSlider *animationTime;
    QLabel *label_2;
    QSlider *animationCnt;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rand;
    QRadioButton *seed;
    QSpinBox *EnterSeed;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingMenu)
    {
        if (SettingMenu->objectName().isEmpty())
            SettingMenu->setObjectName("SettingMenu");
        SettingMenu->resize(400, 300);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("applications-system")));
        SettingMenu->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(SettingMenu);
        verticalLayout->setObjectName("verticalLayout");
        label_3 = new QLabel(SettingMenu);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(SettingMenu);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        animationTime = new QSlider(SettingMenu);
        animationTime->setObjectName("animationTime");
        sizePolicy.setHeightForWidth(animationTime->sizePolicy().hasHeightForWidth());
        animationTime->setSizePolicy(sizePolicy);
        animationTime->setMinimum(8);
        animationTime->setMaximum(256);
        animationTime->setSingleStep(2);
        animationTime->setPageStep(16);
        animationTime->setValue(64);
        animationTime->setOrientation(Qt::Orientation::Horizontal);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, animationTime);

        label_2 = new QLabel(SettingMenu);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        animationCnt = new QSlider(SettingMenu);
        animationCnt->setObjectName("animationCnt");
        sizePolicy.setHeightForWidth(animationCnt->sizePolicy().hasHeightForWidth());
        animationCnt->setSizePolicy(sizePolicy);
        animationCnt->setMinimum(8);
        animationCnt->setMaximum(256);
        animationCnt->setSingleStep(2);
        animationCnt->setPageStep(16);
        animationCnt->setValue(32);
        animationCnt->setOrientation(Qt::Orientation::Horizontal);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, animationCnt);


        verticalLayout->addLayout(formLayout);

        label_4 = new QLabel(SettingMenu);
        label_4->setObjectName("label_4");
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        rand = new QRadioButton(SettingMenu);
        rand->setObjectName("rand");
        rand->setChecked(true);

        verticalLayout_2->addWidget(rand);

        seed = new QRadioButton(SettingMenu);
        seed->setObjectName("seed");

        verticalLayout_2->addWidget(seed);

        EnterSeed = new QSpinBox(SettingMenu);
        EnterSeed->setObjectName("EnterSeed");
        EnterSeed->setMinimum(0);
        EnterSeed->setMaximum(2148174);
        EnterSeed->setSingleStep(2);
        EnterSeed->setValue(0);

        verticalLayout_2->addWidget(EnterSeed);


        verticalLayout->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(SettingMenu);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SettingMenu);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SettingMenu, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SettingMenu, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SettingMenu);
    } // setupUi

    void retranslateUi(QDialog *SettingMenu)
    {
        SettingMenu->setWindowTitle(QCoreApplication::translate("SettingMenu", "\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("SettingMenu", "\345\212\250\347\224\273", nullptr));
        label->setText(QCoreApplication::translate("SettingMenu", "\345\212\250\347\224\273\346\227\266\351\227\264", nullptr));
        label_2->setText(QCoreApplication::translate("SettingMenu", "\345\212\250\347\224\273\346\254\241\346\225\260", nullptr));
        label_4->setText(QCoreApplication::translate("SettingMenu", "\351\232\217\346\234\272", nullptr));
        rand->setText(QCoreApplication::translate("SettingMenu", "\351\232\217\346\234\272\350\256\276\345\244\207\345\274\225\346\223\216", nullptr));
        seed->setText(QCoreApplication::translate("SettingMenu", "\347\247\215\345\255\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingMenu: public Ui_SettingMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGMENU_H
