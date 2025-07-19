/********************************************************************************
** Form generated from reading UI file 'randomchoice.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANDOMCHOICE_H
#define UI_RANDOMCHOICE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RandomChoice
{
public:
    QAction *action;
    QAction *action_4;
    QAction *action_5;
    QAction *helpUse;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton;
    QFormLayout *formLayout;
    QLabel *label_2;
    QSpinBox *spinBox;
    QCheckBox *repeated;
    QCheckBox *animation;
    QTableView *personlist;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RandomChoice)
    {
        if (RandomChoice->objectName().isEmpty())
            RandomChoice->setObjectName("RandomChoice");
        RandomChoice->resize(800, 452);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("media-playlist-shuffle")));
        RandomChoice->setWindowIcon(icon);
        action = new QAction(RandomChoice);
        action->setObjectName("action");
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("document-open")));
        action->setIcon(icon1);
        action_4 = new QAction(RandomChoice);
        action_4->setObjectName("action_4");
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("application-exit")));
        action_4->setIcon(icon2);
        action_5 = new QAction(RandomChoice);
        action_5->setObjectName("action_5");
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("font-x-generic")));
        action_5->setIcon(icon3);
        helpUse = new QAction(RandomChoice);
        helpUse->setObjectName("helpUse");
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("help-contents")));
        helpUse->setIcon(icon4);
        helpUse->setMenuRole(QAction::MenuRole::NoRole);
        action_2 = new QAction(RandomChoice);
        action_2->setObjectName("action_2");
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("applications-system")));
        action_2->setIcon(icon5);
        action_3 = new QAction(RandomChoice);
        action_3->setObjectName("action_3");
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::CallStart));
        action_3->setIcon(icon6);
        centralwidget = new QWidget(RandomChoice);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        QIcon icon7(QIcon::fromTheme(QString::fromUtf8("edit-copy")));
        pushButton_2->setIcon(icon7);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        QIcon icon8(QIcon::fromTheme(QString::fromUtf8("media-seek-forward")));
        pushButton_3->setIcon(icon8);

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        QIcon icon9(QIcon::fromTheme(QString::fromUtf8("edit-delete")));
        pushButton_4->setIcon(icon9);

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        QIcon icon10(QIcon::fromTheme(QString::fromUtf8("edit-clear")));
        pushButton_5->setIcon(icon10);

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setIcon(icon);

        verticalLayout->addWidget(pushButton_6);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QIcon icon11(QIcon::fromTheme(QString::fromUtf8("media-playback-start")));
        pushButton->setIcon(icon11);

        verticalLayout->addWidget(pushButton);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_2);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMinimum(1);
        spinBox->setMaximum(65536);
        spinBox->setValue(1);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, spinBox);

        repeated = new QCheckBox(centralwidget);
        repeated->setObjectName("repeated");
        sizePolicy.setHeightForWidth(repeated->sizePolicy().hasHeightForWidth());
        repeated->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, repeated);

        animation = new QCheckBox(centralwidget);
        animation->setObjectName("animation");
        sizePolicy.setHeightForWidth(animation->sizePolicy().hasHeightForWidth());
        animation->setSizePolicy(sizePolicy);
        animation->setChecked(true);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, animation);


        verticalLayout->addLayout(formLayout);


        horizontalLayout->addLayout(verticalLayout);

        personlist = new QTableView(centralwidget);
        personlist->setObjectName("personlist");

        horizontalLayout->addWidget(personlist);

        RandomChoice->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RandomChoice);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 33));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_2->setTearOffEnabled(false);
        RandomChoice->setMenuBar(menubar);
        statusbar = new QStatusBar(RandomChoice);
        statusbar->setObjectName("statusbar");
        RandomChoice->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action);
        menu->addSeparator();
        menu->addAction(action_4);
        menu_2->addAction(action_3);
        menu_2->addAction(action_2);
        menu_2->addAction(action_5);
        menu_2->addSeparator();
        menu_2->addAction(helpUse);

        retranslateUi(RandomChoice);

        QMetaObject::connectSlotsByName(RandomChoice);
    } // setupUi

    void retranslateUi(QMainWindow *RandomChoice)
    {
        RandomChoice->setWindowTitle(QCoreApplication::translate("RandomChoice", "RandomChoice", nullptr));
        action->setText(QCoreApplication::translate("RandomChoice", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(shortcut)
        action->setShortcut(QCoreApplication::translate("RandomChoice", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_4->setText(QCoreApplication::translate("RandomChoice", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(shortcut)
        action_4->setShortcut(QCoreApplication::translate("RandomChoice", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        action_5->setText(QCoreApplication::translate("RandomChoice", "\345\255\227\344\275\223", nullptr));
#if QT_CONFIG(shortcut)
        action_5->setShortcut(QCoreApplication::translate("RandomChoice", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        helpUse->setText(QCoreApplication::translate("RandomChoice", "\345\270\256\345\212\251", nullptr));
#if QT_CONFIG(shortcut)
        helpUse->setShortcut(QCoreApplication::translate("RandomChoice", "Ctrl+Shift+H", nullptr));
#endif // QT_CONFIG(shortcut)
        action_2->setText(QCoreApplication::translate("RandomChoice", "\350\257\246\347\273\206", nullptr));
#if QT_CONFIG(shortcut)
        action_2->setShortcut(QCoreApplication::translate("RandomChoice", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_3->setText(QCoreApplication::translate("RandomChoice", "\346\202\254\346\265\256\347\252\227", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RandomChoice", "\350\277\275\345\212\240", nullptr));
        pushButton_3->setText(QCoreApplication::translate("RandomChoice", "\346\217\222\345\205\245", nullptr));
        pushButton_4->setText(QCoreApplication::translate("RandomChoice", "\345\210\240\351\231\244", nullptr));
        pushButton_5->setText(QCoreApplication::translate("RandomChoice", "\346\270\205\347\251\272", nullptr));
        pushButton_6->setText(QCoreApplication::translate("RandomChoice", "\351\207\215\346\216\222", nullptr));
        pushButton->setText(QCoreApplication::translate("RandomChoice", "\347\224\237\346\210\220", nullptr));
        label_2->setText(QCoreApplication::translate("RandomChoice", "\344\270\252\346\225\260", nullptr));
        repeated->setText(QCoreApplication::translate("RandomChoice", "\351\207\215\345\244\215", nullptr));
        animation->setText(QCoreApplication::translate("RandomChoice", "\345\212\250\347\224\273", nullptr));
        menu->setTitle(QCoreApplication::translate("RandomChoice", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("RandomChoice", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RandomChoice: public Ui_RandomChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMCHOICE_H
