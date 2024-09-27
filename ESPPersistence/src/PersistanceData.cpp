#include "PersistanceData.hpp"
#include "DataValidator.hpp"
#include "EEPROMHandler.hpp"

PersistanceData::PersistanceData()
{
    mLogger = new Logger(className);
    EEPROMHandler::GetInstance().init(NVData);
    mLogger->log("Persisted data loaded: ");
    mLogger->log(std::string(reinterpret_cast<char const *>(&NVData)));
    if (DataValidator::validateData(NVData))
    {
        mLogger->log("Data valide");
    }
    else
    {
        mLogger->log("Data invalide restoring defaults");
        restoreDefaults();
        EEPROMHandler::GetInstance().Store(NVData);
    }
    mLogger->log("Hostname - " + std::string(NVData.WifiConf.hostname));
    mLogger->log("SSID - " + std::string(NVData.WifiConf.eSsid));
    mLogger->log("Password - " + std::string(NVData.WifiConf.ePass));
}

//------------------Setter functions----------------

void PersistanceData::storeSSID(const std::string newSSID)
{
    if (newSSID.size() >= 5 && strcmp(newSSID.c_str(), NVData.WifiConf.ePass) != 0)
    {
        m_ssid = newSSID;
        strncpy(NVData.WifiConf.eSsid, newSSID.c_str(), MAX_LENGTH_SSID);
        mLogger->log("Stored new ssid: ");
        mLogger->log(NVData.WifiConf.eSsid);
        EEPROMHandler::GetInstance().Store(NVData);
    }
}

void PersistanceData::storePassWd(const std::string newPassWd)
{
    if (newPassWd.size() >= 5 && strcmp(newPassWd.c_str(), NVData.WifiConf.eSsid) != 0)
    {
        m_password = newPassWd;
        strncpy(NVData.WifiConf.ePass, newPassWd.c_str(), MAX_LENGTH_PASSWD);
        mLogger->log("Stored new password: ");
        mLogger->log(NVData.WifiConf.ePass);
        EEPROMHandler::GetInstance().Store(NVData);
    }
}

void PersistanceData::setHostname(const std::string newHostname)
{
    if (newHostname.size() >= 5 && strcmp(newHostname.c_str(), NVData.WifiConf.hostname) != 0)
    {
        m_hostname = newHostname;
        strncpy(NVData.WifiConf.hostname, newHostname.c_str(), MAX_LENGTH_HNAME);
        EEPROMHandler::GetInstance().Store(NVData);
    }
}

void PersistanceData::setBrokerAddress(const std::string newBrokerAddress)
{
    if (newBrokerAddress.size() >= 5 && strcmp(newBrokerAddress.c_str(), NVData.WifiConf.hostname) != 0)
    {
        m_BrokerAddresse = newBrokerAddress;
        strncpy(NVData.mqttConf.mqttServer, newBrokerAddress.c_str(), MAX_LENGTH_HNAME);
        EEPROMHandler::GetInstance().Store(NVData);
    }
}

void PersistanceData::restoreDefaults()
{
    NVData.Header.NVDataSize = sizeof(NVData);
    setHostname(m_hostname);
    setBrokerAddress(m_BrokerAddresse);
    strncpy(NVData.WifiConf.ePass, "defaultPassWd", MAX_LENGTH_PASSWD);
    strncpy(NVData.WifiConf.eSsid, "defaultSSID", MAX_LENGTH_SSID);
    strncpy(NVData.Header.validation, VALID_STRING, MAX_VALIDATION_STRING);
    NVData.mqttConf.mqttPort = 1883;
}