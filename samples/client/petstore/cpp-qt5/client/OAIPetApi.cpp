/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * OpenAPI spec version: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#include "OAIPetApi.h"
#include "OAIHelpers.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace OpenAPI {

OAIPetApi::OAIPetApi() {

}

OAIPetApi::~OAIPetApi() {

}

OAIPetApi::OAIPetApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
OAIPetApi::addPet(const OAIPet& body) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/pet");
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "POST");

    
    QString output = body.asJson();
    input.request_body.append(output);
    

    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIPetApi::addPetCallback);

    worker->execute(&input);
}

void
OAIPetApi::addPetCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit addPetSignal();
        emit addPetSignalFull(worker);
    } else {
        emit addPetSignalE(error_type, error_str);
        emit addPetSignalEFull(worker, error_type, error_str);
    }
}

void
OAIPetApi::deletePet(const qint64& pet_id, const QString& api_key) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/pet/{petId}");
    QString pet_idPathParam("{"); 
    pet_idPathParam.append("petId").append("}");
    fullPath.replace(pet_idPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(pet_id)));
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "DELETE");

    if (api_key != nullptr) {
        input.headers.insert("api_key", "api_key");
    }

    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIPetApi::deletePetCallback);

    worker->execute(&input);
}

void
OAIPetApi::deletePetCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit deletePetSignal();
        emit deletePetSignalFull(worker);
    } else {
        emit deletePetSignalE(error_type, error_str);
        emit deletePetSignalEFull(worker, error_type, error_str);
    }
}

void
OAIPetApi::findPetsByStatus(const QList<QString>& status) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/pet/findByStatus");
    
    if (status.size() > 0) {
      if (QString("csv").indexOf("multi") == 0) {
        foreach(QString t, status) {
          if (fullPath.indexOf("?") > 0)
            fullPath.append("&");
          else
            fullPath.append("?");
          fullPath.append("status=").append(::OpenAPI::toStringValue(t));
        }
      }
      else if (QString("csv").indexOf("ssv") == 0) {
        if (fullPath.indexOf("?") > 0)
          fullPath.append("&");
        else
          fullPath.append("?");
        fullPath.append("status=");
        qint32 count = 0;
        foreach(QString t, status) {
          if (count > 0) {
            fullPath.append(" ");
          }
          fullPath.append(::OpenAPI::toStringValue(t));
        }
      }
      else if (QString("csv").indexOf("tsv") == 0) {
        if (fullPath.indexOf("?") > 0)
          fullPath.append("&");
        else
          fullPath.append("?");
        fullPath.append("status=");
        qint32 count = 0;
        foreach(QString t, status) {
          if (count > 0) {
            fullPath.append("\t");
          }
          fullPath.append(::OpenAPI::toStringValue(t));
        }
      }
    }
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "GET");


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIPetApi::findPetsByStatusCallback);

    worker->execute(&input);
}

void
OAIPetApi::findPetsByStatusCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    QList<OAIPet> output;
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();
    foreach(QJsonValue obj, jsonArray) {
        OAIPet val;
        ::OpenAPI::fromJsonValue(val, obj);
        output.append(val);
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit findPetsByStatusSignal(output);
        emit findPetsByStatusSignalFull(worker, output);
    } else {
        emit findPetsByStatusSignalE(output, error_type, error_str);
        emit findPetsByStatusSignalEFull(worker, error_type, error_str);
    }
}

void
OAIPetApi::findPetsByTags(const QList<QString>& tags) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/pet/findByTags");
    
    if (tags.size() > 0) {
      if (QString("csv").indexOf("multi") == 0) {
        foreach(QString t, tags) {
          if (fullPath.indexOf("?") > 0)
            fullPath.append("&");
          else
            fullPath.append("?");
          fullPath.append("tags=").append(::OpenAPI::toStringValue(t));
        }
      }
      else if (QString("csv").indexOf("ssv") == 0) {
        if (fullPath.indexOf("?") > 0)
          fullPath.append("&");
        else
          fullPath.append("?");
        fullPath.append("tags=");
        qint32 count = 0;
        foreach(QString t, tags) {
          if (count > 0) {
            fullPath.append(" ");
          }
          fullPath.append(::OpenAPI::toStringValue(t));
        }
      }
      else if (QString("csv").indexOf("tsv") == 0) {
        if (fullPath.indexOf("?") > 0)
          fullPath.append("&");
        else
          fullPath.append("?");
        fullPath.append("tags=");
        qint32 count = 0;
        foreach(QString t, tags) {
          if (count > 0) {
            fullPath.append("\t");
          }
          fullPath.append(::OpenAPI::toStringValue(t));
        }
      }
    }
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "GET");


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIPetApi::findPetsByTagsCallback);

    worker->execute(&input);
}

void
OAIPetApi::findPetsByTagsCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    QList<OAIPet> output;
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();
    foreach(QJsonValue obj, jsonArray) {
        OAIPet val;
        ::OpenAPI::fromJsonValue(val, obj);
        output.append(val);
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit findPetsByTagsSignal(output);
        emit findPetsByTagsSignalFull(worker, output);
    } else {
        emit findPetsByTagsSignalE(output, error_type, error_str);
        emit findPetsByTagsSignalEFull(worker, error_type, error_str);
    }
}

void
OAIPetApi::getPetById(const qint64& pet_id) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/pet/{petId}");
    QString pet_idPathParam("{"); 
    pet_idPathParam.append("petId").append("}");
    fullPath.replace(pet_idPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(pet_id)));
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "GET");


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIPetApi::getPetByIdCallback);

    worker->execute(&input);
}

void
OAIPetApi::getPetByIdCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    OAIPet output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit getPetByIdSignal(output);
        emit getPetByIdSignalFull(worker, output);
    } else {
        emit getPetByIdSignalE(output, error_type, error_str);
        emit getPetByIdSignalEFull(worker, error_type, error_str);
    }
}

void
OAIPetApi::updatePet(const OAIPet& body) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/pet");
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "PUT");

    
    QString output = body.asJson();
    input.request_body.append(output);
    

    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIPetApi::updatePetCallback);

    worker->execute(&input);
}

void
OAIPetApi::updatePetCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit updatePetSignal();
        emit updatePetSignalFull(worker);
    } else {
        emit updatePetSignalE(error_type, error_str);
        emit updatePetSignalEFull(worker, error_type, error_str);
    }
}

void
OAIPetApi::updatePetWithForm(const qint64& pet_id, const QString& name, const QString& status) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/pet/{petId}");
    QString pet_idPathParam("{"); 
    pet_idPathParam.append("petId").append("}");
    fullPath.replace(pet_idPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(pet_id)));
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "POST");
    if (name != nullptr) {
        input.add_var("name", name);
    }
        if (status != nullptr) {
        input.add_var("status", status);
    }
    

    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIPetApi::updatePetWithFormCallback);

    worker->execute(&input);
}

void
OAIPetApi::updatePetWithFormCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit updatePetWithFormSignal();
        emit updatePetWithFormSignalFull(worker);
    } else {
        emit updatePetWithFormSignalE(error_type, error_str);
        emit updatePetWithFormSignalEFull(worker, error_type, error_str);
    }
}

void
OAIPetApi::uploadFile(const qint64& pet_id, const QString& additional_metadata, const OAIHttpRequestInputFileElement*& file) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/pet/{petId}/uploadImage");
    QString pet_idPathParam("{"); 
    pet_idPathParam.append("petId").append("}");
    fullPath.replace(pet_idPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(pet_id)));
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "POST");
    if (additional_metadata != nullptr) {
        input.add_var("additionalMetadata", additional_metadata);
    }
        if (file != nullptr) {
        input.add_file("file", (*file).local_filename, (*file).request_filename, (*file).mime_type);
    }
    

    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIPetApi::uploadFileCallback);

    worker->execute(&input);
}

void
OAIPetApi::uploadFileCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    OAIApiResponse output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit uploadFileSignal(output);
        emit uploadFileSignalFull(worker, output);
    } else {
        emit uploadFileSignalE(output, error_type, error_str);
        emit uploadFileSignalEFull(worker, error_type, error_str);
    }
}


}
