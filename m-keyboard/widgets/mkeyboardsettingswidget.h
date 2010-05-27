/* * This file is part of m-keyboard *
 *
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 * Contact: Nokia Corporation (directui@nokia.com)
 *
 * If you have questions regarding the use of this file, please contact
 * Nokia at directui@nokia.com.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * and appearing in the file LICENSE.LGPL included in the packaging
 * of this file.
 */

#ifndef MKEYBOARDSETTINGSWIDGET_H
#define MKEYBOARDSETTINGSWIDGET_H

#include <QObject>
#include <MWidget>
#include "mkeyboardsettings.h"

class QGraphicsItem;
class QGraphicsLayoutItem;
class MContentItem;
class MButton;
class MLabel;
class MDialog;
class MList;
class QModelIndex;
class MGridLayoutPolicy;
class MLinearLayoutPolicy;

class MKeyboardSettingsWidget : public MWidget
{
    Q_OBJECT
public:
    MKeyboardSettingsWidget(MKeyboardSettings *, QGraphicsItem *parent = 0);
    virtual ~MKeyboardSettingsWidget();

protected:
    //! reimp
    virtual void retranslateUi();
    //! reimp_end

private slots:
    void showKeyboardList();
    void updateTitle();
    void updateKeyboardSelectionModel();
    void updateSelectedKeyboards(const QModelIndex &);
    void setErrorCorrectionState(bool toggled);
    void syncErrorCorrectionState();

private:
    void buildUi();
    void addItem(QGraphicsLayoutItem *item);
    void updateKeyboardModel();
    void notifyNoKeyboards();
    void connectSlots();

    MKeyboardSettings *settingsObject;
    MGridLayoutPolicy *landscapePolicy;
    MLinearLayoutPolicy *portraitPolicy;
    MButton *errorCorrectionSwitch;
    MLabel *errorCorrectionLabel;
    MDialog *keyboardDialog;
    MList *keyboardList;
    MContentItem *selectedKeyboardsItem;
};

#endif
