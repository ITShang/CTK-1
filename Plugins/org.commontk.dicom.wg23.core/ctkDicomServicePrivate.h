/*=============================================================================

  Library: CTK

  Copyright (c) 2010 German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/

#ifndef CTKDICOMSERVICEPRIVATE_H
#define CTKDICOMSERVICEPRIVATE_H

#include <ctkDicomWG23Types.h>

#include <QEventLoop>
#include <QtSoapHttpTransport>
#include <org_commontk_dicom_wg23_core_Export.h>

class org_commontk_dicom_wg23_core_EXPORT ctkDicomServicePrivate : public QObject
{
  Q_OBJECT

public:
  ctkDicomServicePrivate(int port, QString path);

  const QtSoapType & askHost(const QString& methodName, QtSoapType* soapStruct);
    
  QEventLoop blockingLoop;
  QtSoapHttpTransport http;

  int port;
  QString path;

private slots:

  void responseReady();
};

#endif // CTKDICOMSERVICEPRIVATE_H
