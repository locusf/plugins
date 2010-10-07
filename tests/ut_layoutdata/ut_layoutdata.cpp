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

#include "ut_layoutdata.h"
#include "mvirtualkeyboardstyle.h"
#include "layoutdata.h"
#include "vkbdatakey.h"
#include "utils.h"

#include <MApplication>
#include <MTheme>


void Ut_LayoutData::initTestCase()
{
    static int argc = 2;
    static char *app_name[2] = { (char *) "ut_layoutdata",
                                 (char *) "-local-theme" };

    disableQtPlugins();
    app = new MApplication(argc, app_name);

    style = new MVirtualKeyboardStyleContainer;
    style->initialize("MVirtualKeyboard", "MVirtualKeyboardView", 0);
}

void Ut_LayoutData::cleanupTestCase()
{
    delete style;
    style = 0;
    delete app;
    app = 0;
}

void Ut_LayoutData::init()
{
}

void Ut_LayoutData::cleanup()
{
}

void Ut_LayoutData::testConstructFromString()
{
    const QString characters("salmon");
    const LayoutSection section(characters, false, style);

    QCOMPARE(section.maxColumns(), characters.length());
    QCOMPARE(section.rowCount(), 1);
    QCOMPARE(section.keyCount(), characters.length());
    QCOMPARE(section.columnsAt(0), characters.length());
    QCOMPARE(section.maxNormalizedWidth(), static_cast<qreal>(characters.length()));
    for (int i = 0; i < characters.length(); ++i) {
        const VKBDataKey * const key(section.vkbKey(0, i));
        QVERIFY(key);
        QCOMPARE(key->style(), VKBDataKey::NormalStyle);
        QCOMPARE(key->width(), VKBDataKey::Medium);
        QVERIFY(key->isFixedWidth());
        QCOMPARE(key->rtl(), false);
        QCOMPARE(key->binding(false)->label(), QString(characters[i]));
        QCOMPARE(key->binding(true)->label(), QString(characters[i]));
        QCOMPARE(key->binding(false)->secondaryLabel(), QString());
        QVERIFY(!key->binding(false)->isDead());
        QCOMPARE(key->binding(false)->extendedLabels(), QString());
        QCOMPARE(key->binding(false)->action(), KeyBinding::ActionInsert);
    }
}


QTEST_APPLESS_MAIN(Ut_LayoutData);
