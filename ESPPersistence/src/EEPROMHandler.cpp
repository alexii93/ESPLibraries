/**
 * @file: EEPROM.cpp
 *
 * @brief: This module provides the EEPROM functionality which is needed to store WLAN credentials for setup any device which cannot connect to the present Network
 *
 */

#include <Arduino.h>
#include <EEPROM.h>
#include "EEPROMHandler.hpp"

int cfgStart = 0;


class nvmDataObject {
    public:
        std::string key;
        int length;
        int offset;
    private:
}

std::list<nvmDataObject> nvmData;

int nextFreeOffset = 0;

public void addObjectToNVM(nvmDataObject dataObject) {
    EEPROM.begin(4095);
    EEPROM.writeBytes(cfgStart, nextFreeOffset, MAX_CONFIG_DATA_SIZE);
    nextFreeOffset += dataO
    delay(200);
    EEPROM.end();
}


std::Map<std::string,byte*> dataMap;

bool proofLength(char *str, int maxLen)
{
    size_t lenght = strlen(str);
    return (lenght < maxLen && lenght != 0);
}

bool setValidString(std::string *member, char *str, int maxLen)
{
    size_t lenght = strlen(str);
    bool successful = true;

    if (lenght < maxLen && lenght != 0)
    {
        *member = std::string(str);
    }
    else
    {
        successful = false;
    }
    return successful;
}

void EEPROMHandler::init(NVData_t &data)
{
    bool eepromUp2Date = true;

    // Read EEPROM
    EEPROM.begin(4095);
    EEPROM.get(0, data);
    EEPROM.end();

    if (false)
    {
        eraseData();
    }

    // if (strcmp(data.Header.validation, "valid") && data.Header.NVDataSize != sizeof(data))
    // {
    //     eepromUp2Date = false;
    //     eraseData();
    //     AssumeDefaults();
    // }

    // eepromUp2Date &= setValidString(&m_hostname, data.WifiConf.hostname, MAX_LENGTH_HNAME);
    // eepromUp2Date &= setValidString(&m_ssid, data.WifiConf.eSsid, MAX_LENGTH_SSID);
    // eepromUp2Date &= setValidString(&m_password, data.WifiConf.ePass, MAX_LENGTH_PASSWD);
    // eepromUp2Date &= setValidString(&m_BrokerAddresse, data.mqttConf.mqttServer, MAX_LENGTH_HNAME);
}

void EEPROMHandler::Store(NVData_t data)
{
    // Save configuration from RAM into EEPROM
    EEPROM.begin(4095);
    EEPROM.put(cfgStart, data);
    delay(200);
    EEPROM.end();
}

// EEPROM Funktionen
void EEPROMHandler::eraseData()
{
    // Reset EEPROM bytes to '0' for the length of the data structure
    EEPROM.begin(4095);
    EEPROM.writeBytes(cfgStart, 0, MAX_CONFIG_DATA_SIZE);
    delay(200);
    EEPROM.end();
}
