/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

#ifndef __ctkFileDialogEventPlayer_h
#define __ctkFileDialogEventPlayer_h

// QtTesting includes
#include <pqNativeFileDialogEventPlayer.h>

// CTK includes
#include <ctkPimpl.h>
#include "ctkWidgetsExport.h"

/// Concrete implementation of pqWidgetEventPlayer that translates
/// high-level events into low-level Qt events.

class CTK_WIDGETS_EXPORT ctkFileDialogEventPlayer :
  public pqNativeFileDialogEventPlayer
{
  Q_OBJECT

public:
  typedef pqNativeFileDialogEventPlayer Superclass;
  ctkFileDialogEventPlayer(pqTestUtility* util, QObject* parent = 0);

  bool playEvent(QObject *Object, const QString &Command, const QString &Arguments, bool &Error);

private:
  ctkFileDialogEventPlayer(const ctkFileDialogEventPlayer&); // NOT implemented
  ctkFileDialogEventPlayer& operator=(const ctkFileDialogEventPlayer&); // NOT implemented

};

#endif